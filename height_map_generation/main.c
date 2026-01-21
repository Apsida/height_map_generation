#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map_IO.h"
#include "UI.h"
#include "generation_alg.h"
#include "biome_init_alg.h"

int main() {
	int size;
	int bloom;
	int max_height;
	int max_temper;
	int biome_count;
	int obj_count;
	unsigned int seed;
	float roughness;


	map_init(&size, &max_height, &max_temper, &seed, &roughness, &bloom);
	Biome* biome_list = receive_biome_list(&biome_count, max_height, max_temper);
	Obj* obj_list = receive_obj_list(&obj_count);
	if (seed == 0) {
		srand(time(NULL));
	}
	else {
		srand(seed);
	}
	Tile** map = allocate_map(size);
	float** height_map = ds_gen_height_map(size, roughness);
	float** temper_map = ds_gen_height_map(size, roughness);
	fill_map(map, height_map, HEIGHT, size, max_height);
	fill_map(map, temper_map, TEMPERATURE, size, max_temper);
	save_info(map, size);
	biome_init(map, biome_list, size, biome_count);
	print_map(map, size, BIOME);
	//Tile** smoothed = allocate_map(size);
	//apply_gaussian_filter(map, smoothed, size, bloom);
	return 0;
}