//
// Created by devildefu on 07.12.2018.
//

#include <engine/sprite/sprite.hpp>
//#include <global.hpp>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Sprite::~Sprite() {
    SDL_FreeSurface(texture);
    texture = NULL;
}

bool Sprite::loadTexture(const char *path) {
    SDL_Surface* surface = IMG_Load(path);
    if(!surface) {
        logError("SDL_Surface is NULL! Path not found, maybe file not exist?");
        return 1;
    }

    texture = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_ARGB8888, NULL);
    return 0;
}
