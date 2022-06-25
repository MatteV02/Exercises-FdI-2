#include <stdio.h>

extern int Fibonacci(int n);

int main(void)
{
	int ret = Fibonacci(0);
	ret = Fibonacci(1);
	ret = Fibonacci(2);
	ret = Fibonacci(3);
	ret = Fibonacci(8);
	ret = Fibonacci(13);		//233
	ret = Fibonacci(40);
	
	printf("%d", ret);

	return 0;
}