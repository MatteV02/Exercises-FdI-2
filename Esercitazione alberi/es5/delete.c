#include "tree.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

static void BstSearchRec(Node* n, const ElemType* key, size_t i, Node** ret, size_t* i_ret, Node* prev, bool prev_right, Node** father_node, bool* is_father_node_right)
{
	if (TreeIsEmpty(n)) {
		return;
	}

	if (i < *i_ret && ElemCompare(TreeGetRootValue(n), key) == 0) {
		*ret = n;
		*i_ret = i;
		*father_node = prev;
		*is_father_node_right = prev_right;
	}

	BstSearchRec(TreeLeft(n), key, i + 1, ret, i_ret, n, false, father_node, is_father_node_right);
	BstSearchRec(TreeRight(n), key, i + 1, ret, i_ret, n, true, father_node, is_father_node_right);
}

static Node* BstSearch(Node* n, const ElemType* key, Node** father_node, bool*  is_father_node_right) 
{
	Node* ret = NULL;
	size_t i_ret = SIZE_MAX;

	BstSearchRec(n, key, 0, &ret, &i_ret, NULL, false, father_node, is_father_node_right);

	return ret;
}

static Node* TrovaPredecessore(Node* n, Node** predecessore_father, bool *is_predessore_father_right)
{
	Node* ret = TreeLeft(n);
	*predecessore_father = n;
	*is_predessore_father_right = false;

	while (!TreeIsEmpty(TreeRight(ret))) {
		*is_predessore_father_right = true;
		*predecessore_father = ret;
		ret = TreeRight(ret);
	}

	return ret;
}

Node* DeleteBstNode(Node* n, const ElemType* key)
{
	Node* father_node = NULL;
	bool is_father_node_right = false;
	Node* key_node = BstSearch(n, key, &father_node, &is_father_node_right);
	
	if (key_node != NULL) {
		if (TreeIsLeaf(key_node)) {
			free(key_node);
			if (father_node != NULL) {
				if (is_father_node_right) {
					father_node->right = NULL;
				}
				else {
					father_node->left = NULL;
				}
			}
			else {
				return NULL;
			}
		}
		else if (TreeIsEmpty(TreeLeft(key_node)) && !TreeIsEmpty(TreeRight(key_node))) {
			if (father_node != NULL) {
				if (is_father_node_right) {
					father_node->right = TreeRight(key_node);
				}
				else {
					father_node->left = TreeRight(key_node);
				}
				free(key_node);
			}
			else {
				Node* ret = TreeRight(key_node);

				free(key_node);

				return ret;
			}
		}
		else if (!TreeIsEmpty(TreeLeft(n)) && TreeIsEmpty(TreeRight(n))) {
			if (father_node != NULL) {
				if (is_father_node_right) {
					father_node->right = TreeLeft(key_node);
				}
				else {
					father_node->left = TreeLeft(key_node);
				}
				free(key_node);
			}
			else {
				Node* ret = TreeLeft(key_node);

				free(key_node);

				return ret;
			}
		}
		else {
			Node* predecessore_father;
			bool is_predecessore_father_right;
			Node* predecessore = TrovaPredecessore(key_node, &predecessore_father, &is_predecessore_father_right);

			if (is_predecessore_father_right) {
				predecessore->left = key_node->left;
			}
			
			predecessore->right = key_node->right;
			if (is_predecessore_father_right) {
				predecessore_father->right = NULL;
			}
			else {
				predecessore_father->left = NULL;
			}

			free(key_node);
			if (father_node != NULL) {
				if (is_father_node_right) {
					father_node->right = predecessore;
				}
				else {
					father_node->left = predecessore;
				}
			}
			else {
				return predecessore;
			}
		}
	}

	return n;
}