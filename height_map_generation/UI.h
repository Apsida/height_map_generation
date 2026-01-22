#pragma once
#include "Obj.h"
#include "Biome.h"
#include "map_IO.h"

Tile** map_init(int* size, int* max_height, int* max_temper,
			  unsigned int* seed, double* roughness);
Biome* receive_biome_list(int* biome_count, int max_h, int max_t);
Obj* receive_obj_list(Tile** map, int size, int* obj_count);
void view_count_biomes(Tile** map, int size, Biome* biome_list, int biome_count);