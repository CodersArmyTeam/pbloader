/**
 *  hook.cpp by devildefu 2019
 */

/* TODO: Create HookManager */

#include <logger.hpp>
#include <hooks/hook.hpp>
#include <engine/sprite/sprite.hpp>

MologieDetours::Detour<tRenderPresent>* detour_RenderPresent = NULL;
MologieDetours::Detour<tRenderCopy>* detour_RenderCopy = NULL;
MologieDetours::Detour<tUpdateTexture>* detour_UpdateTexture = NULL;
MologieDetours::Detour<tlocation_is_changed>* detour_location_is_changed = NULL;

int dog = 0;

auto surfacemanager = GameManager::GetSurfaceManager();
auto mapmanager = GameManager::GetMapManager();

SDL_Texture* globalTexture = NULL;
SDL_Renderer* globalRenderer = NULL;

/**
 * 
 * Initializes all hooks
 * 
 */

bool Hooks::Init() {
    try {
        detour_RenderPresent = new MologieDetours::Detour<tRenderPresent>("SDL2.dll", "SDL_RenderPresent",
                                                                          Hooks::SDL_RenderPresent);

        detour_RenderCopy = new MologieDetours::Detour<tRenderCopy>("SDL2.dll", "SDL_RenderCopy", Hooks::SDL_RenderCopy);

        detour_UpdateTexture = new MologieDetours::Detour<tUpdateTexture>("SDL2.dll", "SDL_UpdateTexture", Hooks::SDL_UpdateTexture);

        detour_location_is_changed = new MologieDetours::Detour<tlocation_is_changed>((tlocation_is_changed)0x00403960, Hooks::location_is_changed);
    } catch(MologieDetours::DetourException& e) {
        logError("%s", e.what());
        return FALSE;
    }
}

/**
 *  
 * Removes hooks from memory
 *  
 */

void Hooks::Clear() {
    delete detour_RenderPresent;
    delete detour_RenderCopy;
    delete detour_UpdateTexture;
    delete detour_location_is_changed;
}

void Hooks::location_is_changed(void* oh, unsigned int param_1) {
    detour_location_is_changed->GetOriginalFunction()(oh, param_1);
    mapmanager->ModifyLocation();
    return;
}

int Hooks::SDL_RenderPresent(SDL_Renderer *renderer) {
    if(!globalRenderer) {
        globalRenderer = renderer;
    }
    return detour_RenderPresent->GetOriginalFunction()(renderer);
}

int Hooks::SDL_RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect) {
    GameManager::Render();
    return detour_RenderCopy->GetOriginalFunction()(renderer, texture, srcrect, dstrect);
}

int Hooks::SDL_UpdateTexture(SDL_Texture* texture, const SDL_Rect* rect, const void* pixels, int pitch) {
    //logInfo("[Hooks] SDL_UpdateTexture"); //if your app fuck up here put dog.png next to pb
    if(!globalTexture) {
        globalTexture = texture;
    }

    int returned_value = detour_UpdateTexture->GetOriginalFunction()(texture, rect, pixels, pitch);
    return returned_value;
}