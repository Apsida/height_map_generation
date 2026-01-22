#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "str_lib.h"
#include "objs_place_alg.h"

void objs_place_alg(Tile** map, int size, Obj* obj_type, int obj_type_count) {
	//Идём по списку всех типов объектов
	for (int i = 0; i < obj_type_count; i++) {
		while (obj_type[i].obj_count > 0) {
			//Случайно выбираем Тайл
			int x = rand() % size;
			int y = rand() % size;
			int flag = 1;
			int j = 0;
			
			if (map[y][x].obj != NULL) { continue; }
			flag = str_cmp(map[y][x].biome->name, obj_type[i].biome);/*
			while (map[y][x].biome->name[j] != '\0') {
				if (map[y][x].biome->name[j] != obj_type[i].biome[j]) {
					flag = 0;
					break;
				}
				j++;
			}*/
			if (flag == 1){
				map[y][x].obj = malloc(sizeof(Obj));
				if (map[y][x].obj == NULL) {
					printf("cant allocate memory");
					exit(EXIT_FAILURE);
				}
				*map[y][x].obj = obj_type[i];
				obj_type[i].obj_count--;
			}
		}
	}	
}