#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void ParoleT9Rec(const char* str, int i, char* vcurr, int* n_sol, const char ** t9)
{
	int c = (int)str[i];
	if (c == 0) {
		++(*n_sol);

		vcurr[i] = 0;

		printf("%s\n", vcurr);

		return;
	}

	c -= '2';

	for (int j = 0; t9[c][j] != 0; ++j)
	{
		vcurr[i] = t9[c][j];

		ParoleT9Rec(str, i + 1, vcurr, n_sol, t9);
	}
}

int ParoleT9(const char* str)
{
	int n_sol = 0;

	if (str != NULL)
	{
		const char* t9[] = {
			"ABC",
			"DEF",
			"GHI",
			"JKL",
			"MNO",
			"PQRS",
			"TUV",
			"WXYZ"
		};

		char* vcurr = malloc(sizeof(char) * (strlen(str) + 1));

		ParoleT9Rec(str, 0, vcurr, &n_sol, t9);

		free(vcurr);
	}

	return n_sol;
}