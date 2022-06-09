

static int MCDRec(int m, int n) 
{
	if (n == 0)
	{
		return m;
	}
	else {
		return MCDRec(n, m % n);
	}
}

int MCD(int m, int n)
{
	if (m >= n) {
		return MCDRec(m, n);
	}
	else {
		return MCDRec(n, m);
	}
}