#include <stdlib.h>

int TempoTrasporto(int n, const int* t, int p)
{
	int tempo = 0;

	int* citta = calloc(n, sizeof(int));
	citta[0] = p;

	while (citta[n-1] != p)
	{
		for (int i = n - 2; i >= 0; --i)
		{
			if (citta[i] > 0)
			{
				int persone_spostate = (t[i] <= citta[i]) ? t[i] : citta[i];
				
				citta[i + 1] += persone_spostate;
				citta[i] -= persone_spostate;

			}
		}

		++tempo;
	}

	free(citta);
	return tempo;
}