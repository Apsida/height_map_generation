#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "str_lib.h"
#include "map_IO.h"

void view_count_biomes(Tile**map, int size, Biome* biome_list, int biome_count) {
	for (int i = 0; i < biome_count; i++) {
		int k = 0;
		for (int y = 0; y < size; y++) {
			for (int x = 0;x < size;x++) {
				if (str_cmp(map[y][x].biome->name, biome_list[i].name)) {
					k++;
				}
			}
		}
		printf("count of %s: %d\n", biome_list[i].name, k);
	}
}

Tile** map_init(int* size, int* max_height, int* max_temper, 
	unsigned int* seed, float* roughness) {
	printf("Size of map: ");
	scanf_s("%d", size);
	int n = *size - 1;
	if (n <= 0 || (n & (n - 1)) != 0) {
		printf("Err^ size must be 2^n+1\n");
		exit(EXIT_FAILURE);
	}
	printf("MAX_HEIGHT: ");
	scanf_s("%d", max_height);
	printf("MAX_TEMPERATURE: ");
	scanf_s("%d", max_temper);
	printf("SEED: ");
	scanf_s("%u", seed);
	printf("ROUGHNESS (from 0 to 1): ");
	scanf_s("%f", roughness);
	if (*roughness > 1 || *roughness < 0) {
		printf("Err of input");
		exit(EXIT_FAILURE);
	}
	return allocate_map(*size);
}

Biome* receive_biome_list(int* biome_count, int max_h, int max_t) {
	int n;
	printf("Input count of biomes ");
	scanf_s("%d", &n);
	if (n == 0) {
		return NULL;
	}
	Biome* biome_list = malloc(n * sizeof(Biome));
	if (biome_list == NULL) {
		printf("ERR: cant allocate memory");
		exit(EXIT_FAILURE);
	}

	printf("Input parametres of object: ");
	for (int i = 0; i < n; i++) {
		Biome ob;
		printf("name:");
		ob.name = str_read();
		printf("limit of height low: ");
		scanf_s("%lf", &ob.left_limit_h);
		printf("limit of height high: ");
		scanf_s("%lf", &ob.right_limit_h);
		if (ob.left_limit_h > ob.right_limit_h || 
			ob.left_limit_h < 0 || ob.right_limit_h > max_h) {
			printf("limit is incorrect");
			exit(EXIT_FAILURE);
		}
		printf("limit of temperature low: ");
		scanf_s("%lf", &ob.left_limit_t);
		printf("limit of temperature high: ");
		scanf_s("%lf", &ob.right_limit_t);
		if (ob.left_limit_t > ob.right_limit_t ||
			ob.left_limit_t < 0 || ob.right_limit_t > max_t) {
			printf("limit is incorrect");
			exit(EXIT_FAILURE);
		}
		biome_list[i] = ob;
	}
	*biome_count = n;
	return biome_list;
}

Obj* receive_obj_list(Tile** map, int size,int* obj_type_count) {
	int n;
	printf("Input count of types of objects ");
	scanf_s("%d", &n);
	if (n == 0) {
		return NULL;
	}
	Obj* obj_list = malloc(n * sizeof(Obj));
	if (obj_list == NULL) {
		printf("ERR: cant allocate memory");
		exit(EXIT_FAILURE);
	}

	printf("Input parametres of object: ");
	for (int i = 0; i < n; i++) {
		Obj ob;
		printf("name:");
		ob.name = str_read();
		printf("biome in which appears:");
		ob.biome = str_read();
		int bcm = biome_check(map, size, ob.biome);
		printf("Count of biomes on map: %d\n Input count of object: ", bcm);
		scanf_s("%d", &ob.obj_count);
		if (ob.obj_count > bcm) {
			printf("ERROR OF COUNT: count of objects > count of biomes");
			exit(EXIT_FAILURE);
		}
		obj_list[i] = ob;

	}
	*obj_type_count = n;
	return obj_list;
}
