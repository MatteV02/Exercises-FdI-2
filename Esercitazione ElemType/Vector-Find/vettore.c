#include "vettore.h"

void VectorBinarySearch(const Vector* v, const ElemType* e, int start, int end, int* pos)
{
	if (start <= end) {
		int pivot = (start + end) / 2;
		int compare = ElemCompare(v->data + pivot, e);

		if (compare == 0)
		{
			if (*pos == -1 || pivot <= *pos) {
				*pos = pivot;
			}
		}
		
		if (compare >= 0)
		{
			VectorBinarySearch(v, e, start, pivot - 1, pos);
		}
		else
		{
			VectorBinarySearch(v, e, pivot + 1, end, pos);
		}
	}
}

int VectorFind(const Vector* v, const ElemType* e)
{
	int pos = -1;
	if (v != NULL && e != NULL) {
		
		VectorBinarySearch(v, e, 0, v->size - 1, &pos);

	}

	return pos;
}