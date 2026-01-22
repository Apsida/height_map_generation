#pragma once
#include "Biome.h"
#include "Obj.h"
typedef int (*Cmp_Func)(float data1, float data2, float data3);

typedef struct Tile {
	float height;
	float temperature;
	Biome* biome;
	Obj* obj;
}Tile;