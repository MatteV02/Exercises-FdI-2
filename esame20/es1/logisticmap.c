#include <stdlib.h>
#include <stdio.h>

double MappaLogistica(double xn, double r, int n, int i)
{
	if (i == n)
	{
		return xn;
	}

	return MappaLogistica(r * xn * (1 - xn), r, n, i + 1);
}

int main(int argc, char* argv[])
{
	int ret = 1;

	if (argc == 4)
	{
		double x0 = strtod(argv[1], NULL),
			r = strtod(argv[2], NULL);
		int n = strtol(argv[3], NULL, 10);

		if ((x0 >= 0 && x0 <= 1) && r >= 0 && n >= 0) {
			ret = 0;

			double risultato = MappaLogistica(x0, r, n, 0);

			printf("%f", risultato);
		}

	}

	return ret;
}