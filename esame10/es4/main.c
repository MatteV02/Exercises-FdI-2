#include <stdlib.h>

#include "list.h"

Item* ListCreateFromVector(const int* v, size_t v_size) {
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

extern int ContaVette(const Item* i);

int main(void)
{
    int v[] = { 7,2,5,4 };

    Item* i = ListCreateFromVector(v, sizeof(v) / sizeof(*v));

    int ret = ContaVette(i);

    ListDelete(i);

	return 0;
}