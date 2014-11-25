#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "../src/heap.h"

int main (int argc, char ** argv) {
    if (argc != 2) {
      printf("usage: ./HeapTest [heap size]\n");
      return -1;
    }

    int size = atoi(argv[1]);
    if (size < 0)
      size = 0;

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
