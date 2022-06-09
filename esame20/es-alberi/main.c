#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "tree.h"

extern Node* TreeRead(const char* filename);

int main(void)
{

    Node* ret = TreeRead(NULL);

    TreeDelete(ret);

    _CrtDumpMemoryLeaks();

    return 0;
}