/**
 *  hook.hpp by devildefu 2019
 */

#ifndef PBLOADER_HOOK_HPP
#define PBLOADER_HOOK_HPP

#include <fstream>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include <api/render.hpp>
#include "typedefs.hpp"
#include <engine/gamemanager/gamemanager.hpp>

namespace Hooks {
    bool Init();
    void Clear();

    SDL_Window *SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags);
    int SDL_RenderPresent(SDL_Renderer *renderer);
    int SDL_RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);

    /* SDL_BlitSurface is just define, so we need to change these functions */
    int SDL_UpperBlit(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect);
    int SDL_UpperBlitScaled(SDL_Surface* src, const SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect);

    int SDL_UpdateTexture(SDL_Texture* texture, const SDL_Rect* rect, const void* pixels, int pitch);

    /* SDL_image */
    SDL_Surface* IMG_Load_RW(SDL_RWops* src, int freesrc);

    /* SDL_mixer */
    int Mix_PlayMusic(Mix_Music* music, int loops);

    /* SDL_ttf */
    TTF_Font* TTF_OpenFontRW(SDL_RWops* src, int freesrc, int ptsize);

    SDL_RWops* SDL_RWFromMem(void* mem, int size);

    void __thiscall location_is_changed(void* oh, unsigned int param_1);

    void __fastcall aha(void* dst, char* unused, char* name);
}

#endif //PBLOADER_HOOK_HPP