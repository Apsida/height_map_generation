#pragma once
#include "Tile.h"

void diamond_step (Tile** map, int size, int step, float roughness);
void square_step (Tile** map, int size, int step, float roughness);
float** diam_sq_alg (int size, float roughness);