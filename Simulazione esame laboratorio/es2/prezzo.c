#include "prezzo.h"

#include <stdio.h>

void TrovaArticoliRec(const struct Articolo* a, size_t a_size, int sum, struct Articolo* vcurr, int sum_vcurr, size_t i, size_t j)
{
	if (i == a_size)
	{
		return;
	}

	for (size_t j_att = j; j_att < a_size; ++j_att)
	{
		vcurr[i] = a[j_att];
		sum_vcurr += vcurr[i].prezzo;

		if (sum_vcurr == sum)
		{
			for (size_t k = 0; k <= i; ++k) {
				printf("%s, ", vcurr[k].nome);
			}

			printf("\n");
		}

		TrovaArticoliRec(a, a_size, sum, vcurr, sum_vcurr, i + 1, j_att + 1);

		sum_vcurr -= vcurr[i].prezzo;
	}
}

void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum)
{
	struct Articolo* vcurr = malloc(sizeof(struct Articolo) * a_size);

	TrovaArticoliRec(a, a_size, sum, vcurr, 0, 0, 0);

	free(vcurr);
}