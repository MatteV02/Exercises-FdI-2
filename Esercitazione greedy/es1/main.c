#include <stdlib.h>

extern int* Monete(int* tagli, size_t tagli_size, int budget);

int main(void)
{
	int tagli[] = { 50,20,10,5,2,1 };
	int budget = 126;

	int* ret = Monete(tagli, sizeof(tagli) / sizeof(*tagli), budget);

	free(ret);

	return 0;
}