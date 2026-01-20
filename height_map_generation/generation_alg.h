#pragma once
#include "Tile.h"
void diamond_step (Tile** map, int size, int step, float scale);
void square_step (Tile** map, int size, int step, float scale);
void ds_gen_height_map (Tile** map, int size, float roughness);
void apply_gaussian_filter(Tile** input, Tile** output, int size, float bloom);