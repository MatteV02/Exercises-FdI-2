#include <stdlib.h>
#include <stdio.h>

long long Catalan(long long n)
{
	if (n == 0)
	{
		return 1;
	}

	long long ret = 0;

	for (long long i = 0; i <= n - 1; i++)
	{
		ret += Catalan(i) * Catalan(n - 1 - i);
	}

	return ret;
}

int main(int argc, char *argv[])
{
	int ret = 1;

	if (argc == 2)
	{
		long long n = strtoll(argv[1], NULL, 10);

		if (n >= 0)
		{
			ret = 0;

			long long risultato = Catalan(n);

			printf("%lli", risultato);
		}
	}

	return ret;
}