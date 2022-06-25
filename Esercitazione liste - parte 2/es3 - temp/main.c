#include <stdlib.h>

#include "list.h"

extern Item* Sort(Item* i);

Item* ListCreateFromVector(const ElemType* v, size_t v_size) {
	Item* list = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		list = ListInsertBack(list, &v[i]);
	}
	return list;
}

int main(void)
{
	ElemType v[] = { 
	{
		"Michele", "Firenze", 12, "Modena", "MO", "41126"
	}, {
		"Federico", "Peschiera", 54, "Modena", "MO", "41126"
	}, {
		"Massimiliano", "Roma", 23, "Firenze", "FI", "50100"
	}, {
		"Massimiliano", "Newton", 23, "Modena", "MO", "41126"
	}, {
		"Stefano", "Ciro Menotti", 10, "Milano", "MI", "20019"
	}
	};

	Item* l = ListCreateFromVector(v, sizeof(v) / sizeof(*v));

	l = Sort(l);

	ListDelete(l);

	return EXIT_SUCCESS;
}