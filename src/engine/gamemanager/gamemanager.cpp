#include <engine/gamemanager/gamemanager.hpp>

SurfaceManager* GameManager::surfacemanager = new SurfaceManager;

SDL_Surface* eeee = NULL;

void GameManager::Init() {
    eeee = IMG_Load("auuu.png");
}

void GameManager::Render() {
    
}