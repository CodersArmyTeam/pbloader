//
// Created by devildefu on 02.12.2018.
//

#ifndef PBLOADER_SPRITE_HPP
#define PBLOADER_SPRITE_HPP

#include <engine/vector/vector.hpp>
#include <SDL2/SDL.h>

class Sprite {
private:
    Vector2f pos;
    Vector2f size;

    SDL_Surface* texture;
public:

    Sprite()
    : pos(0,0) {}
    Sprite(const Sprite& other) 
    : pos(other.pos), size(other.size) {};
    Sprite(const Vector2f& pos, const Vector2f& size) 
    : pos(pos), size(size) {};

    ~Sprite();

    // TODO: make definitions
    Sprite operator=(const Sprite& other);

    void draw();

    Vector2f getPosition() const                        {return pos;}
    Sprite& setPosition(const Vector2f& vec)            {pos = vec;return *this;}
    Sprite& setPosition(const float& x,const float& y)  {pos = Vector2f(x,y);return *this;}

    Vector2f getSize() const                            {return size;}
    Sprite& setSize(const Vector2f& vec)                {size = vec;return *this;}
    Sprite& setSize(const float& x,const float& y)      {size = Vector2f(x,y);return *this;}

    bool loadTexture(const char* path);
    //Sprite& setTexture(const Texture& texture);

    SDL_Surface* getTexture() { return texture; }
};

#endif //PBLOADER_SPRITE_HPP
