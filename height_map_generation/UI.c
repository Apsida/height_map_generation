#include "UI.h"
#include <stdio.h>
#include <stdlib.h>

static char* str_read() {
	char* str = malloc(sizeof(char)*20);
	char c = getchar();
	for (int i = 0; i < 20; i++) {
		c = getchar();
		str[i] = c;
		if (c == '\n' && i != 0) {
			str[i] = '\0';
			return str;
		}
	}
	return str;
}

void map_init(int* size, int* max_height, int* max_temper, 
	unsigned int* seed, float* roughness, int* bloom) {
	printf("Size of map: ");
	scanf_s("%d", size);
	printf("MAX_HEIGHT: ");
	scanf_s("%d", max_height);
	printf("MAX_TEMPERATURE: ");
	scanf_s("%d", max_temper);
	printf("SEED: ");
	scanf_s("%u", seed);
	printf("ROUGHNESS (from 0 to 1): ");
	scanf_s("%f", roughness);
	printf("BLOOM (0 or 1): ");
	scanf_s("%d", bloom);
}

Biome* receive_biome_list(int* biome_count, int max_h, int max_t) {
	int n;
	printf("Input count of biomes ");
	scanf_s("%d", &n);
	if (n == 0) {
		return NULL;
	}
	Biome* biome_list = malloc(n * sizeof(Biome));
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

Obj* receive_obj_list(int* obj_count) {
	int n;
	printf("Input count of objects ");
	scanf_s("%d", &n);
	if (n == 0) {
		return NULL;
	}
	Obj* obj_list = malloc(n * sizeof(Obj));
	printf("Input parametres of object:\n name: ");
	for (int i = 0; i < n; i++) {
		Obj ob;
		ob.id = i;
		if (fgets(ob.name, sizeof(ob.name), stdin) == NULL) {
			printf("Err of input");
			exit(EXIT_FAILURE);
		}
		else {
			ob.name[strcspn(ob.name, "\n")] = '\0';
		}
		printf("popability of spawn: ");
		scanf_s("%f", &ob.probability);
	}
	*obj_count = n;
	return obj_list;
}
