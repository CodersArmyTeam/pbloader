/**
 *  hook.cpp by devildefu 2019
 */

/* TODO: Create HookManager */

#include <logger.hpp>
#include <hooks/hook.hpp>
#include <engine/sprite/sprite.hpp>

MologieDetours::Detour<tCreateWindow>* detour_CreateWindow = NULL;
MologieDetours::Detour<tRenderPresent>* detour_RenderPresent = NULL;
MologieDetours::Detour<tUpperBlit>* detour_UpperBlit = NULL;
MologieDetours::Detour<tUpperBlitScaled>* detour_UpperBlitScaled = NULL;
MologieDetours::Detour<tRenderCopy>* detour_RenderCopy = NULL;
MologieDetours::Detour<tUpdateTexture>* detour_UpdateTexture = NULL;
MologieDetours::Detour<tRWFromMem>* detour_RWFromMem = NULL;

MologieDetours::Detour<tIMGLoadRW>* detour_IMGLoadRW = NULL;

MologieDetours::Detour<tMixPlayMusic>* detour_MixPlayMusic = NULL;

MologieDetours::Detour<tTTFOpenFontRW>* detour_OpenFontRW = NULL;

int dog = 0;

auto surfacemanager = GameManager::GetSurfaceManager();

/**
 * 
 * Initializes all hooks
 * 
 */

bool Hooks::Init() {
    try {
        detour_CreateWindow = new MologieDetours::Detour<tCreateWindow>("SDL2.dll", "SDL_CreateWindow",
                                                                        Hooks::SDL_CreateWindow);

        detour_RenderPresent = new MologieDetours::Detour<tRenderPresent>("SDL2.dll", "SDL_RenderPresent",
                                                                          Hooks::SDL_RenderPresent);

        detour_UpperBlit = new MologieDetours::Detour<tUpperBlit>("SDL2.dll", "SDL_UpperBlit",
                                                                        Hooks::SDL_UpperBlit);

        detour_UpperBlitScaled = new MologieDetours::Detour<tUpperBlitScaled>("SDL2.dll", "SDL_UpperBlitScaled",
                                                                      Hooks::SDL_UpperBlitScaled);

        detour_RenderCopy = new MologieDetours::Detour<tRenderCopy>("SDL2.dll", "SDL_RenderCopy", Hooks::SDL_RenderCopy);


        detour_MixPlayMusic = new MologieDetours::Detour<tMixPlayMusic>("SDL2_mixer.dll", "Mix_PlayMusic", Hooks::Mix_PlayMusic);

        detour_IMGLoadRW = new MologieDetours::Detour<tIMGLoadRW>("SDL2_image.dll", "IMG_Load_RW", Hooks::IMG_Load_RW);

        detour_UpdateTexture = new MologieDetours::Detour<tUpdateTexture>("SDL2.dll", "SDL_UpdateTexture", Hooks::SDL_UpdateTexture);
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
    delete detour_CreateWindow;
    delete detour_RenderPresent;
    delete detour_UpperBlit;
    delete detour_UpperBlitScaled;
    delete detour_RenderCopy;
    delete detour_IMGLoadRW;
    delete detour_MixPlayMusic;
    delete detour_UpdateTexture;
}

SDL_RWops* Hooks::SDL_RWFromMem(void* mem, int size) {
    logInfo("Hooks::SDL_RWFromMemory is used!");
    SDL_RWops* rw = detour_RWFromMem->GetOriginalFunction()(mem, size);
    return rw;
}

SDL_Window* Hooks::SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags) {
    SDL_Window* window = detour_CreateWindow->GetOriginalFunction()("Perypetie Piżmona", x, y, w, h, flags);
    return window;
}

int Hooks::SDL_RenderPresent(SDL_Renderer *renderer) {
    GameManager::Render();
    //logInfo("[SurfaceManager] Liczba tekstur: " + std::to_string(surfacemanager->Size()));
    return detour_RenderPresent->GetOriginalFunction()(renderer);
}

int Hooks::SDL_UpperBlit(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect) {
    //logInfo("[PBLoader][Hooks] SDL_BlitSurface");

    /*
    std::string name = "GRAPH/" + std::to_string(dog) + ".bmp";
    SDL_SaveBMP(dst, name.c_str());
    dog += 1;
     */
    return detour_UpperBlit->GetOriginalFunction()(src, srcrect, dst, dstrect);
}

int Hooks::SDL_UpperBlitScaled(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect) {
    //logInfo("[PBLoader][Hooks] SDL_BlitScaled");
    return detour_UpperBlitScaled->GetOriginalFunction()(src, srcrect, dst, dstrect);
}

int Hooks::SDL_RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect) {
    //logInfo("[Hooks] SDL_RenderCopy");
    //dog = 0;
    return detour_RenderCopy->GetOriginalFunction()(renderer, texture, srcrect, dstrect);
}

int Hooks::SDL_UpdateTexture(SDL_Texture* texture, const SDL_Rect* rect, const void* pixels, int pitch) {
    //logInfo("[Hooks] SDL_UpdateTexture"); //if your app fuck up here put dog.png next to pb
    int returned_value = detour_UpdateTexture->GetOriginalFunction()(texture, rect, pixels, pitch);
    Render::render(detour_UpdateTexture, texture);
    return returned_value;
}

SDL_Surface* Hooks::IMG_Load_RW(SDL_RWops* src, int freesrc) {
    SDL_Surface* original_surface = detour_IMGLoadRW->GetOriginalFunction()(src, freesrc);
    surfacemanager->Add(std::to_string(dog), original_surface);
    dog += 1;
    return original_surface;
}


int Hooks::Mix_PlayMusic(Mix_Music* music, int loops) {
    //logInfo("[Hooks] Mix_PlayMusic\n");
    Mix_Music* changed_music = NULL;
    changed_music = Mix_LoadMUS("downpour.wav");
    return detour_MixPlayMusic->GetOriginalFunction()(changed_music, loops);
    //return -1;
}


TTF_Font* Hooks::TTF_OpenFontRW(SDL_RWops* src, int freesrc, int ptsize) {
    TTF_Font* font = detour_OpenFontRW->GetOriginalFunction()(src, freesrc, ptsize);
    return font;
}

