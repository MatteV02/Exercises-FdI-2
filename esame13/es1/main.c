#include <stdlib.h>

extern char* ReverseString(const char* str);

int main(void)
{
	char* ret = ReverseString("stringa da invertire");

	free(ret);

	return 0;
}