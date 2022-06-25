#include <stdlib.h>

int ProdottoNegativiRec(int a, int b, int ret)
{
	if (b > 0) {
		return ProdottoNegativiRec(a, b - 1, ret + a);
	}

	return ret;
}

int ProdottoNegativi(int a, int b)
{
	if ((a>0) ^ (b>0))
	{
		return -ProdottoNegativiRec(abs(a), abs(b), 0);
	}
	else
	{
		return ProdottoNegativiRec(abs(a), abs(b), 0);
	}
}