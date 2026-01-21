#pragma once
#include "Obj.h"
#include "Biome.h"

void map_init(int* size, int* max_height, int* max_temper,
			  unsigned int* seed, double* roughness, int* bloom);
Biome* receive_biome_list(int* biome_count, int max_h, int max_t);
Obj* receive_obj_list(int* obj_count);