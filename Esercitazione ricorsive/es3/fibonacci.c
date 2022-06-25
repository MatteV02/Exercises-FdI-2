
static int FibonacciRec(int n1, int n2, int n) {
	if (n > 0) {
		return FibonacciRec(n2, n1 + n2, n - 1);
	}

	return n1;
}

int Fibonacci(int n)
{
	if (n < 0)
	{
		return -1;
	}

	return FibonacciRec(0, 1, n);

}