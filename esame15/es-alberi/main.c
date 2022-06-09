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

extern Node* Tree2Bst(const Node* t);

int main(void)
{
    int v_gen_tree[] = { 6,2,9,3,8,0,3,0,0,0,5 },
        v_bst_tree[] = { 0 };

    Node* gen_tree = TreeCreateFromVector(v_gen_tree, sizeof(v_gen_tree) / sizeof(*v_gen_tree)),
        * bst_tree = TreeCreateFromVector(v_bst_tree, sizeof(v_bst_tree) / sizeof(*v_bst_tree));

    TreeDelete(gen_tree->right->left);
    gen_tree->right->left = NULL;

    TreeDelete(gen_tree->left->left->left);
    gen_tree->left->left->left = NULL;

    TreeDelete(gen_tree->left->left->right);
    gen_tree->left->left->right = NULL;

    TreeDelete(gen_tree->left->right->left);
    gen_tree->left->right->left = NULL;

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

    Node* ret = Tree2Bst(gen_tree);

    TreeDelete(gen_tree);
    TreeDelete(bst_tree);
    TreeDelete(ret);

    return 0;
}