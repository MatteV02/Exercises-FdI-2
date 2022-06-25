#include "torrecartoni.h"

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

static void scambia(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

static void TorreCartoniRec(const Cartone* c, size_t n, size_t i, unsigned int peso_attuale,
	unsigned int h_attuale, int* vcurr, int* best, unsigned int* best_h, size_t *best_l, bool* termina) 
{
	if (h_attuale > *best_h) {
		*best_h = h_attuale;
		memcpy(best, vcurr, sizeof(*vcurr) * n);
		*best_l = i;				// la stringa risposta è lunga i (cioè il numero di dati della soluzione controllati)
		
		if (i == n) {
			*termina = true;		// In questo caso la soluzione trovata sarà certamente la migliore
			return;
		}
	}
	
	for (size_t j = i; j < n; ++j) {
		scambia(vcurr + i, vcurr + j);
		if (peso_attuale < c[vcurr[i]].l) {
			TorreCartoniRec(c, n, i + 1, peso_attuale + c[vcurr[i]].p, 
				h_attuale + c[vcurr[i]].a, vcurr, best, best_h, best_l, termina);	// <-- CHIAMATA RICORSIVA

			if (*termina) {			// Termina la funzione nel caso particolare "è stata creata una pila con tutti i cartoni"
				return;
			}
		}
		scambia(vcurr + i, vcurr + j);
	}
}

void TorreCartoni(const Cartone* c, size_t n)
{
	int* vcurr = malloc(sizeof(int) * n);
	for (size_t i = 0; i < n; ++i) {
		vcurr[i] = i;
	}

	int* best = malloc(sizeof(int) * n);
	unsigned int best_h = 0;
	size_t best_l;

	bool termina = false;
	TorreCartoniRec(c, n, 0, 0, 0, vcurr, best, &best_h, &best_l, &termina);

	for (size_t i = 0; i < best_l; i++) {		// <-- STAMPA
		printf("%d\n", best[i]);
	}
	printf("Altezza: %d cm", best_h);

	free(vcurr);		// <-- DISTRUGGI
	free(best);
}