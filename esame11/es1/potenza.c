int Potenza(int a, int b)
{
	if (b == 0) {
		return 1;
	}

	return a * Potenza(a, b - 1);
}