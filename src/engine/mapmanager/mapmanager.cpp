#include <engine/mapmanager/mapmanager.hpp>

void MapManager::ModifyLocation() {
    /* insert magic code here */
    Location* current_location = locations[*location_x][*location_y];
    Location* last_location = locations[last_location_x][last_location_y];

    if(!current_location) {
        // TODO: zmień z polskiego na angielski
        logError("Nie ma w tablicy lokacji x: " + std::to_string(*location_x) + " y: " + std::to_string(*location_y) + "!");
    } else {
        current_location->Run();
        last_location_x = *location_x;
        last_location_y = *location_y;
    }

    if(last_location) {
        //last_location->SetRenderState(false);
    }
}

void MapManager::UpdateLocation() {
    // TODO: Make that the rendering was similar to PB

    Location* current_location = locations[*location_x][*location_y];

    if(!current_location) {
        // TODO: zmień z polskiego na angielski
        //logError("Nie ma w tablicy lokacji x: " + std::to_string(*location_x) + " y: " + std::to_string(*location_y) + "!");
    } else {
        current_location->Update();
    }
}