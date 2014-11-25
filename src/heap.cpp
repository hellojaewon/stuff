#include <cstdio>
#include <algorithm>
#include "heap.h"

MinHeap::MinHeap (int capacity) {
    m_elements = new int[capacity+1];
    m_capacity = capacity;
    m_size = 0;
}

MinHeap::~MinHeap () {
    delete[] m_elements;
}

void MinHeap::MinHeapify (int parent) {
    int leftChild, rightChild;
    int smallest;

    leftChild = parent * 2;
    rightChild = leftChild + 1;

    smallest = parent;
    if (leftChild <= m_size && m_elements[leftChild] < m_elements[parent])
        smallest = leftChild;
    if (rightChild <= m_size && m_elements[rightChild] < m_elements[smallest])
        smallest = rightChild;
    if (smallest != parent) {
        std::swap(m_elements[parent], m_elements[smallest]);
        MinHeapify(smallest);
    }
}

void MinHeap::BuildMinHeap () {
    for (unsigned i = m_size/2; i >= 1; i--)
        MinHeapify(i);
}

int MinHeap::Delete () {
    if (!m_size)
        return 0;
    int min;

    // should consider heap underflow
    min = m_elements[1];
    m_elements[1] = m_elements[m_size];
    m_size--;
    MinHeapify(1);
    return min;
}

void MinHeap::HeapDecreaseKey (int i, int key) {
    m_elements[i] = key;
    // compares to parent
    while (i > 1 && m_elements[i/2] > m_elements[i]) {
        std::swap(m_elements[i], m_elements[i/2]);
        i = i / 2;
    }
}

bool MinHeap::Insert (int key) {
    if (m_size == m_capacity)
        return false;
    m_size++;
    m_elements[m_size] = key;
    HeapDecreaseKey(m_size, key);
    return true;
}
