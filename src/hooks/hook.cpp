//
// Created by devildefu on 01.12.2018.
//

#include <hooks/hook.hpp>
#include <global.hpp>
#include <api/render.hpp>
#include <engine/sprite/sprite.hpp>

MologieDetours::Detour<tCreateWindow> *detour_CreateWindow = NULL;
MologieDetours::Detour<tRenderPresent> *detour_RenderPresent = NULL;
MologieDetours::Detour<tUpperBlit> *detour_UpperBlit = NULL;
MologieDetours::Detour<tUpperBlitScaled> *detour_UpperBlitScaled = NULL;
MologieDetours::Detour<tRenderCopy> *detour_RenderCopy = NULL;

MologieDetours::Detour<tMixPlayMusic> *detour_MixPlayMusic = NULL;

//int dog = 0;

Sprite* sprite;

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

        sprite = new Sprite(Vector2f(0, 0), Vector2f(32, 32));
        //Render::addSprite(sprite);
    } catch(MologieDetours::DetourException& e) {
        return FALSE;
    }
}

void Hooks::Clear() {
    delete detour_CreateWindow;
    delete detour_RenderPresent;
    delete detour_UpperBlit;
    delete detour_UpperBlitScaled;
    delete detour_RenderCopy;

    delete detour_MixPlayMusic;

    delete sprite;
}


SDL_Window* Hooks::SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags) {
    SDL_Window* window = detour_CreateWindow->GetOriginalFunction()(title, x, y, w, h, flags);
    if(gWindow != NULL) {
        gWindow = window;
    }
    return window;
}

int Hooks::SDL_RenderPresent(SDL_Renderer *renderer) {
    //printf("[PBLoader][Hooks] SDL_RenderPresent\n");

    if(gRenderer != NULL) {
        gRenderer = renderer;
    }
    //Render::render(renderer);
    return detour_RenderPresent->GetOriginalFunction()(renderer);
}

int Hooks::SDL_UpperBlit(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect) {
    //printf("[PBLoader][Hooks] SDL_BlitSurface\n");
    /*
    std::string name = "GRAPH/" + std::to_string(dog) + ".bmp";
    SDL_SaveBMP(src, name.c_str());
    dog += 1;
    */
    return detour_UpperBlit->GetOriginalFunction()(src, srcrect, dst, dstrect);
}

int Hooks::SDL_UpperBlitScaled(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect) {
    printf("[PBLoader][Hooks] SDL_BlitScaled\n");
    return detour_UpperBlitScaled->GetOriginalFunction()(src, srcrect, dst, dstrect);
}

int Hooks::SDL_RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect) {
    //printf("[PBLoader][Hooks] SDL_RenderCopy\n");
    //dog = 0;
    return detour_RenderCopy->GetOriginalFunction()(renderer, texture, srcrect, dstrect);
}


int Hooks::Mix_PlayMusic(Mix_Music* music, int loops) {
    printf("[PBLoader][Hooks] Mix_PlayMusic");
    //Mix_Music* changed_music = NULL;
    //changed_music = Mix_LoadMUS("downpour.wav");
    return detour_MixPlayMusic->GetOriginalFunction()(music, loops);
    //return -1;
}