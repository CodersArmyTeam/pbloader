#include <windows.h>
#include <cstdio>

#include <api/api.hpp>
#include <internal.hpp>
#include <detours/detours.h>
#include <logger.hpp>
#include <engine/player/player.hpp>
#include <engine/gamemanager/gamemanager.hpp>
#include <hooks/hook.hpp>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

DWORD WINAPI Main(LPVOID);

HANDLE thread;
bool quit;

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved) {
    switch(reason) {
        case DLL_PROCESS_ATTACH:
			    thread = CreateThread(NULL, 0, &Main, NULL, 0, NULL);
			break;
		case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}

DWORD WINAPI Main(LPVOID) {
    Internal::OpenConsole();
    Hooks::Init();

    logInfo("TEST: info",1);
    logError("TEST: err",2);
    logWarn("TEST: warn",3);
    return 0;
}
