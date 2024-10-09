#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


void resolver_TSP(std::vector<int> &ruta_actual,
                       const std::vector<std::vector<int>> &distancias,
                       int nivel,
                       int costo_actual,
                       int &mejor_costo,
                       std::vector<int> &mejor_ruta)
{
    if (nivel == ruta_actual.size())
    {
        costo_actual += distancias[ruta_actual[nivel - 1]][ruta_actual[0]];
        if (costo_actual < mejor_costo)
        {
            mejor_costo = costo_actual;
            mejor_ruta = ruta_actual;
        }
        return;
    }

    for (int i = nivel; i < ruta_actual.size(); ++i)
    {
        std::swap(ruta_actual[nivel], ruta_actual[i]);

        if (nivel > 0)
        {
            int costo_nuevo = costo_actual + distancias[ruta_actual[nivel - 1]][ruta_actual[nivel]];
            resolver_TSP(ruta_actual, distancias, nivel + 1, costo_nuevo, mejor_costo, mejor_ruta);
        }
        else
        {
            resolver_TSP(ruta_actual, distancias, nivel + 1, costo_actual, mejor_costo, mejor_ruta);
        }

        std::swap(ruta_actual[nivel], ruta_actual[i]);
    }
}

int main()
{
    std::vector<int> ruta_inicial = {0, 1, 2, 3};
    std::vector<std::vector<int>> distancias = {
        {0, 40, 15, 17},
        {40, 0, 10, 20},
        {15, 10, 0, 25},
        {17, 20, 25, 0}};

    int mejor_costo = INT_MAX;
    std::vector<int> mejor_ruta;

    resolver_TSP(ruta_inicial, distancias, 0, 0, mejor_costo, mejor_ruta);

    std::cout << "Mejor ruta: ";
    for (int ciudad : mejor_ruta)
    {
        std::cout << ciudad << " ";
    }
    std::cout << "\nCosto: " << mejor_costo << std::endl;

    return 0;
}