#include <stdlib.h>
#include <stdio.h>

int Hailstone(int n)
{
	
	if (n == 1) {
		printf("1");
		return 1;
	}
	else {
		printf("%i, ", n);
	}

	if (n % 2 == 0)
	{
		n /= 2;
	}
	else {
		n = 3 * n + 1;
	}

	return 1 + Hailstone(n);
}

int main(int argc, char* argv[])
{
	int ret = -1;
	
	if (argc == 2) {
		ret = 0;

		int n = strtol(argv[1], NULL, 10);

		if (n > 0)
		{
			ret = Hailstone(n);
		}
	}

	return ret;
}