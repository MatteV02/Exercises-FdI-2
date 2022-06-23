#include "minheap.h"

#include <stdlib.h>
#include <string.h>

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

int Pop(Heap* h)
{
    int ret = ElemCopy(HeapGetNodeValue(h, 0));
    ElemSwap(h->data, h->data + h->size - 1);
    h->size--;

    h->data = realloc(h->data, sizeof(ElemType) * h->size);

    HeapMinMoveDown(h, 0);

    return ret;
}

int KthLeast(const int* v, size_t n, int k)
{
    Heap* h = HeapifyMinHeap(v, n);

    int ret;
    for (int i = 0; i < k; ++i)
    {
        ret = Pop(h);
    }

    HeapDelete(h);

    return ret;
}