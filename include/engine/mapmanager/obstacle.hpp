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

    bool collision = false;
    bool shadow = false;
public:
    Obstacle() { }

    /**
     *  Create obstacle from other obstacle
     */
    Obstacle(Obstacle& obstacle) {
        this->id = obstacle.GetId();
        this->texture = obstacle.GetTexture();
    }

    /**
     *  Create obstacle from id, collision state and shadow state
     */
    Obstacle(uint16_t id, bool collision = false, bool shadow = false) {
        this->id = id;
        this->collision = collision;
        this->shadow = shadow;
    }

    /**
     *  Create custom obstacle
     */
    Obstacle(SDL_Surface* texture, bool collision = false, bool shadow = false) {
        this->texture = texture;
        this->collision = collision;
        this->shadow = shadow;
    }

    ~Obstacle() { 
        if(texture)
            SDL_FreeSurface(texture);
    }

    /**
     *  Return obstacle's id
     */
    inline uint16_t GetId() { return id; }

    /**
     *  Return obstacle's texture
     */
    inline SDL_Surface* GetTexture() { return texture; }

    /**
     *  Return obstacle's collision state
     */
    inline bool GetCollisionState() { return collision; }

    /**
     *  Return obstacle's shadow state
     */
    inline bool GetShadowState() { return shadow; }
};

#endif

