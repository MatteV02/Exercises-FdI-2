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

extern void LevelOrder(const Node* t);

int main(void)
{
    int v[] = { 7,4,8,2,5,0,0,1 };
    Node* t = TreeCreateFromVector(v, sizeof(v) / sizeof(*v));

    TreeDelete(t->right->left);
    t->right->left = NULL;

    TreeDelete(t->right->right);
    t->right->right = NULL;
    
    LevelOrder(t);

    TreeDelete(t);

    return 0;
}