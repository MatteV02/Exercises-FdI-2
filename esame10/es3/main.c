#include <stdlib.h>

extern void InsertionSort(int* v, size_t v_size);

int main(void)
{
	InsertionSort((int[]) { 5, 3, 7, 9, 8, 1 }, 6);

	return 0;
}