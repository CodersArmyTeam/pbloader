#ifndef PBLOADER_PLAYER_HPP
#define PBLOADER_PLAYER_HPP

#include <cmath>

#include <engine/vector/vector.hpp>

class Player {
private:
    float* pos_x = (float*)0x005411E0;
    float* pos_y = (float*)0x005411E4;
    int* death_count = (int*)0x005410F8;
public:
    Player() { }
    ~Player() { }

    /* TODO: Implement functions */
};

#endif //PBLOADER_PLAYER_HPP