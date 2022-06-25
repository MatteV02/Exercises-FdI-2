#include <stdlib.h>
#include <limits.h>

int Minimo(const int* v, int v_size)
{
	int elem;

	if (v_size > 1)
	{
		elem = Minimo(v + 1, v_size - 1);
	}
	else
	{
		return *v;
	}

	if (*v > elem)
	{
		return elem;
	}
	else
	{
		return *v;
	}

}

static int MinimoTailRet(const int *v, int v_size, int min) {
	if (v_size > 0) {
		if (*v < min) {
			min = *v;
		}
		return MinimoTailRet(v + 1, v_size - 1, min);
	}

	return min;
}

int MinimoTail(const int* v, int v_size) {
	if (v == NULL || v_size < 1) {
		return INT_MIN;
	}
	
	return MinimoTailRet(v + 1, v_size - 1, *v);
}