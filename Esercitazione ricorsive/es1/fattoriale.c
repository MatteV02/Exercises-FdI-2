unsigned long long FattorialeRec(int n, unsigned long long parz)
{
	if (n > 1) {
		return FattorialeRec(n - 1, parz * n);
	}

	return parz;
}

unsigned long long Fattoriale(int n)
{
	if (n < 0)
	{
		return 0;
	}

	return FattorialeRec(n, 1);
}
