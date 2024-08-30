#include <iostream>
#include <vector>
#include <cassert>
int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Intento de acceso fuera de los límites del vector
    for (size_t i = 0; i <= numbers.size(); ++i) {
        assert(i < numbers.size());
        std::cout << "Element at index " << i << ": " << numbers[i] << std::endl;
    }

    return 0;
}
