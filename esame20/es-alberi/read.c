#define _CRT_SECURE_NO_WARNINGS

#if defined _DEBUG & WIN32
#define _CRTBDG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#else
#include <stdlib.h>
#endif
#include <stdio.h>
#include <stdbool.h>

#include "tree.h"

Node* TreeReadRec(FILE* f, bool leaf)
{
	char c;
	int ret_fscanf = fscanf(f, " %c", &c);

	if (ret_fscanf != EOF)
	{
		if (c == '.')
		{
			return TreeReadRec(f, true);
		}
		else {
			if (leaf) {
				return TreeCreateRoot(&c, TreeCreateEmpty(), TreeCreateEmpty());
			}
			
			Node* left_tree = TreeReadRec(f, false);
			Node* right_tree = TreeReadRec(f, false);
			return TreeCreateRoot(&c, left_tree, right_tree);
		}
	}

	return TreeCreateEmpty();
}

Node* TreeRead(const char* filename)
{
	Node* ret = TreeCreateEmpty();
	if (filename != NULL)
	{
		FILE* f = fopen(filename, "r");
		if (f)
		{
			ret = TreeReadRec(f, false);

			fclose(f);
		}
	}

	return ret;
}