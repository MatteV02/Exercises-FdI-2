#include "torrecartoni.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static void TorreCartoniRec(const Cartone* c, size_t n, size_t i, int* vcurr, unsigned int peso_attuale, unsigned int h_parz, bool *pacchi_presi, int *best, unsigned int *best_h, unsigned int *h_max)
{	
	if (i == n) {
		if (h_parz >= *best_h) {
			for (size_t j = i; j < n; j++) {
				vcurr[j] = -1;
			}
			*best_h = h_parz;
			memcpy(best, vcurr, n * sizeof(int));
			if (*best_h == *h_max) {
				*h_max = 0;
				return;
			}
		}
		return;
	}

	bool presi = false;

	for (size_t j = 0; j < n; j++) {
		if (*h_max == 0) {		// se h_max == 0 allora chiudi (uso h_max per fare pruning di situazioni particolari)
			return;
		}
		if (pacchi_presi[j] == false) {
			if (peso_attuale <= c[j].l) {		// alziamo la struttura solo se il tutto regge
				presi = true;
				pacchi_presi[j] = true;
				vcurr[i] = j;
				TorreCartoniRec(c, n, i + 1, vcurr, peso_attuale + c[j].p, h_parz + c[j].a, pacchi_presi, best, best_h, h_max);
				pacchi_presi[j] = false;	// ripristino
			}

		}
	}

	if (presi == false) {
		TorreCartoniRec(c, n, n, vcurr, peso_attuale, h_parz, pacchi_presi, best, best_h, h_max);
	}
	
}

void TorreCartoni(const Cartone* c, size_t n)
{
	int* vcurr = malloc((n) * sizeof(int));
	memset(vcurr, -1, n * sizeof(int));

	bool* pacchi_presi = calloc(n, sizeof(bool));

	int* best = malloc(n * sizeof(int));
	unsigned int best_h = 0;

	unsigned int h_max = 0;
	for (size_t i = 0; i < n; i++) {
		h_max += c[i].a;
	}

	TorreCartoniRec(c, n, 0, vcurr, 0, 0, pacchi_presi, best, &best_h, &h_max);

	for (size_t i = 0; i < n; ++i) {
		if (best[i] != -1) {
			printf("%i\n", best[i]);
		}
	}

	printf("Altezza: %icm", best_h);

	free(vcurr);
	free(pacchi_presi);
	free(best);
}