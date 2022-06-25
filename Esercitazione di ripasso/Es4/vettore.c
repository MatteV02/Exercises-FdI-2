#include "vettore.h"
#include <string.h>

void Push(struct vettore *v, int d)
{
	if (v != NULL) {
		if (v->data == NULL) {
			v->size = 1;
		}
		else {
			v->size++;
		}

		v->data = realloc(v->data, v->size * sizeof(int));
		v->data[v->size - 1] = d;
	}
}

int Pop(struct vettore *v)
{
	int ret = *(v->data);

	v->size--;
	memmove(v->data, v->data + 1,	sizeof(int) * v->size);
	v->data = realloc(v->data,		sizeof(int) * v->size);

	return ret;
}