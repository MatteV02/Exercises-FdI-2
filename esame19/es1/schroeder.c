#include <stdlib.h>
#include <stdio.h>

int Schroeder(int n)
{
	if (n == 0)
	{
		return 1;
	}

	if (n == 1)
	{
		return 2;
	}

	int s_1 = ((6 * n - 3) * Schroeder(n - 1)) / (n + 1);
	int s_2 = ((n - 2) * Schroeder(n - 2)) / (n + 1);

	return s_1 - s_2;
}

int main(int argc, char* argv[])
{
	int ret = 1;

	if (argc == 2)
	{
		int n = strtol(argv[1], NULL, 10);

		if (n >= 0)
		{
			ret = 0;

			int risultato = Schroeder(n);

			printf("%i", risultato);
		}
	}

	return ret;
}