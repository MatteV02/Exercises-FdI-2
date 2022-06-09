#include <stdlib.h>

void InsertionSort(int* v, size_t v_size)
{
	for (size_t i = 1; i < v_size; ++i) {
		int el = v[i];

		size_t j;
		for (j = i - 1; j + 1 > 0 && v[j] > el; --j) {
			v[j + 1] = v[j];
		}

		v[j + 1] = el;
	}
}