#include <stdlib.h>

extern char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size);

int main(void)
{
	int f[] = { 8, 3, 16, 6, 12, 20 };

	size_t ret_size;
	char* ret = GuidaLaPulce(f, sizeof(f) / sizeof(*f), 15, 13, 5, 11, &ret_size);

	free(ret);

	return 0;
}