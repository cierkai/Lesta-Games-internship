#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

#include <iostream>
#include <random>

std::mt19937 gen(757);

inline void Partition(int l, int r, int x, int *a, int &i, int &j) {
    i = l;
    j = r;
    while (i <= j) {
        while (a[i] < x) { i++; }
        while (a[j] > x) { j--; }
        if (i <= j) { std::swap(a[i++], a[j--]); }
    }
}

inline void QuickSort(int l, int r, int *a, int size_) {
    if (l >= r) { return; }
    int i, j;
    Partition(l, r, a[gen() % size_], a, i, j);
    QuickSort(l, j, a, size_);
    QuickSort(i, r, a, size_);
}

#endif