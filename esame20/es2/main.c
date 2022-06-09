#include <stdlib.h>

int TempoTrasporto(int n, const int* t, int p);

int main(void)
{
	int tempo = TempoTrasporto(4, (int[]) { 3, 2, 4 }, 5);

	return 0;
}