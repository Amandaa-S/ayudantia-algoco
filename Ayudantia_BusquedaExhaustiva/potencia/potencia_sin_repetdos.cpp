#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;

// Función para encontrar todos los subconjuntos (eliminando duplicados)
vector<vector<int>> encontrarConjuntoPotencia(const vector<int> &nums)
{
    int num_elementos = nums.size();
    unsigned int num_subconjuntos = pow(2, num_elementos); // Total de subconjuntos posibles (2^n)

    // Ordenar el array para gestionar duplicados
    vector<int> elementos_ordenados = nums;
    sort(elementos_ordenados.begin(), elementos_ordenados.end());

    vector<vector<int>> subconjuntos;          // Almacena todos los subconjuntos
    unordered_set<string> subconjuntos_unicos; // Almacena representaciones únicas de subconjuntos

    // Generar todos los subconjuntos posibles
    for (int contador = 0; contador < num_subconjuntos; ++contador)
    {
        vector<int> subconjunto_actual;
        string clave_unica; // Para evitar duplicados

        // Construir el subconjunto actual basado en los bits de 'contador'
        for (int j = 0; j < num_elementos; ++j)
        {
            if (contador & (1 << j))
            { // Verificar si el bit j está encendido
                subconjunto_actual.push_back(elementos_ordenados[j]);
                clave_unica += to_string(elementos_ordenados[j]) + '$';
            }
        }

        // Si el subconjunto es único, agregarlo a la lista de subconjuntos
        if (subconjuntos_unicos.find(clave_unica) == subconjuntos_unicos.end())
        {
            subconjuntos.push_back(subconjunto_actual);
            subconjuntos_unicos.insert(clave_unica);
        }
    }

    return subconjuntos;
}

int main()
{
    // Conjunto de entrada
    vector<int> conjunto = {10, 12, 12};

    // Encontrar el conjunto potencia (subconjuntos únicos)
    vector<vector<int>> conjunto_potencia = encontrarConjuntoPotencia(conjunto);

    // Mostrar los subconjuntos
    cout << "Subconjuntos únicos:\n";
    for (const auto &subconjunto : conjunto_potencia)
    {
        cout << "{ ";
        for (int elemento : subconjunto)
        {
            cout << elemento << " ";
        }
        cout << "}\n";
    }

    return 0;
}
