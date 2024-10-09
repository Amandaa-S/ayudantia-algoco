#include <iostream>
#include <algorithm>
#include <vector>

void imprimir_permutaciones(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
    do {
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(arr.begin(), arr.end()));
}

int main() {
    std::vector<int> arr = {1, 2, 3};
    imprimir_permutaciones(arr);
    return 0;
}
