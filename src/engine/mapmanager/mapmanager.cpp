#include <engine/mapmanager/mapmanager.hpp>

void MapManager::ModifyLocation() {
    /* insert magic code here */
    Location* current_location = locations[*location_x][*location_y];

    if(!current_location) {
        // TODO: zmień z polskiego na angielski
        logError("Nie ma w tablicy lokacji x: " + std::to_string(*location_x) + " y: " + std::to_string(*location_y) + "!");
    } else {
        current_location->Run();
    }
}