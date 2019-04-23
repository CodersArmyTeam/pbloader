//
// Created by devildefu on 21.12.2018.
//

#ifndef PBLOADER_FONT_HPP
#define PBLOADER_FONT_HPP

#include <SDL2/SDL_ttf.h>
#include <string>

class Font {
private:
    TTF_Font* font;
    std::string path;
public:
    Font(const std::string& path);
    Font(const Font& other);
    ~Font();
};

#endif //PBLOADER_FONT_HPP
