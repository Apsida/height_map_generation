#include "generation_alg.h"
#include <stdio.h>
#include <stdlib.h>

int BLOOM = 1;

static float** allocate_map(int size) {
	float** map = (float**)malloc(size * sizeof(float*));
	for (int i = 0; i < size; i++) {
		map[i] = (float*)malloc(size * sizeof(float));
	}
	return map;
}

static void print_map(float** map, int size) {
	for (int y = 0;y < size; y++) {
		for (int x = 0; x < size; x++) {
			printf("%f ", map[y][x]);
		}
		printf("\n");
	}
}

int main() {
	int size = 9;
	float** map = allocate_map(size);
	float** smoothed = allocate_map(size);
	ds_gen_height_map(map, size, 6.75f);
	apply_gaussian_filter(map, smoothed, size, BLOOM);
	print_map(smoothed, size);
	return 0;
}