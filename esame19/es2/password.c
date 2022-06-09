#include <stdlib.h>
#include <stdio.h>

void PasswordRec(const char* str, int n, int i, char* vcurr, int* n_sol)
{
	if (i == n)
	{
		vcurr[i] = 0;

		printf("%s\n", vcurr);

		++(*n_sol);
		return;
	}

	for (const char* j = str; *j != 0; ++j)
	{
		vcurr[i] = *j;

		PasswordRec(str, n, i + 1, vcurr, n_sol);
	}
}

int Password(const char* str, int n)
{
	int n_sol = 0;

	if (str != NULL) {
		char* vcurr = malloc(sizeof(char) * (n + 1));

		PasswordRec(str, n, 0, vcurr, &n_sol);

		free(vcurr);
	}
	return n_sol;
}