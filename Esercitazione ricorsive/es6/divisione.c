int DivisioneRec(int a, int b, int ret) {
	if (a >= b) {
		return DivisioneRec(a - b, b, ret + 1);
	}

	return ret;
}

int Divisione(int a, int b)
{
	if (a < 0 || b <= 0)
	{
		return -1;
	}

	return DivisioneRec(a, b, 0);
}