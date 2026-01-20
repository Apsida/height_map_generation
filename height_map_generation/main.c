#include "generation_alg.h"
#include <stdio.h>
#include <stdlib.h>
#include "Tile.h"
#include "Object.h"

int BLOOM = 1;

static Tile** allocate_map(int size) {
	Tile** map = (Tile**)malloc(size * sizeof(Tile*));
	for (int i = 0; i < size; i++) {
		map[i] = (Tile*)malloc(size * sizeof(Tile));
	}
	return map;
}

static void print_map(Tile** map, int size) {
	for (int y = 0;y < size; y++) {
		for (int x = 0; x < size; x++) {
			printf("%f ", map[y][x].height);
		}
		printf("\n");
	}
}

int main() {
	int size = 5;
	Tile** map = allocate_map(size);
	Tile** smoothed = allocate_map(size);
	ds_gen_height_map(map, size, 6.75f);
	//apply_gaussian_filter(map, smoothed, size, BLOOM);
	print_map(smoothed, size);
	return 0;
}