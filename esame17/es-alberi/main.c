#include <stdlib.h>

#include "tree.h"

extern Node* CreateMinBinTree(const ElemType* v, size_t v_size);

int main(void)
{
    ElemType v[] = { 3,2,1,6,8,5 };

    Node* ret = CreateMinBinTree(v, sizeof(v) / sizeof(*v));

    Node* gen_tree = TreeCreateRoot(
        &(int) { 12 },
        TreeCreateRoot(
            &(int) { 4 },
            TreeCreateRoot(
                &(int) { 0 },
                TreeCreateRoot(
                    &(int) { 77 },
                    NULL,
                    NULL
                ),
                TreeCreateRoot(
                    &(int) { 8 },
                    NULL,
                    NULL
                )
            ),
            TreeCreateRoot(
                &(int) { 2 },
                TreeCreateRoot(
                    &(int) { 9 },
                    NULL,
                    NULL
                ),
                NULL
            )
        ),
        TreeCreateRoot(
            &(int) { 21 },
            TreeCreateRoot(
                &(int) { 5 },
                NULL,
                NULL
            ),
            TreeCreateRoot(
                &(int) { 18 },
                NULL,
                NULL
            )
        )
    );

    Node* bst_tree = TreeCreateRoot(
        &(int) { 12 },
        TreeCreateRoot(
            &(int) { 4 },
            TreeCreateRoot(
                &(int) { 0 },
                NULL,
                TreeCreateRoot(
                    &(int) { 2 },
                    NULL,
                    NULL
                )
            ),
            TreeCreateRoot(
                &(int) { 5 },
                NULL,
                TreeCreateRoot(
                    &(int) { 8 },
                    NULL,
                    TreeCreateRoot(
                        &(int) { 9 },
                        NULL,
                        NULL
                    )
                )
            )
        ),
        TreeCreateRoot(
            &(int) { 21 },
            TreeCreateRoot(
                &(int) { 18 },
                NULL,
                NULL
            ),
            TreeCreateRoot(
                &(int) { 77 },
                NULL,
                NULL
            )
        )
    );

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

    TreeDelete(gen_tree);
    TreeDelete(bst_tree);

    return 0;
}