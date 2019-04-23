#include <api/api.hpp>

int API::GetXLoc() {
	int* ptr = (int*)0x00541118;
	return *ptr;
}

int API::GetYLoc() {
	int* ptr = (int*)0x00541114;
	return *ptr;
}

void API::SetXLoc(int val) {
	int* ptr = (int*)0x00541118;
	*ptr = val;
}

void API::SetYLoc(int val) {
	int* ptr = (int*)0x00541114;
	*ptr = val;
}

////////////////////////////////////////////////////////////////////////////////

float API::GetXPos() {
	return 0;
}

float API::GetYPos() {
	return 0;
}

void API::SetXPos(float val) {
	
}

void API::SetYPos(float val) {
	
}

////////////////////////////////////////////////////////////////////////////////

void API::Shoot() {
	uint8_t* ptr = (uint8_t*)0x00542460;
	*ptr = 1;
}

void API::Respawn() {
	uint8_t* ptr = (uint8_t*)0x005411F0;
	*ptr = 1;
}

////////////////////////////////////////////////////////////////////////////////

int API::GetDeathCount() {
	return 0;
}

void API::SetDeathCount(int val) {
	
}

////////////////////////////////////////////////////////////////////////////////

void API::PlaceBlock(int x, int y, uint16_t ID, bool solid) {
	SetBlock(x, y, ID);
	if(solid) AddCollision(x, y);	
	AddShadow(x, y);
}

// x*MAP_HEIGHT+y
void API::SetBlock(int x, int y, uint16_t ID) {
	uint16_t* ptr = (uint16_t*)MAP_START;

	// Set X
	for(int i = 0; i < x * MAP_HEIGHT; i++) {
		ptr += 0x00000001;
	}

	// Set Y
	for(int i = 0; i < y; i++) {
		ptr += 0x00000001;
	}

	*ptr = ID;
}

////////////////////////////////////////////////////////////////////////////////

void API::AddCollision(int x, int y) {
	SetCollision(x, y, true);
}

void API::RemoveCollision(int x, int y) {
	SetCollision(x, y, false);
}

void API::SetCollision(int x, int y, bool state) {
	bool* ptr = (bool*)COLLISION_START;

	for(int i = 0; i < x * MAP_HEIGHT; i++) {
		ptr += 0x00000001;
	}

	for(int i = 0; i < y; i++) {
		ptr += 0x00000001;
	}

	*ptr = state;
}

////////////////////////////////////////////////////////////////////////////////

void API::AddShadow(int x, int y) {
	SetShadow(x, y, true);
}

void API::RemoveShadow(int x, int y) {
	SetShadow(x, y, false);
}

void API::SetShadow(int x, int y, bool state) {
	bool* ptr = (bool*)SHADOWS_START;

	for(int i = 0; i < x * MAP_HEIGHT; i++) {
		ptr += 0x00000001;
	}

	for(int i = 0; i < y; i++) {
		ptr += 0x00000001;
	}

	*ptr = state;
}

////////////////////////////////////////////////////////////////////////////////