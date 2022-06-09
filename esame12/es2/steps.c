#include <stdlib.h>
#include <stdio.h>

static void StepsRec(int n, int i, int* vcurr, int *n_soluzioni)
{
	if (n < 0)
	{
		return;
	}

	if (n == 0)
	{
		++(*n_soluzioni);

		if (*n_soluzioni != 1)
		{
			putchar(' ');
		}
		putchar('[');
		for (int j = 0; j < i; ++j)
		{
			if (j != 0) {
				printf(", ");
			}

			printf("%i", vcurr[j]);
		}
		printf("],");

		return;
	}

	for (int j = 1; j <= 3; ++j)
	{
		vcurr[i] = j;

		StepsRec(n - j, i + 1, vcurr, n_soluzioni);
	}
}

int Steps(int n)
{
	int n_soluzioni = 0;

	if (n > 0)
	{
		int* vcurr = malloc(sizeof(int) * n);

		StepsRec(n, 0, vcurr, &n_soluzioni);

		free(vcurr);
	}

	return n_soluzioni;
}