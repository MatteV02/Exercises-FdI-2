#include <stdlib.h>
#include "list.h"

extern Item* CopiaDaN(const Item* i, int n);

Item* ListCreateFromVector(const int* v, size_t v_size) {
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void)
{
    int v[] = { 12,2,37,4 };

    Item* l = ListCreateFromVector(v, sizeof(v) / sizeof(*v));

    Item* ret = CopiaDaN(l, 2);

    ListDelete(ret);
    ListDelete(l);

	return 0;
}