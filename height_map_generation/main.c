#include <stdio.h>
#include <stdlib.h>
#include "map_IO.h"
#include "generation_alg.h"

int BLOOM = 1;
int MAX_HEIGHT = 1;
float ROUGHNESS = 0.6f;

int main() {
	int size = 9;
	Tile** map = allocate_map(size);
	Tile** smoothed = allocate_map(size);
	float** height_map = ds_gen_height_map(size, ROUGHNESS);
	fill_map(map, height_map, HEIGHT, size, MAX_HEIGHT);
	print_map(map, size);
	//apply_gaussian_filter(map, smoothed, size, BLOOM);
	return 0;
}