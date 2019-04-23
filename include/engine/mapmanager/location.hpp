#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <algorithm>
#include <iterator>

#include <engine/mapmanager/obstacle.hpp>

class Location {
private:
    Obstacle* obstacles[576];
public:
    Location();

    ~Location();
    
    /**
     *  Sets the block type in the array
     */
    void SetObstacle(int x, int y, Obstacle* obstacle);
};

#endif