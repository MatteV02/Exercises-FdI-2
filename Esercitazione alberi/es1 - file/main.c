#include <stdlib.h>

#include "tree.h"

extern Node* BstInsert(const ElemType* e, Node* n);
extern Node* BstInsertRec(const ElemType* e, Node* n);

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
    int v[] = { 12,4,21,0,5,18,77,0,2,0,8,0,0,0,0,0,0,0,0,6,9 };

    Node* t = TreeCreateFromVector(v, sizeof(v) / sizeof(*v));
    TreeDelete(t->left->left->left);
    t->left->left->left = NULL;

    TreeDelete(t->left->right->left);
    t->left->right->left = NULL;

    TreeDelete(t->right->left->left);
    t->right->left->left = NULL;

    TreeDelete(t->right->left->right);
    t->right->left->right = NULL;

    TreeDelete(t->right->right->left);
    t->right->right->left = NULL;

    TreeDelete(t->right->right->right);
    t->right->right->right = NULL;

    t = BstInsertRec(&(int) { 6 }, t);
    
	return 0;
}