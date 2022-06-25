#include <stdlib.h>
#include <limits.h>

int DivisioneNegativiRec(int a, int b, int ret) 
{
	if (a >= b) {
		return DivisioneNegativiRec(a - b, b, ret + 1);
	}

	return ret;
}

int DivisioneNegativi(int a, int b)
{
	if (b == 0) {
		return INT_MAX;
	}
	if ((a>0) ^ (b>0))
	{
		return -DivisioneNegativiRec(abs(a), abs(b), 0);
	}
	else {
		return DivisioneNegativiRec(abs(a), abs(b), 0);
	}
}