#include <stdlib.h>

static int AToI_rec(const char* str, int* pow10)
{
	if (*str != 0) {
		int parz = AToI_rec(str + 1, pow10);

		if (*pow10 == 0) {
			*pow10 = 1;
		}
		else {
			*pow10 *= 10;
		}

		return (*str - '0') * *pow10 + parz;
	}
	else {
		return 0;
	}
}

int AToI(const char* str)
{
	if (str == NULL) {
		return 0;
	}
	int pow10 = 0;

	return AToI_rec(str, &pow10);
}