#include "gioielli.h"

#include <stdio.h>
#include <stdint.h>

#if defined _DEBUG & WIN32
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif // defined DEBUG & WIN32

int CompGioielli(const Gioiello* a, const Gioiello* b) {
	return (a->peso / a->prezzo > b->peso / b->prezzo) - (a->peso / a->prezzo < b->peso / b->prezzo);
}

static Gioiello* LeggiGioielli(const char* filename, size_t* ret_size) 
{
	Gioiello* ret = NULL;
	size_t ret_capacity = 0;
	FILE* f = fopen(filename, "rt");
	
	if (f != NULL) {

		while (1) {
			Gioiello temp;
			int ret_fscanf = fscanf(f, "%i %g %g", &temp.codice, &temp.peso, &temp.prezzo);

			if (ret_fscanf != 3) {
				break;
			}

			if (*ret_size >= ret_capacity) {
				if (ret_capacity == 0) {
					ret_capacity = 1;
					ret = malloc(sizeof(Gioiello));
				}
				else {
					ret_capacity *= 2;
					ret = realloc(ret, ret_capacity * sizeof(Gioiello));
				}
			}

			(*ret_size)++;
			ret[*ret_size - 1] = temp;
		}

		ret = realloc(ret, *ret_size * sizeof(Gioiello));

		fclose(f);
	}
	
	return ret;
}

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size)
{
	size_t gioielli_size = 0;
	Gioiello* gioielli = LeggiGioielli(filename, &gioielli_size), *ret = NULL;
	
	
	if (gioielli != NULL) {
		ret = malloc(gioielli_size * sizeof(Gioiello));
		
		qsort(gioielli, gioielli_size, sizeof(Gioiello), CompGioielli);

		*ret_size = 0;
		for (size_t i = 0; i < gioielli_size; ++i) {
			if (budget >= gioielli[i].prezzo) {
				ret[*ret_size] = gioielli[i];
				budget -= gioielli[i].prezzo;
				(*ret_size)++;
			}
		}

		ret = realloc(ret, *ret_size * sizeof(Gioiello));

	}

	free(gioielli);
	return ret;
}