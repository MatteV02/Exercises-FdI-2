#include <stdlib.h>

extern void BabboNatale(const int* pacchi, size_t pacchi_size, int p);

int main(void)
{
	int p = 100;
	int pacchi[] = { 101, 200, 300 };

	BabboNatale(pacchi, sizeof(pacchi) / sizeof(int), p);

	return EXIT_SUCCESS;
}