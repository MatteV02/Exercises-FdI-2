#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

bool Controlla(const int* f, size_t f_size, int pos)
{
	for (size_t i = 0; i < f_size; i++)
	{
		if (f[i] == pos) {
			return false;
		}
	}

	return true;
}

static void GuidaLaPulceRec(const int* f, size_t f_size, int pos,  int a, bool prev_a, int b, int i, int n, int h, char* vcurr, char* ret, size_t* ret_size)
{
	if (i > n || i >= (int) *ret_size) {
		return;
	}

	if (pos == h) {
		memcpy(ret, vcurr, sizeof(char) * i);
		*ret_size = (size_t)i;
		return;
	}

	int temp_pos;
	
	temp_pos = pos + a;
	if (Controlla(f, f_size, temp_pos)) {
		vcurr[i] = 'a';
		GuidaLaPulceRec(f, f_size, temp_pos, a, true, b, i + 1, n, h, vcurr, ret, ret_size);
	}
	
	if (prev_a) {
		temp_pos = pos - b;
		if (Controlla(f, f_size, temp_pos)) {
			vcurr[i] = 'b';
			GuidaLaPulceRec(f, f_size, temp_pos, a, false, b, i + 1, n, h, vcurr, ret, ret_size);
		}
	}
}

char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size)
{
	char* ret = malloc(sizeof(char) * (n + 1)), 
		*vcurr = malloc(sizeof(char) * (n + 1));

	*ret_size = (size_t)n + 2;

	GuidaLaPulceRec(f, f_size, 0, a, true, b, 0, n, h, vcurr, ret, ret_size);

	free(vcurr);

	if (*ret_size == (size_t)n + 2) {
		free(ret);
		ret = NULL;
		*ret_size = 0;
	}
	else {
		ret = realloc(ret, sizeof(char) * *ret_size);
	}

	return ret;
}