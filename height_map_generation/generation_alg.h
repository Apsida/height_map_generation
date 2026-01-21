#pragma once
#include "Tile.h"
void diamond_step (Tile** map, int size, int step, float roughness);
void square_step (Tile** map, int size, int step, float roughness);
float** ds_gen_height_map (int size, float roughness);
void apply_gaussian_filter(Tile** input, Tile** output, int size, float bloom);