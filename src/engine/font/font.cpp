//
// Created by DiD3n on 20.01.2019.
//

#include <engine/font/font.hpp>

#include <logger.hpp>


Font::Font(const std::string& path)
 : font(nullptr) , path(path) {
    font = TTF_OpenFont(path.c_str(), 64); //TODO: custom DPI
    if (!font) {
        logError("Font::Font(path) - TTF Error: \n",SDL_GetError());
    }
}

Font::Font(const Font& other) {
    Font::Font(other.path);
}

Font::~Font() {
    if (font)
        TTF_CloseFont(this->font);
}