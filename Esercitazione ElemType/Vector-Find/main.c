#include <stdlib.h>
#include <string.h>

#define N_ELEM 25
#define TO_FIND 3

#include "vettore.h"

int main(void)
{
	Vector* v = malloc(sizeof(Vector));
	memcpy(
		v,
		&(Vector) {10, 10, NULL},
		sizeof(Vector)
	);
	
	v->data = malloc(N_ELEM * sizeof(ElemType));
	memcpy(
		v->data,
		(ElemType[]) { -12, -4, 3, 3, 3, 3, 4, 5, 6, 6, 7, 8, 34, 34, 54, 56, 234, 346, 367, 435, 1233, 3453, 3456, 4567, 5667 },
		N_ELEM * sizeof(ElemType)
	);

	int pos = VectorFind(v, &(ElemType) {TO_FIND});

	free(v->data);
	free(v);

	return EXIT_SUCCESS;
}