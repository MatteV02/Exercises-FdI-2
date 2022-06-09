#include "colora.h"

#include <stdio.h>

#define el(m, i, j) m->data[i*m->size + j]

static bool PossoAssegnare(char c_att, size_t i, const char* vcurr, const struct Matrix* m)
{
	for (size_t j = 0; j + 1 <= i; ++j)
	{
		if (el(m, i, j) == true && vcurr[j] == c_att) {
			return false;
		}
	}

	return true;
}

static void MappaColoriRec(const struct Matrix* m, const char* c, size_t c_size, size_t i, char* vcurr, int *nsol)
{
	if (i == m->size) {

		if (*nsol != 0) {
			putchar('\n');
		}
		for (size_t j = 0; j < m->size; ++j)
		{
			printf("%zu -> %c; ", j, vcurr[j]);
		}

		++(*nsol);
		return;
	}

	for (size_t i_c = 0; i_c < c_size; ++i_c) {
		if (PossoAssegnare(c[i_c], i, vcurr, m))	// posso assegnare il colore c[i_c] all'area i
		{
			vcurr[i] = c[i_c];
			MappaColoriRec(m, c, c_size, i + 1, vcurr, nsol);
		}
	}
}

int MappaColori(const struct Matrix* m, const char* c, size_t c_size)
{
	int nsol = 0;

	if (m != NULL) {
		char* vcurr = malloc(m->size);

		MappaColoriRec(m, c, c_size, 0, vcurr, &nsol);

		free(vcurr);
	}

	return nsol;
}