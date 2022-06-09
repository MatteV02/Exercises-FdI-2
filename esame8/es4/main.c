#include <stdlib.h>
#include <stdbool.h>

#include "tree.h"

extern bool Isomorfi(const Node* t1, const Node* t2);

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

int main(void)
{
    int t1_v[] = { 1,2,3,0,0,4 };
    int t2_v[] = { 1,2,3 };

    Node* t1 = TreeCreateFromVector(t1_v, sizeof(t1_v) / sizeof(*t1_v));
    Node* t2 = TreeCreateFromVector(t2_v, sizeof(t2_v) / sizeof(*t2_v));

    bool ret = Isomorfi(t1, t2);

    TreeDelete(t1);
    TreeDelete(t2);

	return 0;
}