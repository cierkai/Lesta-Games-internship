#include "is even.hpp"
#include <iostream>
#include <random>
#include <thread>
#include <chrono>

int main() {
    std::mt19937 gen(757);
    int n;
    while (true) {
        n = gen() % INT_MAX;
        std::cout << n << " " << isEven(n) << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}