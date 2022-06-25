#include "sciatori.h"

#include <math.h>		// fabs
#include <stdbool.h>	// bool
#include <stdint.h>		// dimensioni
#include <string.h>		// memcpy, memmove

int ConfrontaDouble(const double* a, const double* b) {
	if (*a < *b) return -1;
	if (*a > *b) return 1;
	return 0;
}

static size_t TrovaMinElementiMaggiori(double* v, size_t start, size_t end, double el)
{
	if (end != start) {
		size_t mid = (start + end) / 2;
		if (v[mid] == el) {
			return mid;
		}
		else if (v[mid] > el) {

			return TrovaMinElementiMaggiori(v, start, mid, el);
		}
		else {
			return TrovaMinElementiMaggiori(v, mid + 1, end, el);
		}
	}
	else {
		return start;
	}

}

Sciatore* Accoppia(double* altezze, double* lunghezze, size_t v_size)
{	
	Sciatore* ret = NULL;

	if (v_size != 0 && altezze != NULL && lunghezze != NULL)
	{
		ret = malloc(sizeof(Sciatore) * v_size);
		double* lunghezze_copia = memcpy(malloc(sizeof(double) * v_size), lunghezze, sizeof(double) * v_size);
		size_t lunghezze_copia_size = v_size;


		qsort(lunghezze_copia, v_size, sizeof(double), ConfrontaDouble);

		for (size_t i = 0; i < v_size; i++)
		{
			size_t j = TrovaMinElementiMaggiori(lunghezze_copia, 0, lunghezze_copia_size - 1, altezze[i]);

			
			if (j > 0 && fabs(lunghezze_copia[j - 1] - altezze[i]) < fabs(lunghezze_copia[j] - altezze[i])) {
					j = j - 1; 
			}

			ret[i] = (Sciatore){ altezze[i], lunghezze_copia[j] };

			memmove(lunghezze_copia + j, lunghezze_copia + j + 1, sizeof(*lunghezze_copia) * (lunghezze_copia_size - (j + 1))); // rimuovibile utilizzando una lista
			--lunghezze_copia_size;	
		}

		free(lunghezze_copia);

	}
	
	return ret;
}