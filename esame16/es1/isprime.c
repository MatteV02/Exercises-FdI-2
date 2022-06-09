#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

static bool IsPrimeRec(int n, int i)
{
	if (i > sqrt(n)) {
		return true;
	}

	if (n % i == 0) {
		return false;
	}

	return IsPrimeRec(n, i + 1);
}

int main(int argc, char* argv[])
{
	int ret = 1;
	if (argc == 2) {
		int n = strtol(argv[1], NULL, 10);

		if (n >= 0) {
			if (n != 0 && n != 1 && IsPrimeRec(n, 2)) {
				printf("true");
			}
			else {
				printf("false");
			}

			ret = 0;
		}
	}

	return ret;
}