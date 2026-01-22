#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map_IO.h"
#include "UI.h"
#include "generation_alg.h"
#include "biome_init_alg.h"
#include "objs_place_alg.h"
#include "str_lib.h"

int test_cmp(float a, float x, float b) {
	return (a <= x && x <= b);
}

int main() {
	int size;
	int max_height;
	int max_temper;
	int biome_count;
	int obj_type_count;
	unsigned int seed;
	float roughness;


	Tile** map = map_init(&size, &max_height, &max_temper, &seed, &roughness);
	Biome* biome_list = receive_biome_list(&biome_count, max_height, max_temper);
	if (seed == 0) {
		srand(time(NULL));
	}
	else {
		srand(seed);
	}

	float** height_map = diam_sq_alg(size, roughness);
	float** temper_map = diam_sq_alg(size, roughness);
	fill_map(map, height_map, HEIGHT, size, max_height);
	fill_map(map, temper_map, TEMPERATURE, size, max_temper);
	biome_init(map, biome_list, size, biome_count, test_cmp);
	view_count_biomes(map, size, biome_list, biome_count);
	Obj* obj_list = receive_obj_list(map, size, &obj_type_count);
	objs_place_alg(map, size, obj_list, obj_type_count);
	print_map(map, size, OBJECT);
	save_info(map, size);
	return 0;
}