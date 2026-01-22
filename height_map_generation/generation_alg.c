#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "generation_alg.h"

static float**allocate_map(int size) {
	float** map = (float**)malloc(size * sizeof(float*));
	for (int i = 0; i < size; i++) {
		map[i] = (float*)malloc(size * sizeof(float));
	}
	return map;
}

static float _random_num (float roughness, float avg) {
	float rand_val = (float)rand() / RAND_MAX;
	return (roughness * rand_val  + (1.0f - roughness) * avg);
}

void diamond_step (float** map, int size, int step, float roughness) {
	int half = step / 2;
	for (int y = half; y < size; y += step) {
		for (int x = half; x < size; x += step) {
			//Считаем среднее значение соседей справа, сверху, снизу, слева
			float avg = (map[y - half][x - half] +
				map[y - half][x + half] +
				map[y + half][x - half] +
				map[y + half][x + half]) / 4;
			map[y][x] = _random_num(roughness, avg);
		}
	}
}

void square_step (float** map, int size, int step, float roughness) {
	int half = step / 2;
	for (int y = 0; y < size; y += half) {
		int start_x = (y % step == 0) ? half : 0;
		for (int x = start_x; x < size; x += step) {
			float sum = 0.0f;
			int count = 0;
			//Считаем среднее значение соседей по диогоналям
			if (y >= half) {
				sum += map[y - half][x];
				count++;
			}
			if (y + half < size) {
				sum += map[y + half][x];
				count++;
			}
			if (x >= half) {
				sum += map[y][x - half];
				count++;
			}
			if (x + half < size) {
				sum += map[y][x + half];
				count++;
			}
			map[y][x] = _random_num(roughness, sum / count);
		}
	}
}

float** diam_sq_alg(int size, float roughness) {
	float** map = allocate_map(size);
	int n = size - 1;
	if (n <= 0 || (n & (n - 1)) != 0) {
		printf("Err^ size must be 2^n+1\n");
		exit(EXIT_FAILURE);
	}
	// Задаём начальные значения в углах карты
	map[0][0] = (float)rand() / RAND_MAX;
	map[0][size - 1] = (float)rand() / RAND_MAX;
	map[size - 1][0] = (float)rand() / RAND_MAX;
	map[size - 1][size - 1] = (float)rand() / RAND_MAX;
	int step = size - 1;

	while (step > 1) {
		diamond_step(map, size, step, roughness);
		square_step(map, size, step, roughness);
		step /= 2;
	}
	return map;
}