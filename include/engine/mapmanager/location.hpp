#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <algorithm>
#include <iterator>
#include <vector>

#include <engine/mapmanager/obstacle.hpp>

#include <hooks/typedefs.hpp>
#include <logger.hpp>

#define MAP_START 0x00541DC0
#define MAP_END   0x0054223E
#define MAP_WIDTH  32
#define MAP_HEIGHT 18

#define COLLISION_START 0x00541B80
#define COLLISION_END   0x00541DBF

#define SHADOWS_START 0x00541280
#define SHADOWS_END   0x005414BF

#define BLOCK_RESOLUTION 10

class Location {
private:
    Obstacle* obstacles[MAP_WIDTH * MAP_HEIGHT - 1];
    std::vector<Obstacle*> custom_obstacles;

    bool render = false;

    void SetCollision(int x, int y, bool state);
    void SetShadow(int x, int y, bool state);
public:
    Location();

    ~Location();
    
    /**
     *  Sets the block type in the array
     */
    void SetObstacle(int x, int y, Obstacle* obstacle);
    
    void PlaceObstacle(int x, int y, Obstacle* obstacle);

    /**
     *  Modify current location
     */
    void Run();

    void Update();

    void SetRenderState(bool state) { render = state; }
};

#endif