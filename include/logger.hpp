#pragma once

#include <iostream>
#include <windows.h>

#ifndef LOGGER_OFF

    #ifndef LOGGER_OFF_INFO
        #define logInfo(x...)  setConsoleColor(15);_logger_raw("[INFO]" , x, " at", __FILE__ , "\b:", __LINE__);setConsoleColor(15)
    #endif

    #ifndef LOGGER_OFF_ERROR
        #define logError(x...) setConsoleColor(12);_logger_raw("[ERROR]", x, " at", __FILE__ , "\b:", __LINE__);setConsoleColor(15)
    #endif

    #ifndef LOGGER_OFF_WARN
        #define logWarn(x...)  setConsoleColor(14);_logger_raw("[WARN]" , x, " at", __FILE__ , "\b:", __LINE__);setConsoleColor(15)
    #endif

#else

    #define logInfo(x...);
    #define logError(x...);
    #define logWarn(x...);

#endif

static void setConsoleColor(unsigned char a) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, a);
}

template<typename T>
static void _logger_raw(const T& arg) {
    std::cout << arg << '\n';
}

template<typename T, typename ... T2>
static void _logger_raw(const T& arg, const T2& ... args) {
    std::cout << arg << ' ';
	_logger_raw(args...);
}

#define UNIMPLEMENTED logWarn(__FUNCTION__ + " stub, but is unimplemented!");
#define UNIMPLEMENTED_PART logWarn("This part of code is unimplemented! FIX IT!");