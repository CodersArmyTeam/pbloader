#include <windows.h>

DWORD GetWindowProcessId(const char* title);
int DisplayError(const wchar_t* message);
bool FileExists(const char* path);
bool InjectDLL(DWORD pid, const char* path);

int main(int argc, char* argv[]) {
	char path[MAX_PATH];
	bool inject = false;

	for(int i = 1; i < argc; i++) {
		if(!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
			MessageBoxW(NULL, L"-h    --help    Wyśwetla pomoc\n-i    --inject    Wpina się do istniejącego okna gry", L"PB Loader", MB_OK);
			return 0;
		} else if((!strcmp(argv[i], "--inject") || !strcmp(argv[i], "-i")) && !inject) {
			inject = true;
		}
	}

	if(!inject) {
		GetFullPathName("PerypetieBoba.exe", MAX_PATH, path, NULL);

		if(FileExists(path)) {
			if(WinExec(path, SW_HIDE) <= 31) {
				DisplayError(L"Błąd podczas uruchamiania gry");
				return 1;
			}
		} else {
			DisplayError(L"Nie znaleziono plików z grą");
			return 1;
		}
	}

	DWORD pid = GetWindowProcessId("Perypetie Boba");
	if(pid != 0) {
		GetFullPathName("pbloader.dll", MAX_PATH, path, NULL);

		if(FileExists(path)) {
			if(!InjectDLL(pid, path)) {
				DisplayError(L"Nie można wczytać Mod Loadera\nSpróbuj wykonać następujące czynności:\n    - Upewnij się, czy gra jest włączona\n    - Ponownie uruchom grę\n    - Uruchom launcher jako adminstrator\nJeżeli to nie pomoże skontaktuj się z deweloperem");
				return 1;
			}
		} else {
			DisplayError(L"Nie znaleziono plików Mod Loadera");
			return 1;
		}
	} else {
		DisplayError(L"Gra nie została uruchomiona");
		return 1;
	}

	return 0;
}

DWORD GetWindowProcessId(const char* title) {
	DWORD pid = 0;
	HWND handle = FindWindow(NULL, title);
	if(handle) {
		GetWindowThreadProcessId(handle, &pid);
	}
	return pid;
}

int DisplayError(const wchar_t* message) {
	return MessageBoxW(NULL, message, L"PB Loader", MB_OK | MB_ICONERROR);
}

bool FileExists(const char* path) {
	DWORD Attributes = GetFileAttributes(path);
	return (Attributes != INVALID_FILE_ATTRIBUTES && !(Attributes & FILE_ATTRIBUTE_DIRECTORY));
}

bool InjectDLL(DWORD pid, const char* path) {
	HANDLE process, thread;
	LPVOID memory;
	LPTHREAD_START_ROUTINE RemoteLoadLibrary;
	bool state = false;

	// Dla opornych PROCESS_ALL_ACCESS może się przydać
	if((process = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_CREATE_THREAD, false, pid)) != NULL) {
		DWORD size = strlen(path) + 1;

		// Dla opornych PAGE_EXECUTE_READWRITE może się przydać
		if((memory = VirtualAllocEx(process, NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READ)) != NULL) {
			if(WriteProcessMemory(process, memory, path, size, NULL)) {
				RemoteLoadLibrary = (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");

				if((thread = CreateRemoteThread(process, NULL, 0, RemoteLoadLibrary, memory, 0, NULL)) != NULL) {
					state = true;
					CloseHandle(thread);
				}
			}

		}

		CloseHandle(process);
	}

	return state;
}
