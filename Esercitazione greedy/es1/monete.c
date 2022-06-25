#include <stdlib.h>

int* Monete(int* tagli, size_t tagli_size, int budget)
{
	int* ret = NULL;

	if (budget > 0) {

		ret = calloc(tagli_size, sizeof(int));

		for (size_t i = 0; i < tagli_size && budget > 0; ++i) {
			
			ret[i] = budget / tagli[i];
			budget = budget % tagli[i];
			
		}

	}

	return ret;
}

