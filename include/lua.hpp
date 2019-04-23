#ifndef __LUA_HPP
#define __LUA_HPP

#include <lua5.3/lua.hpp>

class Lua {
private:
	lua_State* state;
public:
	Lua(const char* filename) {
		// Create new state
		state = luaL_newstate();

		// Make standard libraries available
		luaL_openlibs(state);

		int result;

		// Load the script
		result = luaL_loadfile(state, filename);

		if(result != LUA_OK) {
			throw GetError();
			return;
		}

		// Execute the script
		result = lua_pcall(state, 0, LUA_MULTRET, 0);

		if(result != LUA_OK) {
			throw GetError();
			return;
		}
	}

	~Lua() {
		lua_close(state);
	}

	const char* GetError() {
		// The error message is on top of the stack
		// Fetch it, pop it off the stack and return it
		const char* error = lua_tostring(state, -1);
		lua_pop(state, 1);
		return error;
	}

	// Dodaj jakieś ustawianie/pobieranie wartości
	// Ustawianie zrób na overloadzie
}

#endif
