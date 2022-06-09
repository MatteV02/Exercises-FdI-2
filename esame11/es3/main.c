#include <stdlib.h>

#include "list.h"

#define _CRT_MAP_ALLOC
#include <crtdbg.h>

extern Item* BucketSort(Item* l);

int main(void)
{

	Item* l = ListCreateEmpty();
	
	l = ListInsertHead(&(int) { 4 }, l);
	l = ListInsertHead(&(int) { 5 }, l);
	l = ListInsertHead(&(int) { 2 }, l);
	l = ListInsertHead(&(int) { 7 }, l);

	l = BucketSort(l);

	ListDelete(l);

	_CrtDumpMemoryLeaks();

	return 0;
}