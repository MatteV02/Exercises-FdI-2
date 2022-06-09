#include <stdlib.h>
#include <stdio.h>

int RadiceNumerica(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return n % 10 + RadiceNumerica(n / 10);
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
			int radice = n;
			do {
				radice = RadiceNumerica(radice);
			} while (radice / 10 != 0);
			printf("%i", radice);
		}
	}

	return ret;
}