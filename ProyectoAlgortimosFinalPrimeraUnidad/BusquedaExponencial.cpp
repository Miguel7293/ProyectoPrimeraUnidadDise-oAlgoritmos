#include "BusquedaExponencial.h"
#include "BusquedaBinaria.h"
#include <algorithm>
#include <cmath>

BusquedaExponencial::BusquedaExponencial(QObject *parent) : QObject(parent) {}

int BusquedaExponencial::buscar(int arr[], int tamano, int objetivo) {
    if (arr[0] == objetivo) return 0; // Caso especial para el primer elemento

    int i = 1;
    while (i < tamano && arr[i] <= objetivo) {
        i *= 2;
    }

    // Limitar el rango a los límites del arreglo
    int rangoDerecha = std::min(i, tamano - 1);
    int rangoIzquierda = i / 2;

    // Utilizar búsqueda binaria en el rango ajustado
    BusquedaBinaria busquedaBinaria;
    int resultado = busquedaBinaria.buscar(arr + rangoIzquierda, rangoDerecha - rangoIzquierda + 1, objetivo);

    return (resultado != -1) ? rangoIzquierda + resultado : -1; // Ajustar el índice de retorno si se encontró
}
