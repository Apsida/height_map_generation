#pragma once
#include "Tile.h"

char* str_read();
int str_cmp(char* a, char* b);
int biome_check(Tile** map, int size, char* biome);