#include <engine/mapmanager/location.hpp>

Location::Location() {
    /* Fill everything with NULL */
    for(Obstacle* obstacle : obstacles) {
        obstacle = NULL;
    }
}

Location::~Location() {
    /* Remove from memory and set to NULL */
    for(Obstacle* obstacle : obstacles) {
        if(obstacle) {
            delete obstacle;
            obstacle = NULL;
        }
    }
}
