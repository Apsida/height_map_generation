#pragma once
#include "Biome.h"
#include "Obj.h"
typedef struct Tile {
	float height;
	float temperature;
	Biome* biome;
	Obj* obj;
}Tile;