#include <stdio.h>
#include <stdlib.h>
#include "biome_init_alg.h"

void biome_init(Tile** map, Biome* biome_list, int size, int biome_count, Cmp_Func cmpf) {
    if (biome_count == 0) {
        printf("Нет биомов.\n");
        return 0;
    }
    //Идём по карте расставляя биомы
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            map[y][x].biome = NULL;
            for (int i = 0; i < biome_count; i++) {
                //смотрим лежат ли значения тайла в границах параметрво биома
                if (cmpf(biome_list[i].left_limit_h, map[y][x].height, biome_list[i].right_limit_h) &&
                    cmpf(biome_list[i].left_limit_t, map[y][x].temperature, biome_list[i].right_limit_t)
                    ) {
                    map[y][x].biome = &biome_list[i];
                }
            }
            if (map[y][x].biome == NULL) {
                printf("%f, %f\n", map[y][x].height, map[y][x].temperature);
                printf("Biome not found");
                exit(EXIT_FAILURE);
            }
        }
    }
}