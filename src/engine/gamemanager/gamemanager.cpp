#include <engine/gamemanager/gamemanager.hpp>

SurfaceManager* GameManager::surfacemanager = new SurfaceManager;
MapManager* GameManager::mapmanager = new MapManager;

Location* location = new Location;
SDL_Surface* yyy = NULL;

bool mhm = false;

void GameManager::Init() {
    yyy = IMG_Load("auuu.png");

    location->SetObstacle(31, 15, new Obstacle(1, true, true));
    location->SetObstacle(30, 15, new Obstacle(1, true, true));
    location->SetObstacle(29, 15, new Obstacle(1, true, true));
    location->SetObstacle(28, 15, new Obstacle(1, true, true));
    location->SetObstacle(27, 15, new Obstacle(1, true, true));

    location->SetObstacle(8, 15, new Obstacle(1, true, true));
    location->SetObstacle(7, 15, new Obstacle(1, true, true));
    location->SetObstacle(6, 15, new Obstacle(1, true, true));
    location->SetObstacle(5, 15, new Obstacle(1, true, true));
    location->SetObstacle(4, 15, new Obstacle(1, true, true));
    location->SetObstacle(3, 15, new Obstacle(1, true, true));
    location->SetObstacle(2, 15, new Obstacle(1, true, true));
    location->SetObstacle(1, 15, new Obstacle(1, true, true));
    location->SetObstacle(0, 15, new Obstacle(1, true, true));
    mapmanager->AddLocationToArray(9, 8, location);
    mapmanager->AddLocationToArray(8, 8, location);
}

void GameManager::Render() {
    mapmanager->UpdateLocation();
}

void GameManager::End() {
    delete location;
}