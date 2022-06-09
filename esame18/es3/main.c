#include <stdlib.h>

extern void CocktailSort(int* v, size_t v_size);

int main(void)
{
	int v[] = { 10, 3, 7, 1, 0, 34 };

	CocktailSort(v, sizeof(v) / sizeof(*v));

	return 0;
}