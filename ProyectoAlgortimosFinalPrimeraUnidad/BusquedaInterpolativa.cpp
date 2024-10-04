#include "BusquedaInterpolativa.h"

BusquedaInterpolativa::BusquedaInterpolativa(QObject *parent) : QObject(parent) {}

int BusquedaInterpolativa::buscar(int arr[], int tamano, int objetivo) {
    int izquierda = 0, derecha = tamano - 1;

    while (izquierda <= derecha && objetivo >= arr[izquierda] && objetivo <= arr[derecha]) {
        // Calcular la posición de estimación
        int posicion = izquierda + ((double)(derecha - izquierda) / (arr[derecha] - arr[izquierda]) * (objetivo - arr[izquierda]));

        // Comprobar si el objetivo está en la posición estimada
        if (arr[posicion] == objetivo) {
            return posicion; // Retorna el índice
        }

        if (arr[posicion] < objetivo) {
            izquierda = posicion + 1;
        } else {
            derecha = posicion - 1;
        }
    }

    return -1; // No encontrado
}
