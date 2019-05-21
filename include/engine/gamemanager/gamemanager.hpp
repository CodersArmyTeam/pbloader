#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <logger.hpp>

#include <hooks/typedefs.hpp>
#include <detours/detours.h>
#include <sol/sol.hpp>

#include <engine/datamanager/datamanager.hpp>
#include <engine/player/player.hpp>
#include <engine/mapmanager/mapmanager.hpp>

class GameManager {
private:
    GameManager() { }
public:
    static SurfaceManager* surfacemanager;
    static MapManager* mapmanager;

    static void Init();
    static void HandleEvents();
    static void Render();
    static void End();

    static SurfaceManager* GetSurfaceManager() { return surfacemanager; }
    static MapManager* GetMapManager() { return mapmanager; }
};

#endif