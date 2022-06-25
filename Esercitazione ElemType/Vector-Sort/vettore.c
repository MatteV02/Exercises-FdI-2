#include "vettore.h"

#include <string.h>

static void VectorQuickSort(Vector* v, int start, int end)
{
	if (start < end) {
	ElemType pivot = v->data[(start + end) / 2];
	int i = start, j = end;

		do {
			while (ElemCompare(v->data + i, &pivot) < 0) ++i;
			while (ElemCompare(v->data + j, &pivot) > 0) --j;

			if (i <= j) {
				ElemSwap(v->data + i, v->data + j);
				++i; --j;
			}
		} while (i <= j);

		VectorQuickSort(v, start, j);
		VectorQuickSort(v, i, end);
	}
}

void VectorSort(Vector* v)
{
	if (v != NULL) {

		VectorQuickSort(v, 0, v->size - 1);

	}
}