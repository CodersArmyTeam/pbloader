#ifndef __INTERNAL_HPP
#define __INTERNAL_HPP

#include <windows.h>
#include <cstdio>
#include <cstdint>
#include <cmath>
#include <fcntl.h>
#include <stdint.h>

namespace Internal {
	HWND GetHWND();
	void OpenConsole();
	void CloseConsole();
	void SetTitle(const wchar_t* title);
	int MsgBox(const wchar_t* title, const wchar_t* content, uint32_t flags);
}

#endif
