#include <stdlib.h>
#include "list.h"

extern Item* CreaDaMinori(const Item* i, int v);

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

    Item* ret = CreaDaMinori(l, 5);

    ListDelete(l);
    ListDelete(ret);

	return EXIT_SUCCESS;
}