#include <stdlib.h>

extern int CombinaMonete(int b, const int* m, size_t m_size);

int main(void)
{
	int ret = CombinaMonete(4, (int[]) { 1, 2, 50, 10, 5, 20 }, 6);

	return 0;
}