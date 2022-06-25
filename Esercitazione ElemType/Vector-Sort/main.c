#include <stdlib.h>
#include <string.h>

#include "vettore.h"

#define V_L 10

static void VectorPushBackInt(Vector* v, int el)
{
	if (v->capacity == v->size) {
		v->capacity *= 2;
		v->data = realloc(v->data, sizeof(ElemType) * v->capacity);
	}

	v->data[v->size] = el;
	++(v->size);
}

int main(void)
{
	/*
	srand(2);

	Vector* v = malloc(sizeof(Vector));
	v->capacity = 1;
	v->size = 0;
	v->data = malloc(sizeof(ElemType));
	
	for (size_t i = 0; i < V_L; ++i) {
		VectorPushBackInt(v, rand() % (2*V_L));
	}

	*/

	Vector* v = memcpy(
		malloc(sizeof(Vector)),
		&(Vector) {
			13, 13, 
				memcpy(
					malloc(13 * sizeof(ElemType)),
					(ElemType[]) {
						1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 15, 18, 20
					},
						13 * sizeof(ElemType)
				)
		},
		sizeof(Vector)
	);

	VectorSort(v);

	free(v->data);
	free(v);

	return EXIT_SUCCESS;
}