#include <stdio.h>
#include "biome_defin_alg.h"

void biome_defin(Tile** map, int size) {
    if (obj_count == 0) {
        printf("Нет биомов.\n");
        return 0;
    }

    double step = 1.0 / obj_count;
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            for (int i = 0; i < obj_count; ++i) {
                double left = i * step;
                double right = (i + 1) * step;
                if (left <= map[y][x].height <= right) {
                    map[y][x].biome = biome_list[i];
                }
        }
    }
}