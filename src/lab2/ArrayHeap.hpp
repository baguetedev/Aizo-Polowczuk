#ifndef ARRAYHEAP_HPP
#define ARRAYHEAP_HPP

#include "HeapSort.hpp"

template <typename T>
class ArrayHeap {
private:
    T* data;
    int count;

    void heapifyDown(int i) {
        while (true) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < count && data[left] > data[largest]) largest = left;
            if (right < count && data[right] > data[largest]) largest = right;

            if (largest != i) {
                mySwap(data[i], data[largest]);
                i = largest;
            } else break;
        }
    }

public:
    ArrayHeap(T* arr, int n) {
        count = n;
        data = new T[n];
        for (int i = 0; i < n; ++i) data[i] = arr[i];
        for (int i = n / 2 - 1; i >= 0; --i) heapifyDown(i);
    }

    ~ArrayHeap() {
        delete[] data;
    }

    void pop() {
        if (count == 0) return;
        data[0] = data[count - 1];
        count--;
        heapifyDown(0);
    }

    T top() {
        return data[0];
    }
};

#endif
