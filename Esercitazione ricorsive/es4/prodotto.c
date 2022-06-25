int ProdottoRec(int a, int b, int ret)
{
	if (b > 0) {
		return ProdottoRec(a, b - 1, ret + a);
	}

	return ret;
}

int Prodotto(int a, int b)
{
	if (a < 0 || b < 0)
	{
		return -1;
	}

	return ProdottoRec(a, b, 0);
}