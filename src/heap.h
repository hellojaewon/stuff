#ifndef HEAP_H
#define HEAP_H

#define DEFAULT_MAX_HEAP_SIZE 100

class MinHeap {
public:
    MinHeap (int capacity = DEFAULT_MAX_HEAP_SIZE);
    ~MinHeap ();

    bool Insert (int key);
    int Delete ();
    void Print ();

private:
    void BuildMinHeap ();
    void MinHeapify (int parent);
    void HeapDecreaseKey (int i, int key);

    int * m_elements;
    int m_capacity;
    int m_size;
};

#endif
