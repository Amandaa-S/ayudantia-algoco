#include <iostream>

void memoryLeak() {
    std::cout << "Inicio de funcion memoryLeak()" << std::endl;
    int* leak = new int[100]; // Memoria asignada pero no liberada
    for (int i = 0; i < 100; ++i) {
        leak[i] = i;
    }
}

int main() {
    memoryLeak();
    std::cout << "Memory leak example" << std::endl;
    return 0;
}