#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SDL2/SDL.h>

#include <engine/vector/vector.hpp>

class Obstacle {
private:
    /** 
     *  If obstacle is custom, id must be -1 (may change) 
     */
    int id = -1;

    /** 
     *  It doesn't have to be set if obstacle is built into the game.
     */
    SDL_Surface* texture = NULL;

    bool collision = false;
    bool shadow = false;

    int x;
    int y;
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
    Obstacle(int id, bool collision = false, bool shadow = false) {
        this->id = id;
        this->collision = collision;
        this->shadow = shadow;
    }

    /**
     *  Create custom obstacle
     */
    Obstacle(SDL_Surface* texture, bool collision = false, bool shadow = false) {
        this->texture = SDL_ConvertSurfaceFormat(texture, SDL_PIXELFORMAT_ARGB8888, NULL);
        this->collision = collision;
        this->shadow = shadow;
        this->id = -1;
    }

    ~Obstacle() { 
        if(texture)
            SDL_FreeSurface(texture);
    }

    /**
     *  Return obstacle's id
     */
    inline int GetId() { return id; }

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

    inline void SetPosition(const Vector2f& pos) { x = pos.x; y = pos.y; }
    inline void SetPosition(int x, int y) { this->x = x; this->y = y; }

    inline Vector2f GetPosition() {
        Vector2f vec;
        vec.x = x;
        vec.y = y;
        return vec;
    }
};

#endif

