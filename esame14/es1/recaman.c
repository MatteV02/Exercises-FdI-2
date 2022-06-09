

static int RecamanRec(int n)
{
	if (n == 1)
	{
		return 1;
	}

	int a_n = RecamanRec(n - 1);

	if (a_n % (n - 1) == 0) {
		return a_n / (n - 1);
	}
	else {
		return (n - 1) * a_n;
	}

}

int Recaman(int n)
{
	if (n < 1)
	{
		return -1;
	}

	return RecamanRec(n);
}