#include <stdlib.h>
#include <stdio.h>

void Scambia(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SubsetEqualRec(int n, int s, int* vcurr, int i, int last)
{
	if (i > n)
	{
		return;
	}

	if (s == 0)
	{
		// stampa
		printf("{ ");
		for (int j = 0; j < i; ++j)
		{
			printf("%i ", vcurr[j]);
		}
		printf("}, ");
	}
	else if (s < 0)
	{
		return;
	}

	for (int j = last + 1; j <= n; j++)
	{
		vcurr[i] = j;

		SubsetEqualRec(n, s - vcurr[i], vcurr, i + 1, j);
	}
}

void SubsetEqual(int n, int s)
{
	if (n > 0 && s > 0)
	{
		int* vcurr = malloc(sizeof(int) * n);
		/*for (int i = 1; i <= n; i++)
		{
			vcurr[i - 1] = i;
		}*/

		SubsetEqualRec(n, s, vcurr, 0, 0);

		free(vcurr);
	}
}