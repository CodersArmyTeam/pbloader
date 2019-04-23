#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <algorithm>
#include <iterator>

#include <engine/mapmanager/obstacle.hpp>
#include <logger.hpp>

#include <api/api.hpp>

#define MAP_START 0x00541DC0
#define MAP_END   0x0054223E
#define MAP_WIDTH  32
#define MAP_HEIGHT 18

class Location {
private:
    Obstacle* obstacles[MAP_WIDTH * MAP_HEIGHT - 1];
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
};

#endif