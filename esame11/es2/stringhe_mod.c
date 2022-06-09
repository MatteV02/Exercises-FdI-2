#include <stdlib.h>
#include <stdio.h>

void BacktrackStrModRec(int n, int i, int k, char* vcurr)
{
	if (i == k) {
		vcurr[i] = 0;

		printf("{%s}, ", vcurr);

		return;
	}

	for (int j = 0; j < n; j++)
	{
		vcurr[i] = 'a' + j;
		BacktrackStrModRec(n, i + 1, k, vcurr);
	}
}

void BacktrackStrMod(int n, int k)
{
	if (n > 0 && n <= 26 && k > 0)
	{
		char* vcurr = malloc(sizeof(char) * (k + 1));

		BacktrackStrModRec(n, 0, k, vcurr);

		free(vcurr);
	}
}