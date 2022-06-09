#include <stdlib.h>
#include <stdbool.h>

static bool IsPalindromoRec(const char* str, int* str_len, int i, char c)
{
	if (c == 0) {
		return true;
	}

	++(*str_len);

	bool ret = IsPalindromoRec(str, str_len, i + 1, str[i + 1]);

	if (ret == true)
	{
		if (c != str[(*str_len - i - 1)])
		{
			ret = false;
		}
	}

	return ret;
}

bool IsPalindromo(const char* str)
{
	if (str == NULL)
	{
		return false;
	}

	int str_len = 0;

	return IsPalindromoRec(str, &str_len, 0, str[0]);
}