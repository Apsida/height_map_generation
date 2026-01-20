#include <stdlib.h>
#include "map_IO.h"

Tile** allocate_map(int size) {
	Tile** map = (Tile**)malloc(size * sizeof(Tile*));
	for (int i = 0; i < size; i++) {
		map[i] = (Tile*)malloc(size * sizeof(Tile));
	}
	return map;
}

void print_map(Tile** map, int size) {
	for (int y = 0;y < size; y++) {
		for (int x = 0; x < size; x++) {
			printf("%f ", map[y][x].height);
		}
		printf("\n");
	}
}

void fill_map(Tile** map, float** filler, tile_param param, int size, int MAX_HEIGHT) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (param == HEIGHT) {
				map[i][j].height = filler[i][j] * MAX_HEIGHT;
			}
			else if (param == TEMPERATURE) {
				map[i][j].temperature = filler[i][j];
			}
		}
	}
}