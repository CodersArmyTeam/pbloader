/**
 *  typedefs.hpp by devildefu 2019
 */

#ifndef PBLOADER_TYPEDEFS_HPP
#define PBLOADER_TYPEDEFS_HPP

#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <ghidra.h>

typedef SDL_Window *(*tCreateWindow)(const char *, int, int, int, int, Uint32); /* Maybe remove it later */
typedef int (*tRenderPresent)(SDL_Renderer*);
typedef int (*tRenderCopy)(SDL_Renderer*, SDL_Texture*, const SDL_Rect*, const SDL_Rect*);

typedef int (*tUpperBlit)(SDL_Surface*, const SDL_Rect*, SDL_Surface*, SDL_Rect*);
typedef int (*tUpperBlitScaled)(SDL_Surface*, const SDL_Rect*, SDL_Surface*, SDL_Rect*);
typedef int (*tUpdateTexture)(SDL_Texture*, const SDL_Rect*, const void*, int);

typedef SDL_Surface* (*tIMGLoadRW)(SDL_RWops*, int);

typedef int (*tMixPlayMusic)(Mix_Music*, int);

typedef TTF_Font* (*tTTFOpenFontRW)(SDL_RWops*, int, int);

typedef SDL_RWops* (*tRWFromMem)(void*, int);

typedef void __thiscall (*tlocation_is_changed)(void*, unsigned int);

#endif //PBLOADER_TYPEDEFS_HPP
