#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "heap.h"

int main () {
    int size;

    printf("heap size : ");
    scanf("%d", &size);

    MinHeap * heap = new MinHeap(size);

    // generates heap with random values
    srand(time(NULL));
    for(unsigned i = 0; i < size; i++) {
        if (!heap->Insert(rand() % 100))
            printf("insert failed(%d)\n", i);
    }

    // delete elements from heap
    int minimum = -1;
    for (unsigned i = 0; i < size; i++) {
        int min = heap->Delete();
        assert(minimum <= min);
        minimum = min;
    }
    printf("test completed!\n");

    delete heap;
}
