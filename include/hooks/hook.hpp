//
// Created by devildefu on 01.12.2018.
//

#ifndef PBLOADER_HOOK_HPP
#define PBLOADER_HOOK_HPP

#include <detours/detours.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

typedef SDL_Window *(*tCreateWindow)(const char *, int, int, int, int, Uint32); /* Maybe remove it later */
typedef int (*tRenderPresent)(SDL_Renderer*);
typedef int (*tRenderCopy)(SDL_Renderer*, SDL_Texture*, const SDL_Rect*, const SDL_Rect*);

typedef int (*tUpperBlit)(SDL_Surface*, const SDL_Rect*, SDL_Surface*, SDL_Rect*);
typedef int (*tUpperBlitScaled)(SDL_Surface*, const SDL_Rect*, SDL_Surface*, SDL_Rect*);
typedef SDL_Texture* (*tCreateTextureFromSurface)(SDL_Renderer*, SDL_Surface*); /* Remove it later */
typedef int (*tUpdateTexture)(SDL_Texture*, const SDL_Rect*, const void*, int);

typedef SDL_Surface* (*tIMGLoadRW)(SDL_RWops*, int);

typedef int (*tMixPlayMusic)(Mix_Music*, int);

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
