#include <stdlib.h>

#include "list.h"

extern Item* Rotate(Item* i, int n);

Item* ListCreateFromVector(const int* v, size_t v_size) {
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void)
{
    int v[] = { 1, 3,4,7,8 };

    Item* l = ListCreateFromVector(v, sizeof(v) / sizeof(*v));

    l = Rotate(l, 2);

    ListDelete(l);

	return 0;
}