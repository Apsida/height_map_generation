#pragma once
#include "Tile.h"
#include "Tile_param.h"

Tile** allocate_map(int size);
void print_map(Tile** map, int size);
void fill_map(Tile** map, float** filler, tile_param param, int size, int MAX_HEIGHT);