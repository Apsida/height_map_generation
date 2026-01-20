#include "UI.h"
#include <stdio.h>
#include <stdlib.h>

int MAX_LEN_NAME = 20;

char** receive_biome_list() {
	int n;
	printf("Input count of objects");
	scanf_s("%d", &n);
	char** biome_list = malloc(n * sizeof(char*));
	for (int i = 0; i < n; i++) {
		biome_list[i] = malloc(MAX_LEN_NAME * sizeof(char));
	}
}

Obj* receive_obj_list() {
	int n;
	printf("Input count of objects");
	scanf_s("%d", &n);
	Obj* obj_list = malloc(n * sizeof(Obj));
	printf("Input parametres of object: name, popability of spawn");
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
		float f;
		scanf_s("%f", &f);
		ob.probability = f;
	}
}

//char biome_list[][20] = {
//	"sea", "sand", "field", "forest", "mountain"
//};