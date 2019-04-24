#include <engine/gamemanager/gamemanager.hpp>

SurfaceManager* GameManager::surfacemanager = new SurfaceManager;
MapManager* GameManager::mapmanager = new MapManager;

SDL_Surface* eeee = NULL;
Location* location = new Location;

void GameManager::Init() {
    eeee = IMG_Load("auuu.png");

    location->SetObstacle(8, 15, new Obstacle(1, true, true));
    mapmanager->AddLocationToArray(9, 8, location);
}

void GameManager::Render() {
    
}

void GameManager::End() {
    delete location;
}