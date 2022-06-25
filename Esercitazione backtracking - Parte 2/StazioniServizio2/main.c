#include <stdlib.h>

extern void StazioniServizio(double m, const double* d, const double* p, size_t n);

int main(void)
{
	double d[] = { 260,284,308,332,356 };
	double p[] = { 35,35,33,29,23 };

	StazioniServizio(1540, d, p, sizeof(d) / sizeof(*d));

	return EXIT_SUCCESS;
}