#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP

class MapManager {
private:
    int* location_x = (int*)0x00541118;
    int* location_y = (int*)0x00541114;

    int last_location_x;
    int last_location_y;
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
};

#endif