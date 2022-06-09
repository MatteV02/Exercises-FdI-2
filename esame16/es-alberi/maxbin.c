#include <stdlib.h>
#include <stdint.h>

#include "tree.h"

static size_t TrovaMax(const ElemType* v, size_t start, size_t end)
{
	size_t max = start;
	for (size_t i = start + 1; i <= end; i++)
	{
		if (v[i] > v[max])
		{
			max = i;
		}
	}

	return max;
}

static Node* CreateMaxBinTreeRec(const ElemType* v, size_t start, size_t end)
{
	if (start <= end && end != SIZE_MAX) {
		size_t max = TrovaMax(v, start, end);
		
		return TreeCreateRoot(v + max, CreateMaxBinTreeRec(v, start, max - 1), CreateMaxBinTreeRec(v, max + 1, end));
	}
	
	return TreeCreateEmpty();
	
}

Node* CreateMaxBinTree(const ElemType* v, size_t v_size)
{
	if (v == NULL || v_size == 0) {
		return NULL;
	}

	return CreateMaxBinTreeRec(v, 0, v_size - 1);
}