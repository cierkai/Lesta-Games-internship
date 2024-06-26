#include <iostream>
#include "option 2.hpp"

int main() {
    List<int> cyclic_buffer;
    cyclic_buffer.push_back(5);
    cyclic_buffer.push_back(371);
    cyclic_buffer.push_back(84);
    cyclic_buffer.push_back(129);
    std::cout << cyclic_buffer.size() << "\n";
    auto elem = cyclic_buffer.find(371);
    std::cout << elem->value << " ";
    for (int i = 0; i < 5; ++i) {
        elem = cyclic_buffer.next(elem);
        std::cout << elem->value << " ";
    }
    std::cout << "\n";
    // delete elem with value = 84
    cyclic_buffer.erase(elem);
    std::cout << cyclic_buffer.size() << "\n";
    cyclic_buffer.make_empty();
    std::cout << cyclic_buffer.size() << "\n";
    cyclic_buffer.make_empty();
    std::cout << cyclic_buffer.size() << "\n";
    cyclic_buffer.find(987);
}