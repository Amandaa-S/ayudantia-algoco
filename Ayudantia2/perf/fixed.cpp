#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>

// Función optimizada que cuenta la frecuencia de cada elemento usando un unordered_map
std::unordered_map<int, int> countFrequencies(const std::vector<int>& vec) {
    std::unordered_map<int, int> frequency_map;

    for (size_t i = 0; i < vec.size(); ++i) {
        frequency_map[vec[i]]++;
    }

    return frequency_map;
}

int main() {
    // Semilla fija para reproducibilidad
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, 100); // Distribución uniforme entre 1 y 100

    // Genera un vector aleatorio de tamaño 1000000
    std::vector<int> vec(1000000);
    for (int& num : vec) {
        num = dist(rng);
    }

    // Llama a la función optimizada
    std::unordered_map<int, int> frequencies = countFrequencies(vec);

    // Imprime la frecuencia del primer elemento en el vector
    std::cout << "Element: " << vec[0] << " Frequency: " << frequencies[vec[0]] << std::endl;

    return 0;
}
