//
// Created by devildefu on 07.12.2018.
//

#include <engine/sprite/sprite.hpp>
//#include <global.hpp>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
    texture = NULL;
}

bool Sprite::loadTexture(const char *path) {
    SDL_Surface* surface = IMG_Load(path);
    if(surface == NULL) {
        return 1;
    }

    //texture = SDL_CreateTextureFromSurface(gRenderer, surface);
    if(texture == NULL) {
        return 1;
    }
    SDL_FreeSurface(surface);
}
