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

extern Node* DeleteBstNode(Node* n, const ElemType* key);

int main(void)
{
    int v[] = { 12,4,21,0,5,18,77,0,2,0,8,0,0,0,0,0,0,0,0,0,0,0,9 };

    Node* n = TreeCreateFromVector(v, sizeof(v) / sizeof(*v));
    
    TreeDelete(n->left->left->left);
    n->left->left->left = NULL;

    TreeDelete(n->left->right->left);
    n->left->right->left = NULL;

    TreeDelete(n->right->left->left);
    n->right->left->left = NULL;

    TreeDelete(n->right->left->right);
    n->right->left->right = NULL;

    TreeDelete(n->right->right->left);
    n->right->right->left = NULL;

    TreeDelete(n->right->right->right);
    n->right->right->right = NULL;

    DeleteBstNode(n, &(ElemType){21});

    return 0;
}