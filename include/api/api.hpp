#ifndef __API_HPP
#define __API_HPP

#include <windows.h>
#include <cstdio>
#include <cstdint>
#include <cmath>
#include <fcntl.h>

#include <internal.hpp>
#include <engine/player/player.hpp>

#define MAP_WIDTH  32
#define MAP_HEIGHT 18

#define MAP_START 0x00541DC0
#define MAP_END   0x0054223E

#define COLLISION_START 0x00541B80
#define COLLISION_END   0x00541DBF

#define SHADOWS_START 0x00541280
#define SHADOWS_END   0x005414BF

namespace API {
	
	int GetXLoc();
	int GetYLoc();
	void SetXLoc(int val);
	void SetYLoc(int val);

	float GetXPos();
	float GetYPos();
	void SetXPos(float val);
	void SetYPos(float val);

	void Shoot();
	void Respawn();

	int GetDeathCount();
	void SetDeathCount(int val);

	void PlaceBlock(int x, int y, uint16_t ID, bool solid = true);
	void SetBlock(int x, int y, uint16_t ID);

	void AddCollision(int x, int y);
	void RemoveCollision(int x, int y);
	void SetCollision(int x, int y, bool state);

	void AddShadow(int x, int y);
	void RemoveShadow(int x, int y);
	void SetShadow(int x, int y, bool state);

}

#endif
