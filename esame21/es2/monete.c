#include <stdlib.h>
#include <stdio.h>

void CombinaMoneteRec(int b, const int* m, size_t m_size, int moneta_precedente, int* vcurr, int vcurr_value, int *nsol)
{
	if (vcurr_value == b)
	{
		//stampa

		for (size_t j = 0; j < m_size; ++j)
		{
			printf("%i ", vcurr[j]);
		}
		printf("\n");

		++(*nsol);

		return;
	}

	if (vcurr_value > b)
	{
		return;
	}

	for (size_t j = moneta_precedente; j < m_size; ++j)
	{
		vcurr[j]++;
		vcurr_value += m[j];

		CombinaMoneteRec(b, m, m_size, j, vcurr, vcurr_value, nsol);

		vcurr[j]--;
		vcurr_value -= m[j];
	}
}

int CombinaMonete(int b, const int* m, size_t m_size)
{
	int n_sol = 0;

	int* vcurr = calloc(m_size, sizeof(int));

	CombinaMoneteRec(b, m, m_size, 0, vcurr, 0, &n_sol);

	free(vcurr);
	return n_sol;
}