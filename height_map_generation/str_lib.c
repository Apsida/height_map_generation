#include "str_lib.h"
#include <stdlib.h>
#include <string.h>

char* str_read() {
	char* str = malloc(sizeof(char) * 20);
	char c = getchar();
	int k = 0;
	if (c != '\n') {
		str[k] = c;
		k++;
	}
	for (int i = k; i < 20; i++) {
		c = getchar();
		str[i] = c;
		if (c == '\n' && i != 0) {
			str[i] = '\0';
			return str;
		}
	}
	return str;
}

int str_cmp(char* a, char* b) {
	int flag = 1;
	int j = 0;
	while (a[j] != '\0') {
		if (a[j] != b[j]) {
			flag = 0;
			break;
		}
		j++;
	}
	return flag;
}

int biome_check(Tile** map, int size, char* biome) {
	int k = 0;
	for (int y = 0; y < size; y++) {
		for (int x = 0;x < size;x++) {
			if (str_cmp(map[y][x].biome->name, biome)) {
				k++;
			}
		}
	}
	return k;
}