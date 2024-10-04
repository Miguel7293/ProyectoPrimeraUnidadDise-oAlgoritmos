#include "BusquedaBinaria.h"

BusquedaBinaria::BusquedaBinaria(QObject *parent) : QObject(parent) {}

int BusquedaBinaria::buscar(int arr[], int tamano, int objetivo) {
    int izquierda = 0;
    int derecha = tamano - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == objetivo) {
            return medio; // Retorna el índice
        }

        if (arr[medio] < objetivo) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    return -1; // No encontrado
}
