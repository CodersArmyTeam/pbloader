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

    int SDL_RenderPresent(SDL_Renderer *renderer);
    int SDL_RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
    int SDL_UpdateTexture(SDL_Texture* texture, const SDL_Rect* rect, const void* pixels, int pitch);
    void __thiscall location_is_changed(void* oh, unsigned int param_1);
}

#endif //PBLOADER_HOOK_HPP