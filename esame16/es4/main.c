#include <stdlib.h>

extern void PancakeSort(int* v, size_t v_size);

int main(void)
{
	int v[] = { 3,2,5,6,8,9,7 };

	PancakeSort(v, sizeof(v) / sizeof(*v));

	return 0;
}