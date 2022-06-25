#include <stdlib.h>

#include "tree.h"

Node* TreeCreateFromVectorRec(const int* v, size_t v_size, int i) {
    if (i >= (int)v_size) {
        return NULL;
    }

    Node* l = TreeCreateFromVectorRec(v, v_size, i * 2 + 1);
    Node* r = TreeCreateFromVectorRec(v, v_size, i * 2 + 2);

    return TreeCreateRoot(&v[i], l, r);
}

Node* TreeCreateFromVector(const int* v, size_t v_size) {
    return TreeCreateFromVectorRec(v, v_size, 0);
}

extern bool TreeIsMirror(const Node* t);

int main(void)
{
    int v[] = { 0,1,1,4,2,2,4,8,7,6,5,5,6,7,8 };

    Node* t = TreeCreateFromVector(v, sizeof(v) / sizeof(*v));

    bool ret = TreeIsMirror(t);

    TreeDelete(t);

	return 0;
}