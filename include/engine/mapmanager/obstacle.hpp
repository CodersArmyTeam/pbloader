#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SDL2/SDL.h>

class Obstacle {
private:
    /** 
     *  If obstacle is custom, id must be -1 (may change) 
     */
    uint16_t id = -1;

    /** 
     *  It doesn't have to be set if obstacle is built into the game.
     */
    SDL_Surface* texture = NULL;
public:
    Obstacle() { }

    /**
     *  Create obstacle from other obstacle
     */
    Obstacle(Obstacle& obstacle) {
        this->id = obstacle.getId();
        this->texture = obstacle.getTexture();
    }

    /**
     *  Create obstacle from id
     */
    Obstacle(uint16_t id) {
        this->id = id;
    }

    ~Obstacle() { 
        if(texture)
            SDL_FreeSurface(texture);
    }

    /**
     *  Return obstacle's id
     */
    inline uint16_t getId() { return id; }

    /**
     *  Return obstacle's texture
     */
    inline SDL_Surface* getTexture() { return texture; }
};

#endif

