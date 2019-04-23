#ifndef PBLOADER_PLAYER_HPP
#define PBLOADER_PLAYER_HPP

#include <cmath>

#include <engine/vector/vector.hpp>

class Player {
private:
    float* const pos_x = (float*)0x005411E0;
    float* const pos_y = (float*)0x005411E4;
    int* const death_count = (int*)0x005410F8;
public:
    Player() { }
    ~Player() { }

    /* TODO: Implement functions */

    /**
     *  Return position 
     */
    Vector2f GetPosition() {
        Vector2f vec;
        vec.x = *pos_x;
        vec.y = *pos_y;

        return vec;
    }

    /**
     *  Return death count
     */
    int GetDeathCount() {
        return *death_count;
    }

    /**
     *  Set player's position
     */ 
    void SetPosition(const Vector2f& vec) {
        *pos_x = vec.x;
        *pos_y = vec.y;
    }

    /**
     *  Set player's death count
     */
    void SetDeathCount(int count) {
        *death_count = count;
    }
};

#endif //PBLOADER_PLAYER_HPP