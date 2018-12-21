#include <windows.h>
#include <cstdio>

#include <api/api.hpp>
#include <internal.hpp>
#include <detours/detours.h>
#include <hooks/hook.hpp>

#include <SDL2/SDL.h>

DWORD WINAPI Main(LPVOID);

HANDLE thread;
bool quit;

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID reserved) {
    switch(reason) {
        case DLL_PROCESS_ATTACH:
			    thread = CreateThread(NULL, 0, &Main, &quit, 0, NULL);
			break;
		case DLL_PROCESS_DETACH:
            Hooks::Clear();
            Internal::CloseConsole();
			break;
	}
	return TRUE;
}

DWORD WINAPI Main(LPVOID) {
    Internal::OpenConsole();
    if(!Hooks::Init()) {
        return FALSE;
    }
    return 0;
}
