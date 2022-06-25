#define CONSUMI 0.05
#define SERBATOIO 30

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <float.h>

static void StazioniServizioRec(double m, const double* d, const double* p, size_t n, size_t i, double benz_rimasta, double prezzo_attuale, int* vcurr, int* best, double* best_prezzo, size_t* best_l, int prec)
{
	if (prezzo_attuale > *best_prezzo) {
		return;
	}

	if (m * CONSUMI < benz_rimasta) {
		*best_prezzo = prezzo_attuale;
		*best_l = i;
		memcpy(best, vcurr, n * sizeof(*vcurr));
		return;
	}

	if (i == n) {
		return;			// si entra qui solo se il prezzo attuale è conveniente ma non c'è abbastanza benza per arrivare a destinazione --> scarta la soluzione
	}

	for (int j = prec + 1; j < (int)n; j++)
	{
		benz_rimasta -= d[j] * CONSUMI;
		m -= d[j];
		if (benz_rimasta > 0)	// riesco ad arrivare alla j-esima stazione di servizio
		{
			vcurr[i] = j;
			StazioniServizioRec(m, d, p, n, i + 1, SERBATOIO, prezzo_attuale + (SERBATOIO - benz_rimasta) * p[j], vcurr, best, best_prezzo, best_l, j);
		}
		else {
			return;
		}
	}
}

void StazioniServizio(double m /* DISTANZA DA PERCORRERE */,
	const double* d /* VETTORE DELLE DISTANZE */,
	const double* p /*VETTORI DEI PREZZI DEL CARBURANTE PRESSO LE STAZIONI DI SERVIZIO*/,
	size_t n /* NUMERO STAZIONI DI SERVIZIO */)
{
	int* vcurr = malloc(sizeof(*vcurr) * n);
	memset(vcurr, -1, sizeof(*vcurr) * n);

	int* best = malloc(sizeof(*best) * n);
	double best_prezzo = DBL_MAX;
	size_t best_l;

	StazioniServizioRec(m, d, p, n, 0, SERBATOIO, 0, vcurr, best, &best_prezzo, &best_l, -1);

	if (best_prezzo == DBL_MAX) {
		printf("Non esistono soluzioni");
	}
	else {
		for (size_t i = 0; i < best_l; ++i) {
			printf("%i ", best[i]);
		}
		printf("\nSpesa totale: %f", best_prezzo);
	}

	free(vcurr);
	free(best);
}