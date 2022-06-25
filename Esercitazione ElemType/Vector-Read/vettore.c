#include "vettore.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void VectorPushBack(Vector* v, ElemType* el) {
	if (v->size == v->capacity) {
		v->capacity *= 2;
		v->data = realloc(v->data, sizeof(ElemType) * v->capacity);
	}

	memcpy(v->data + v->size, el, sizeof(ElemType));
	++(v->size);

}

Vector* VectorRead(const char* filename)
{
	Vector* ret = NULL;
	FILE* in = fopen(filename, "rt");
	
	if (in != NULL) {
		ret = malloc(sizeof(Vector));
		ret->capacity = 1;
		ret->size = 0;
		ret->data = malloc(sizeof(ElemType));
		
		while (1) {
			ElemType temp;

			int ret_ElemRead = ElemRead(in, &temp);

			if (ret_ElemRead == EOF) {
				break;
			}

			VectorPushBack(ret, &temp);

		}

		fclose(in);
	}

	return ret;
}

static void VectorInsert(Vector* v, ElemType* el) {
	if (v->size == v->capacity) {
		v->capacity *= 2;
		v->data = realloc(v->data, sizeof(ElemType) * v->capacity);
	}

	size_t i;
	bool already_inserted = false;
	for (i = 0; i < v->size; i++)
	{
		if (ElemCompare(el, v->data + i) < 0) {
			memmove(v->data + i + 1, v->data + i, sizeof(ElemType) * (v->size - i));
			memcpy(v->data + i, el, sizeof(ElemType));
			already_inserted = true;
			break;
		}
	}

	if (!already_inserted) {
		memcpy(v->data + v->size, el, sizeof(ElemType));
	}

	++(v->size);

}


Vector* VectorReadSorted(const char* filename)
{
	Vector* ret = NULL;
	FILE* in = fopen(filename, "rt");

	if (in != NULL) {
		ret = malloc(sizeof(Vector));
		ret->capacity = 1;
		ret->size = 0;
		ret->data = malloc(sizeof(ElemType));

		while (1) {
			ElemType temp;

			int ret_ElemRead = ElemRead(in, &temp);

			if (ret_ElemRead == EOF) {
				break;
			}

			VectorInsert(ret, &temp);

		}

		fclose(in);
	}

	return ret;
}