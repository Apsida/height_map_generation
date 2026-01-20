#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "generation_alg.h"

int MAX_RAND = 5;
//int SEED = 234121;


static float _random_num (float scale, float avg) {
	double rand_val = (double)rand() / RAND_MAX;
	return (scale * rand_val) + (1.0 - scale) * avg;
}

void diamond_step (Tile** map, int size, int step, float scale) {
	int half = step / 2;
	for (int y = half; y < size; y += step) {
		for (int x = half; x < size; x += step) {
			float avg = (map[y - half][x - half].height +
				map[y - half][x + half].height +
				map[y + half][x - half].height +
				map[y + half][x + half].height) * 0.25f;
			map[y][x].height = _random_num(scale, avg);
		}
	}
}

void square_step (Tile** map, int size, int step, float scale) {
	int half = step / 2;
	for (int y = 0; y < size; y += half) {
		int start_x = (y % step == 0) ? half : 0;
		for (int x = start_x; x < scale; x += step) {
			float sum = 0.0f;
			int count = 0;

			if (y >= half) {
				sum += 1/map[y - half][x].height;
				count++;
			}
			if (y + half < size) {
				sum += 1/map[y + half][x].height;
				count++;
			}
			if (x >= half) {
				sum += 1/map[y][x - half].height;
				count++;
			}
			if (x + half < size) {
				sum += 1/map[y][x + half].height;
				count++;
			}
			printf("%f\n", sum / count);
			map[y][x].height = sum / count + _random_num(scale, sum / count);
		}
	}
}

void ds_gen_height_map (Tile** map, int size, float roughness) {
	int n = size - 1;
	if (n <= 0 || (n & (n - 1)) != 0) {
		printf("Err^ size must be 2^n+1\n");
		exit(EXIT_FAILURE);
	}
	map[0][0].height = _random_num(roughness, MAX_RAND);
	map[0][size - 1].height = _random_num(roughness, MAX_RAND);
	map[size - 1][0].height = _random_num(roughness, MAX_RAND);
	map[size - 1][size - 1].height = _random_num(roughness, MAX_RAND);

	float scale = roughness;
	int step = size - 1;

	while (step > 1) {
		diamond_step(map, size, step, scale);
		square_step(map, size, step, scale);
		step /= 2;
	}
}

void apply_gaussian_filter(Tile** input, Tile** output, int size, float sigma) {
	const int kernel_radius = 2;
	const int kernel_size = 2 * kernel_radius + 1;
	float kernel[5][5];
	float sum = 0.0f;

	for (int i = -kernel_radius; i <= kernel_radius; i++) {
		for (int j = -kernel_radius; j <= kernel_radius; j++) {
			float dist = (i * i + j * j) / (2.0f * sigma * sigma);
			kernel[i + kernel_radius][j + kernel_radius] = expf(-dist);
			sum += kernel[i + kernel_radius][j + kernel_radius];
		}
	}

	for (int i = 0; i < kernel_size; i++) {
		for (int j = 0; j < kernel_size; j++) {
			kernel[i][j] /= sum;
		}
	}

	for (int y = 0; y < size; y++) {
		for (int x = 0; x < size; x++) {
			float value = 0.0f;
			for (int ky = -kernel_radius; ky <= kernel_radius; ky++) {
				for (int kx = -kernel_radius; kx <= kernel_radius; kx++) {
					int ny = y + ky;
					int nx = x + kx;
					if (ny < 0) ny = -ny;
					if (nx < 0) nx = -nx;
					if (ny >= size) ny = size - 1 - (ny - size + 1);
					if (nx >= size) nx = size - 1 - (nx - size + 1);
					if (ny < 0) ny = 0;
					if (nx < 0) nx = 0;
					if (ny >= size) ny = size - 1;
					if (nx >= size) nx = size - 1;

					value += input[ny][nx].height * kernel[ky + kernel_radius][kx + kernel_radius];
				}
			}
			output[y][x].height = value;
		}
	}
}