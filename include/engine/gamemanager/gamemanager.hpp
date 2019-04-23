#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <logger.hpp>

#include <hooks/typedefs.hpp>
#include <detours/detours.h>

#include <engine/datamanager/datamanager.hpp>
#include <engine/player/player.hpp>

class GameManager {
private:
    GameManager() { }
public:
    static SurfaceManager* surfacemanager;

    static void Init();
    static void HandleEvents();
    static void Render();

    static SurfaceManager* GetSurfaceManager() { return surfacemanager; }
};

#endif