#pragma once
void diamond_step (float** map, int size, int step, float scale);
void square_step (float** map, int size, int step, float scale);
void ds_gen_height_map (float** map, int size, float roughness);
void apply_gaussian_filter(float** input, float** output, int size, float bloom);