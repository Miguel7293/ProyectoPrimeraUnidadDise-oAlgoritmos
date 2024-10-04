#include "BusquedaSalto.h"
#include <algorithm>
#include <cmath>

BusquedaSalto::BusquedaSalto(QObject *parent) : QObject(parent) {}

int BusquedaSalto::buscar(int arr[], int tamano, int objetivo) {
    int paso = std::sqrt(tamano);
    int anterior = 0;

    // Bucle para saltar bloques del tamaño "paso"
    while (anterior < tamano && arr[std::min(paso, tamano) - 1] < objetivo) {
        anterior = paso;
        paso += std::sqrt(tamano);
        if (anterior >= tamano) return -1; // No encontrado
    }

    // Búsqueda lineal dentro del bloque donde podría estar el objetivo
    for (int i = anterior; i < std::min(paso, tamano); i++) {
        if (arr[i] == objetivo) {
            return i; // Retorna el índice
        }
    }

    return -1; // No encontrado
}
