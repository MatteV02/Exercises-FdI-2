#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static bool Controlla(const char* r, int* vcurr, int n)
{
	bool ret = true;

	// Controllo che non ci siano numeri ripetuti in vcurr
	bool* occur = calloc(n + 1, sizeof(bool));

	// Controllo la regola r
	for (int i = 0; i <= n; ++i) {
		if (ret == false) {
			break;
		}

		if (occur[vcurr[i] - 1]) {
			ret = false;
		}
		occur[vcurr[i] - 1] = true;

		if (i < n) {
			switch (r[i])
			{
			case 'i': case 'I':
				if (vcurr[i + 1] <= vcurr[i]) {
					ret = false;
				}
				break;

			case 'd': case 'D':
				if (vcurr[i + 1] >= vcurr[i]) {
					ret = false;
				}
				break;

			default:
				break;
			}
		}
	}

	free(occur);
	return ret;
}

static void RegoleRec(const char* r, int n, int i, int* vcurr) 
{
	if (i > n) {
		if (Controlla(r, vcurr, n)) {
			for (int j = 0; j < n + 1; ++j)
			{
				printf("%d ", vcurr[j]);
			}

			putchar('\n');
		}
		return;
	}

	for (int j = 1; j <= n + 1; ++j) {
		vcurr[i] = j;

		RegoleRec(r, n, i + 1, vcurr);
	}
}

void Regole(const char* r)
{
	int n = strlen(r);
	int* vcurr = malloc((n + 1)*sizeof(*vcurr));

	RegoleRec(r, n, 0, vcurr);

	free(vcurr);
}