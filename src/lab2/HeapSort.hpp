#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <template<typename> class HeapType, typename T>
void heapSort(T* arr, int n) {
    HeapType<T> heap(arr, n); 
    for (int i = n - 1; i >= 0; --i) {
        arr[i] = heap.top();
        heap.pop();
    }
}

#endif
