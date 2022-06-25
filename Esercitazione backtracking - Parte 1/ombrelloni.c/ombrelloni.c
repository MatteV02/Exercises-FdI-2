#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void OmbrelloniRec(int k, int n, int i, bool vsol[], int* nsol, bool prec, int k_att) {

	if (k_att == k) {
		++(*nsol);

		printf("%4d)", *nsol);

		for (int j = 0; j < i; ++j) {
			if (vsol[j]) {
				printf(" 1");
			}
			else {
				printf(" 0");
			}
		}

		for (int j = i; j < n; ++j) { 
			printf(" 0");
			
		}

		putchar('\n');

		return;
	}
	
	if (k-k_att > n-i) {
		return;
	}

	if (prec == false) {
		vsol[i] = true;
		OmbrelloniRec(k, n, i + 1, vsol, nsol, true, k_att + 1);
	}

	vsol[i] = false;
	OmbrelloniRec(k, n, i + 1, vsol, nsol, false, k_att);

}

int Ombrelloni(int k, int n) {
	if (k < 0 || n < 0 || k > n / 2) {
		return 0;
	}

	int nsol = 0;
	bool* vsol = malloc(sizeof(bool) * n);

	OmbrelloniRec(k, n, 0, vsol, &nsol, false, 0);

	free(vsol);

	return nsol;
}