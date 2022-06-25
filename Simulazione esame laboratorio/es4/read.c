#define _CRT_SECURE_NO_WARNINGS

#include "tree.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

Node* TreeReadRec(FILE* f, bool foglia) 
{
	char c;
	int ret_fscanf = fscanf(f, " %c", &c);

	if (ret_fscanf == EOF) {
		return TreeCreateEmpty();
	}

	if (c == '.') {
		return TreeReadRec(f, true);
	}
	else {

		if (foglia) {
			return TreeCreateRoot(&c, NULL, NULL);
		}
		else {
			Node* l = TreeReadRec(f, false);
			Node* r = TreeReadRec(f, false);
			return TreeCreateRoot(&c, l, r);
			
		}
	}
}

Node* TreeRead(const char* filename)
{
	Node* ret = TreeCreateEmpty();

	if (filename != NULL)
	{
		FILE* f = fopen(filename, "rt");

		if (f != NULL)
		{

			/*while (1)
			{
				char c;
				int ret_fscanf = fscanf(f, " %c", &c);

				if (ret_fscanf == EOF) {
					break;
				}

				if (c == '.') {
					foglia = true;
					continue;
				}

				if (foglia) {
					if (insert_right) {
						father->right = TreeCreateRoot(&c, NULL, NULL);
						insert_right = false;
					}
					else {
						father->left = TreeCreateRoot(&c, NULL, NULL);
						foglia = false;
						insert_right = true;
					}
				}
				else {
					Node* new_elem = TreeCreateRoot(&c, NULL, NULL);
					if (insert_right) {
						father->right = new_elem;
						father = new_elem;
						insert_right = false;
					}
					else {
						father->left = new_elem;
						father = new_elem;
					}
				}
			}*/

			ret = TreeReadRec(f, false);

			fclose(f);
		}
	}

	return ret;
}