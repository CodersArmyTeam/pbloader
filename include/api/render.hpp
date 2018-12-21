//
// Created by devildefu on 02.12.2018.
//

#ifndef PBLOADER_RENDER_HPP
#define PBLOADER_RENDER_HPP

#include <string>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <engine/sprite/sprite.hpp>
#include <detours/detours.h>
#include <hooks/typedefs.hpp>

typedef std::vector<Sprite*> TVectorSprite;

namespace Render {
    void addSprite(Sprite* sprite);
    void popSprite();
    void clear();
    void render(MologieDetours::Detour<tUpdateTexture>* detour_UpdateTexture, SDL_Texture* texture);
}

#endif //PBLOADER_RENDER_HPP
