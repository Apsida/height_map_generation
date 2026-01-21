#pragma once
#include "Tile.h"
#include "Tile_param.h"

Tile** allocate_map(int size);
void print_map(Tile** map, int size, tile_param param);
void fill_map(Tile** map, float** filler, tile_param param, int size, int max_val);
void save_info(Tile** map, int size);