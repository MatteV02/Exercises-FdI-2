#include <stdlib.h>
#include <string.h>

static void ReverseStringRec(const char* str, char** out)
{
	if (*str == 0)
	{
		return;
	}

	ReverseStringRec(str + 1, out);

	**out = *str;
	++(*out);

}

char* ReverseString(const char* str)
{
	if (str == NULL)
	{
		return NULL;
	}

	char* ret = malloc(strlen(str) + 1);
	char* temp = ret;

	ReverseStringRec(str, &temp);
	*temp = 0;

	return ret;
}