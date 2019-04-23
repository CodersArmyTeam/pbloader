//
// Created by DiD3n on 20.01.2019.
//

#include <engine/surface/surface.hpp>

#include <logger.hpp>

//TODO: fix all fucking errors
Surface::Surface(const std::string& path)
 : surface(nullptr) , path(path) {
    surface = IMG_Load(path.c_str());
    if (!surface) {
        logError("Surface::Surface(path) - IMG Error: \n",SDL_GetError());
    }
}

Surface::Surface(const Surface& other) {
    Surface::Surface(other.path);
}

Surface::~Surface() {
    if (surface)
        SDL_FreeSurface(this->surface);
}