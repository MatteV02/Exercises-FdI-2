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

extern double Mediano(const Node* t);

int main(void)
{
    int v_gen_tree[] = { 12,4,21,0,2,5,18,77,8,9 },
        v_bst_tree[] = { 7,4,8,2,5,0,0,1 };

    Node* gen_tree = TreeCreateFromVector(v_gen_tree, sizeof(v_gen_tree) / sizeof(*v_gen_tree)),
        * bst_tree = TreeCreateFromVector(v_bst_tree, sizeof(v_bst_tree) / sizeof(*v_bst_tree));

    TreeDelete(bst_tree->right->left);
    bst_tree->right->left = NULL;

    TreeDelete(bst_tree->right->right);
    bst_tree->right->right = NULL;

    /*TreeDelete(bst_tree->left->left->left);
    bst_tree->left->left->left = NULL;

    TreeDelete(bst_tree->left->right->left);
    bst_tree->left->right->left = NULL;

    TreeDelete(bst_tree->left->left->right->left);
    bst_tree->left->left->right->left = NULL;

    TreeDelete(bst_tree->left->left->right->right);
    bst_tree->left->left->right->right = NULL;

    TreeDelete(bst_tree->left->right->right->left);
    bst_tree->left->right->right->left = NULL;

    TreeDelete(bst_tree->right->left->left);
    bst_tree->right->left->left = NULL;

    TreeDelete(bst_tree->right->left->right);
    bst_tree->right->left->right = NULL;

    TreeDelete(bst_tree->right->right->left);
    bst_tree->right->right->left = NULL;

    TreeDelete(bst_tree->right->right->right);
    bst_tree->right->right->right = NULL;*/

    /*      GEN_TREE
                     12
                    /  \
                   /    \
                  4      21
                 / \    / \
                /   \  5  18
               0     2
              / \   /
             77  8 9
    */

    /* BST_TREE
                                (12)
                  +--------------+--------+
                ( 4)                    (21)
          +------+----+               +--+----+
        ( 0)        ( 5)            (18)    (77)
         +----+      +----+
            ( 2)        ( 8)
                         +----+
                            ( 9)
    */

    double ret = Mediano(bst_tree);

    TreeDelete(gen_tree);
    TreeDelete(bst_tree);

    return 0;
}