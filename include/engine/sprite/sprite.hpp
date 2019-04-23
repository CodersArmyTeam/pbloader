//
// Created by devildefu on 02.12.2018.
//

#ifndef PBLOADER_SPRITE_HPP
#define PBLOADER_SPRITE_HPP

#include <engine/vector/vector.hpp>
#include <SDL2/SDL.h>
#include <logger.hpp>

class Sprite {
private:
    Vector2f pos;
    Vector2f size;

    SDL_Surface* texture;
public:

    Sprite()
    : pos(0,0) {}

    /**
     *  Create sprite from other sprite
     */
    Sprite(const Sprite& other) 
    : pos(other.pos), size(other.size) {};

    /**
     *  Create sprite from pos and size
     */
    Sprite(const Vector2f& pos, const Vector2f& size) 
    : pos(pos), size(size) {};

    ~Sprite();

    // TODO: make definitions
    Sprite operator=(const Sprite& other);

    /**
     *  Draw sprite
     */
    void draw();

    /**
     *  Return sprite's position
     */
    Vector2f getPosition() const                        {return pos;}

    /**
     *  Set position from Vector2f
     */
    Sprite& setPosition(const Vector2f& vec)            {pos = vec;return *this;}

    /**
     *  Set position from x and y
     */
    Sprite& setPosition(const float& x,const float& y)  {pos = Vector2f(x,y);return *this;}

    /** 
     *  Return sprite's size 
     */
    Vector2f getSize() const                            {return size;}

    /**
     *  Set size from Vector2f
     */
    Sprite& setSize(const Vector2f& vec)                {size = vec;return *this;}
    
    /**
     *  Set size from x and y
     */
    Sprite& setSize(const float& x,const float& y)      {size = Vector2f(x,y);return *this;}

    /**
     *  Loads texture and changes actual sprite's texture
     *  \return True if texture was successfully loaded or false if not
     */
    bool loadTexture(const char* path);

    /**
     *  Return texture's
     */
    SDL_Surface* getTexture() { return texture; }
};

#endif //PBLOADER_SPRITE_HPP
