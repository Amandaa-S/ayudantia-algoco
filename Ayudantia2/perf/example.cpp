#include <iostream>
#include <vector>
#include <random>

// Función ineficiente que cuenta la frecuencia de cada elemento en el vector
std::vector<std::pair<int, int>> countFrequencies(const std::vector<int>& vec) {
    std::vector<std::pair<int, int>> frequencies;

    for (size_t i = 0; i < vec.size(); ++i) {
        bool found = false;
        for (size_t j = 0; j < frequencies.size(); ++j) {
            if (frequencies[j].first == vec[i]) {
                frequencies[j].second++;
                found = true;
                break;
            }
        }
        if (!found) {
            frequencies.push_back(std::make_pair(vec[i], 1));
        }
    }

    return frequencies;
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

    // Llama a la función ineficiente
    std::vector<std::pair<int, int>> frequencies = countFrequencies(vec);

    // Imprime la frecuencia del primer elemento en el vector de frecuencias
    std::cout << "Element: " << frequencies[0].first << " Frequency: " << frequencies[0].second << std::endl;

    return 0;
}
