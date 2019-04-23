#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include <SDL2/SDL.h>

#include "storage.hpp"

class SurfaceManager {
public:
	SurfaceManager() { }

	/**
	 *	Add a new item to the container
	 */
	void Add(const std::string& key, SDL_Surface* surface) { surfaces.Add(key, surface); }

	/**
	 *	Remove an item from the container
	 */
	void Remove(const std::string& key) { surfaces.Remove(key); }

	/**
	 * 	Cleans the container
	 */	
	void Clear() { surfaces.Clear(); }

	/**
	 *	Returns the number of items in the container
	 */
	int Size() { return surfaces.Size(); };

	/**
	 *	Returns an item with a given name from the container
	 */
	SDL_Surface* Get(const std::string& key) { return surfaces.Get(key); }
private:
	res::Storage<SDL_Surface*> surfaces;
};

#endif