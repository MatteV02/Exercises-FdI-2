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

extern bool Equivalenti(const Node* t1, const Node* t2);

int main(void)
{
    int v1[] = { 1,2,3,4,5,6,0,7,8 };
    int v2[] = { 1,2,3,4,5,12,0,21,2 };

    Node* t1 = TreeCreateFromVector(v1, sizeof(v1) / sizeof(*v1)),
        *t2 = TreeCreateFromVector(v2, sizeof(v2) / sizeof(*v2));

    TreeDelete(t1->right->right);
    t1->right->right = NULL;

    TreeDelete(t2->right->right);
    t2->right->right = NULL;

    bool ret = Equivalenti(t1, t2);

    TreeDelete(t1);
    TreeDelete(t2);

	return 0;
}