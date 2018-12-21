//
// Created by devildefu on 01.12.2018.
//

#ifndef PBLOADER_HOOK_HPP
#define PBLOADER_HOOK_HPP

#include <detours/detours.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <api/render.hpp>

#include "typedefs.hpp"

namespace Hooks {
    bool Init();
    void Clear();

    SDL_Window *SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags);
    int SDL_RenderPresent(SDL_Renderer *renderer);
    int SDL_RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);

    /* SDL_BlitSurface is just define, so we need to change these functions */
    int SDL_UpperBlit(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect);
    int SDL_UpperBlitScaled(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect);

    SDL_Texture* SDL_CreateTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface);
    int SDL_UpdateTexture(SDL_Texture* texture, const SDL_Rect* rect, const void* pixels, int pitch);

    /* SDL_image */
    SDL_Surface* IMG_Load_RW(SDL_RWops* src, int freesrc);

    /* SDL_Mixer */
    int Mix_PlayMusic(Mix_Music* music, int loops);
}

#endif //PBLOADER_HOOK_HPP
