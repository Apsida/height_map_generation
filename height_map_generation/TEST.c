#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map_IO.h"
#include "UI.h"
#include "generation_alg.h"
#include "biome_init_alg.h"
#include "objs_place_alg.h"
#include "str_lib.h"

static int test_cmp(float a, float x, float b) {
	return (a <= x && x <= b);
}

int TEST_OBJ_PLACEMENT() {
	int res = 1;
	int size = 129;
	int max_height = 10;
	int max_temper = 10;
	int biome_count = 2;
	int obj_type_count = 1;
	unsigned int seed = 0;
	float roughness = 0.1f;

	Tile** map = allocate_map(size);
	set_seed(seed);
	Biome sea;
	sea.name = "~sea";
	sea.left_limit_h = 0; sea.right_limit_h = 10; sea.left_limit_t = 0; sea.right_limit_t = 5;
	Biome forest;
	forest.name = "#forest";
	forest.left_limit_h = 0; forest.right_limit_h = 10; forest.left_limit_t = 5; forest.right_limit_t = 10;
	Biome* biome_list = malloc(biome_count * sizeof(Biome));
	biome_list[0] = sea;
	biome_list[1] = forest;

	float** height_map = diam_sq_alg(size, roughness);
	float** temper_map = diam_sq_alg(size, roughness);
	fill_map(map, height_map, HEIGHT, size, max_height);
	fill_map(map, temper_map, TEMPERATURE, size, max_temper);
	biome_init(map, biome_list, size, biome_count, test_cmp);
	view_count_biomes(map, size, biome_list, biome_count);

	Obj* obj_list = malloc(obj_type_count * sizeof(Obj));
	Obj ob;
	ob.name = "chest";
	ob.biome = "#forest";
	ob.obj_count = 15;
	obj_list[0] = ob;
	objs_place_alg(map, size, obj_list, obj_type_count);

	int counter = 0;
	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			if (map[y][x].obj != NULL) {
				counter++;
			}
		}
	}
	if (counter != obj_list[0].obj_count) {
		res = 0;
	}
	return res;
}

int run_all_tests() {
	const int count_tests = 1;
	int count_passed_test = 0;
	count_passed_test += TEST_OBJ_PLACEMENT();
	printf("Tests completed %d / %d", count_passed_test, count_tests);
	return 0;
}