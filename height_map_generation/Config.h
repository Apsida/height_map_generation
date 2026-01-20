#pragma once
#include <stdlib.h>

typedef struct Object {
	int id;
	char* name;
	float probability;
}Obj;

int obj_count;

//Obj* sea = (Obj*)malloc(sizeof(Obj*));
//sea->id=-1; //??????
//
//
//void** list_obj{
//}