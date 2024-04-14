#include <iostream>
#include "QuickSort.hpp"

int main() {
    int a[] {6, 129, -34, 0, 7, 1954};
    QuickSort(0, 5, a, 6);
    for (int i : a) {
        std::cout << i << " ";
    }
}