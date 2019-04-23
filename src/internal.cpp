#include "../include/internal.hpp"

HWND Internal::GetHWND() {
	return FindWindow(NULL, "Perypetie Boba");
}

void Internal::OpenConsole() {
	AllocConsole();

	HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	int hCrt = _open_osfhandle((long)handle_out, _O_TEXT);
	FILE* hf_out = _fdopen(hCrt, "w");
	setvbuf(hf_out, NULL, _IONBF, 1);
	*stdout = *hf_out;

	HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
	hCrt = _open_osfhandle((long)handle_in, _O_TEXT);
	FILE* hf_in = _fdopen(hCrt, "r");
	setvbuf(hf_in, NULL, _IONBF, 128);
	*stdin = *hf_in;
}

/* This fucking function crashes */
void Internal::CloseConsole() {
	FreeConsole();

	FILE* nulf = NULL;
	*stdout = *nulf;
	*stdin = *nulf;
}

void Internal::SetTitle(const wchar_t* title) {
	HWND handle = Internal::GetHWND();
	SetWindowTextW(handle, title);
}

int Internal::MsgBox(const wchar_t* title, const wchar_t* content, uint32_t flags) {
	HWND handle = Internal::GetHWND();
	return MessageBoxW(handle, content, title, flags);
}
