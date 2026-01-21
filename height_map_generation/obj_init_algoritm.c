#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "obj_init_algoritm.h"

void objs_on_map_init(Tile** map, int size, Obj* obj_type, int obj_type_count, int obj_count) {
	while (obj_count > 0){
		int x = rand() % size;
		int y = rand() % size;
		if (map[y][x].obj != NULL) { continue; }
		for (int j = 0; j < obj_type_count; j++) {
			if (!strcmp(map[y][x].biome->name, obj_type[j].biome)) {
				map[y][x].obj = malloc(sizeof(Obj));
				if (map[y][x].obj == NULL) {
					printf("cant allocate memory");
					exit(EXIT_FAILURE);
				}
				*map[y][x].obj = obj_type[j];
				obj_count--;
				break;
			}
		}
	}
	
}