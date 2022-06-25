#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

void scambia(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void TiroAllaFune(int* n, size_t n_l, size_t i, int* vcurr, int* best, int* best_diff, size_t prev, int s_totale)
{
	if (i == n_l / 2) {
		
		int s1 = 0;
		for (size_t j = 0; j < n_l/2; j++)
		{
			s1 += n[vcurr[j]];
		}

		int diff_attuale = abs(s_totale - 2 * s1);
		
		if (diff_attuale < *best_diff) {
			*best_diff = diff_attuale;
			memcpy(best, vcurr, sizeof(*vcurr) * n_l);
		}

		return;
	}

	for (size_t j = prev + 1; j < n_l; j++)
	{
		vcurr[i] = j;
		TiroAllaFune(n, n_l, i + 1, vcurr, best, best_diff, j, s_totale);
	}
}

int main(int argc, char* argv[])
{
	if (argc < 3) {
		printf("{ }, { }");

		return EXIT_FAILURE;
	}
	else {
		size_t n_l = argc - 1;
		int* n = malloc(sizeof(*n) * n_l);
		int s_totale = 0;
		for (size_t i = 0; i < n_l; i++) {
			n[i] = strtol(argv[i + 1], NULL, 10);
			s_totale += n[i];
		}

		int* vcurr = malloc(sizeof(*vcurr) * n_l / 2);

		int* best = malloc(sizeof(*best) * n_l);
		int best_diff = INT_MAX;

		TiroAllaFune(n, n_l, 0, vcurr, best, &best_diff, -1, s_totale);

		bool* presi = calloc(n_l, sizeof(bool));
		for (size_t i = 0; i < n_l/2; i++)
		{
			presi[best[i]] = true;
		}

		for (size_t i = 0; i < n_l; i++) {
			static size_t j = 0;
			if (presi[i] == false) {
				best[n_l / 2 + j] = i;
				j++;
			}
		}

		printf("{ %d", n[best[0]]);
		for (size_t i = 1; i < n_l/2; i++)
		{
			printf(", %d", n[best[i]]);
		}
		printf(" }, { %d", n[best[n_l / 2]]);
		for (size_t i = n_l / 2 + 1; i < n_l; ++i) {
			printf(", %d", n[best[i]]);
		}
		printf(" }");

		free(n);
		free(presi);
		free(vcurr);
		free(best);
		return EXIT_SUCCESS;
	}
}