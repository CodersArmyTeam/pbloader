//
// Created by devildefu on 21.12.2018.
//

#ifndef PBLOADER_TEXTURE_HPP
#define PBLOADER_TEXTURE_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include <engine/font/font.hpp>

class Surface {
private:
    SDL_Surface* surface;
    std::string path;
public:
    Surface(const std::string& path);
    Surface(const Surface& other);
    ~Surface();
};

#endif //PBLOADER_TEXTURE_HPP
