#define CONSUMI 0.05
#define SERBATOIO 30

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <float.h>

static void StazioniServizioRec(double m, const double* d, const double* p, size_t n, size_t i, double benz_rimasta, double prezzo_attuale, bool* vcurr, bool* best, double* best_prezzo, size_t *best_l) 
{
	if (prezzo_attuale > *best_prezzo) {
		return;
	}

	if (m * CONSUMI < benz_rimasta) {
		*best_prezzo = prezzo_attuale;
		*best_l = i;
		for (size_t j = i; j < n; ++j) {
			vcurr[i] = false;
		}
		memcpy(best, vcurr, n * sizeof(*vcurr));
		return;
	}

	if (i == n) {
		return;			// si entra qui solo se il prezzo attuale è conveniente ma non c'è abbastanza benza per arrivare a destinazione --> scarta la soluzione
	}

	benz_rimasta -= d[i] * CONSUMI;
	if (benz_rimasta < 0) {
		return;
	}

	vcurr[i] = false;
	StazioniServizioRec(m - d[i], d, p, n, i + 1, benz_rimasta, prezzo_attuale, vcurr, best, best_prezzo, best_l);

	vcurr[i] = true;
	StazioniServizioRec(m - d[i], d, p, n, i + 1, SERBATOIO, prezzo_attuale + (SERBATOIO - benz_rimasta) * p[i], vcurr, best, best_prezzo, best_l);

}

void StazioniServizio(double m /* DISTANZA DA PERCORRERE */, 
	const double* d /* VETTORE DELLE DISTANZE */, 
	const double* p /*VETTORI DEI PREZZI DEL CARBURANTE PRESSO LE STAZIONI DI SERVIZIO*/, 
	size_t n /* NUMERO STAZIONI DI SERVIZIO */)
{
	bool* vcurr = malloc(sizeof(bool) * n);

	bool* best = malloc(sizeof(bool) * n);
	double best_prezzo = DBL_MAX;
	size_t best_l;

	StazioniServizioRec(m, d, p, n, 0, SERBATOIO, 0, vcurr, best, &best_prezzo, &best_l);

	if (best_prezzo == DBL_MAX) {
		printf("Non esistono soluzioni");
	}
	else {
		for (size_t i = 0; i < best_l; ++i) {
			if (best[i]) {
				printf("%zu ", i);
			}
		}
		printf("\nSpesa totale: %f", best_prezzo);
	}

	free(vcurr);
	free(best);
}