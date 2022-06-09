#include "tree.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static const Node* Prova(const Node* t, size_t level, size_t pos)
{
	const Node* ret;

	while (!TreeIsEmpty(t) && level > 0) {
		if (pos >= pow(2, level - 1)) {
			t = TreeRight(t);
		}
		else {
			t = TreeLeft(t);
		}

		pos %= (size_t)pow(2, level - 1);

		--level;
	}

	ret = t;

	return ret;
}

static bool PrintLevel(const Node* t, size_t level)
{
	bool ret_bool = false;

	for (size_t pos = 0; pos < pow(2, level); pos++)
	{
		const Node* ret = Prova(t, level, pos);
		if (ret) {
			ret_bool = true;
			printf("%i ", ret->value);
		}
	}

	return ret_bool;
}

void LevelOrder(const Node* t)
{
	size_t level = 0;
	while (PrintLevel(t, level)) {
		++level;
	}
}