#pragma once
#include "Tile.h"
#include "Biome.h"

void biome_init(Tile** map, Biome* biome_list, int size, int biome_count, Cmp_Func cmpf);