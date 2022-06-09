#include <stdlib.h>
#include <string.h>

#include "minheap.h"

Heap* HeapifyMinHeap(const ElemType* v, size_t v_size) {
    // Costruisco la heap con gli elementi del vettore v
    Heap* h = HeapCreateEmpty();
    h->size = v_size;
    h->data = malloc(sizeof(ElemType) * (v_size));
    memcpy(h->data, v, v_size * sizeof(ElemType));

    // Chiamo la HeapMinMoveDown a partire dai nodi nel penultimo livello
    // dell'albero fino alla radice, per garantire che tutti i nodi rispettino 
    // le proprietà (min-)heap. Non serve chiamare la HeapMinMoveDown sulle
    // foglie perché non avrebbe alcun effetto.
    for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
        HeapMinMoveDown(h, i);
    }
    return h;
}

extern Heap* MergeHeap(const Heap* h1, const Heap* h2);

int main(void)
{
    ElemType v1[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 },
        v2[] = { 1, 13, 5, 22, 3, 19, 78, 9, 8 };

    Heap* h1 = HeapifyMinHeap(v1, sizeof(v1) / sizeof(*v1));
    Heap* h2 = HeapifyMinHeap(v2, sizeof(v2) / sizeof(*v2));

    Heap* ret = MergeHeap(h1, h2);

    HeapDelete(ret);

	return 0;
}