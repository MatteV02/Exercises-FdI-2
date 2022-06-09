#include <stdlib.h>
#include <stdbool.h>

static void Scambia(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void CocktailSort(int* v, size_t v_size)
{
	if (v == NULL || v_size == 0)
		return;

	bool done;

	size_t start = 0, end = v_size - 1;

	while (1)
	{
		done = true;
		for (size_t i = start; i < end; ++i)
		{
			if (v[i] > v[i + 1]) {
				done = false;
				Scambia(v + i, v + i + 1);
			}
		}

		--end;
		if (done || end <= start) {
			break;
		}

		done = true;
		for (size_t i = end; i > start; --i)
		{
			if (v[i] < v[i - 1]) {
				done = false;
				Scambia(v + i, v + i - 1);
			}
		}

		++start;
		if (done || end <= start) {
			break;
		}
	}
}