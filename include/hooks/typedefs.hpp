/**
 *  typedefs.hpp by devildefu 2019
 */

#ifndef PBLOADER_TYPEDEFS_HPP
#define PBLOADER_TYPEDEFS_HPP

#include <stdio.h>
#include <windows.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include <ghidra.h>

#include <detours/detours.h>

typedef int (*tRenderPresent)(SDL_Renderer*);
typedef int (*tRenderCopy)(SDL_Renderer*, SDL_Texture*, const SDL_Rect*, const SDL_Rect*);
typedef int (*tUpdateTexture)(SDL_Texture*, const SDL_Rect*, const void*, int);
typedef void __thiscall (*tlocation_is_changed)(void*, unsigned int);

using UpdateTextureHook = MologieDetours::Detour<tUpdateTexture>;

#endif //PBLOADER_TYPEDEFS_HPP
