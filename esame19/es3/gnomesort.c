#include <stdlib.h>

static void Scambia(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void GnomeSort(int* v, size_t v_size)
{
	for (size_t i = 0; i < v_size; ++i)
	{
		if (i != 0 && v[i] < v[i - 1])
		{
			Scambia(v + i, v + i - 1);
			i -= 2;
		}
	}
}