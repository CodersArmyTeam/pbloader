#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP

#include <logger.hpp>
#include <engine/mapmanager/location.hpp>

const int MAXIMUM_LOCATIONS = 1000;

class MapManager
{
private:
    int* const location_x = (int*)0x00541118;
    int* const location_y = (int*)0x00541114;
    
    Location* locations[MAXIMUM_LOCATIONS][MAXIMUM_LOCATIONS];
public:
    MapManager() { }
    ~MapManager() { }

    /**
     *  Return location X
     */
    int GetLocationX() { return *location_x; }

    /**
     *  Return location Y
     */
    int GetlocationY() { return *location_y; }

    /**
     *  Set location X and location Y
     */
    int SetLocation(int location_x, int location_y) { 
        if(location_x > -1)
            *(this->location_x) = location_x;
        if(location_y > -1)
            *(this->location_y) = location_y;
    }

    /**
     *  Add Location object to array
     */
    void AddLocationToArray(int x, int y, Location* location) {
        if(!location) {
            logError("location is undefined! Aborting.");
            return;
        }

        if(locations[x][y]) {
            logWarn("Trying to override Location object! x: " + std::to_string(x) + " y: " + std::to_string(y));
            locations[x][y] = location;
        } else {
            logInfo("Adding location to array... x: " + std::to_string(x) + " y: " + std::to_string(y));
            locations[x][y] = location;
        }
    }

    /**
     *  Call Location::Run from array
     *  
     */
    void ModifyLocation();
};

#endif