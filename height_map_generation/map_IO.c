#include <stdio.h>
#include <stdlib.h>
#include "map_IO.h"

static void set_null(Tile** map, int size) {
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size;x++) {
			map[y][x].obj = NULL;
		}
	}
}

Tile** allocate_map(int size) {
	Tile** map = (Tile**)malloc(size * sizeof(Tile*));
	for (int i = 0; i < size; i++) {
		map[i] = (Tile*)malloc(size * sizeof(Tile));
	}
	set_null(map, size);
	return map;
}

void print_map(Tile** map, int size, tile_param param) {
	for (int y = 0;y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (param == HEIGHT) {
				printf("%f ", map[y][x].height);
			}
			else if (param == TEMPERATURE) {
				printf("%f ", map[y][x].temperature);
			}
			else if (param == BIOME) {
				printf("%c", map[y][x].biome->name[0]);
			}
			else if (param == OBJECT) {
				if (map[y][x].obj != NULL) {
					printf("%c", map[y][x].obj->name[0]);
				}
				else {
					printf("%c", map[y][x].biome->name[0]);
				}
			}
		}
		printf("\n");
	}
}

void fill_map(Tile** map, float** filler, tile_param param, int size, int max_val) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (param == HEIGHT) {
				map[i][j].height = filler[i][j] * max_val;
			}
			else if (param == TEMPERATURE) {
				map[i][j].temperature = filler[i][j] * max_val;
			}
		}
	}
}
void save_info(Tile** map, int size) {
	FILE* file1 = fopen("height.txt", "w");
	if (file1 == NULL) {
		perror("Ошибка открытия файла");
		return 1;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fprintf(file1, "%f ", map[i][j].height);
		}
		fprintf(file1, "\n");
	}
	fclose(file1);
	FILE* file = fopen("temper.txt", "w");
	if (file == NULL) {
		perror("Ошибка открытия файла");
		return 1;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fprintf(file, "%f ", map[i][j].temperature);
		}
		fprintf(file, "\n");
	}
	fclose(file);
	printf("Массив успешно записан в файл temper.txt\n");
}