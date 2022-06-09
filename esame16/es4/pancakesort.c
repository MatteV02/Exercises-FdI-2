#include <stdlib.h>

static size_t TrovaMax(const int* v, size_t start, size_t end)
{
	size_t max = start;
	for (size_t i = start + 1; i <= end; i++)
	{
		if (v[i] > v[max])
		{
			max = i;
		}
	}

	return max;
}

static void Flip(int* v, size_t i)
{
	for (size_t j = 0; j < i; j++, i--)
	{
		int temp = v[i];
		v[i] = v[j];
		v[j] = temp;
	}
}

void PancakeSort(int* v, size_t v_size)
{
	size_t curr_size = v_size;
	
	while (curr_size > 1) {
		size_t max = TrovaMax(v, 0, curr_size - 1);

		Flip(v, max);

		Flip(v, curr_size - 1);

		--curr_size;
	}
}