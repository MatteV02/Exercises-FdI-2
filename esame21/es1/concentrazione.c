#include <stdlib.h>
#include <stdio.h>

double Concentrazione(int n, int i, double c_n)
{
	if (i + 1 == n)
	{
		return c_n;
	}

	return Concentrazione(n, i+1, 0.3 * c_n + 0.2);
}

int main(int argc, char*argv[])
{
	int ret = 1;

	if (argc == 2)
	{
		int n = strtol(argv[1], NULL, 10);

		if (n >= 1)
		{
			ret = 0;

			double risultato = Concentrazione(n, 0, 0);

			printf("%f", risultato);
		}
	}

	return ret;
}