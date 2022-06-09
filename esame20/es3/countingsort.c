#include <stdlib.h>

static void TrovaMinMax(const int* v, size_t v_size, int* min, int* max)
{
	*min = *v;
	*max = *v;
	for (size_t i = 1; i < v_size; ++i)
	{
		if (v[i] < *min)
		{
			*min = v[i];
		}
		else if (v[i] > *max)
		{
			*max = v[i];
		}
	}
}

void CountingSort(int* v, size_t v_size)
{
	if (v == NULL)
	{
		return;
	}

	int min, max;
	TrovaMinMax(v, v_size, &min, &max);

	size_t count_size = abs(max - min) + 1;
	int* count = calloc(count_size, sizeof(int));

	for (size_t i = 0; i < v_size; i++)
	{
		++count[v[i] - min];
	}

	for (size_t count_i = 0, v_i = 0; count_i < count_size; ++count_i)
	{
		for (int j = 0; j < count[count_i]; ++j)
		{
			v[v_i] = min + count_i;
			++v_i;
		}
	}

	free(count);
}