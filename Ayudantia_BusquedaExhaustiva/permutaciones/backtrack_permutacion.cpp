#include <iostream>
#include <vector>

void permutar(std::vector<int>& arr, int inicio) {
    if (inicio == arr.size() - 1) {
        for (int num : arr) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        return;
    }
    for (int i = inicio; i < arr.size(); ++i) {
        std::swap(arr[inicio], arr[i]);
        permutar(arr, inicio + 1);
        std::swap(arr[inicio], arr[i]);
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3};
    permutar(arr, 0);
    return 0;
}
