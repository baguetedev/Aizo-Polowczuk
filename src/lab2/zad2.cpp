#include <iostream>
#include <cstdlib>
#include <ctime>

#include "ArrayHeap.hpp"
#include "PointerHeap.hpp"
#include "HeapSort.hpp"

int main() {
    srand(1337);
    const int N = 200000;
    int* oryginalne = new int[N];
    for (int i = 0; i < N; ++i) oryginalne[i] = rand() % 1000000;

    int* dane = new int[N];
    clock_t start, end;

    std::cout << "Sortowanie " << N << " elementow...\n\n";

    for(int i=0; i<N; ++i) dane[i] = oryginalne[i];
    start = clock();
    heapSort<PointerHeap>(dane, N);
    end = clock();
    std::cout << "1. Kopiec Wskaznikowy czas: " << double(end - start) / CLOCKS_PER_SEC << " s\n";

    for(int i=0; i<N; ++i) dane[i] = oryginalne[i];
    start = clock();
    heapSort<ArrayHeap>(dane, N);
    end = clock();
    std::cout << "2. Kopiec Tablicowy czas:   " << double(end - start) / CLOCKS_PER_SEC << " s\n";

    delete[] oryginalne;
    delete[] dane;
    return 0;
}
