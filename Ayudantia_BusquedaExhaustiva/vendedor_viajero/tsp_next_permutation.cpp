#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>



int calcular_costo_ruta(const std::vector<int> &ruta,
                        const std::vector<std::vector<int>> &distancias)
{
    int costo = 0;
    for (size_t i = 0; i < ruta.size() - 1; ++i)
    {
        costo += distancias[ruta[i]][ruta[i + 1]];
    }
    // Regreso a la ciudad de origen
    costo += distancias[ruta.back()][ruta.front()]; 
    return costo;
}

void resolver_TSP(std::vector<int> &ciudades,
                  const std::vector<std::vector<int>> &distancias)
{
    std::sort(ciudades.begin(), ciudades.end());
    int mejor_costo = INT_MAX;
    std::vector<int> mejor_ruta;

    do
    {
        int costo = calcular_costo_ruta(ciudades, distancias);
        if (costo < mejor_costo)
        {
            mejor_costo = costo;
            mejor_ruta = ciudades;
        }
    } while (std::next_permutation(ciudades.begin(), ciudades.end()));

    std::cout << "Mejor ruta: ";
    for (int ciudad : mejor_ruta)
    {
        std::cout << ciudad << " ";
    }
    std::cout << "\nCosto: " << mejor_costo << std::endl;
}

int main()
{
    std::vector<int> ciudades = {0, 1, 2, 3};
    std::vector<std::vector<int>> distancias = {
        {0, 40, 15, 17},
        {40, 0, 10, 20},
        {15, 10, 0, 25},
        {17, 20, 25, 0}};
    resolver_TSP(ciudades, distancias);
    return 0;
}
