#include <stdlib.h>
#include <stdio.h>

#define N_ELEM 10

extern int Minimo(const int* v, int v_size);
extern int MinimoTail(const int* v, int v_size);

int main(void)
{
	int v[N_ELEM];

	for (size_t i = 0; i < N_ELEM; i++) {
		v[N_ELEM - 1 - i] = i + 1;
	}
	v[4] = 0;

	int ret = MinimoTail(v, N_ELEM);
	printf("%d", ret);

	return 0;
}