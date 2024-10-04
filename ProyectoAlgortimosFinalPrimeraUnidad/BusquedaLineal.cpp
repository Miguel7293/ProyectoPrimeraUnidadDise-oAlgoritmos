#include "BusquedaLineal.h"

BusquedaLineal::BusquedaLineal(QObject *parent) : QObject(parent) {}

int BusquedaLineal::buscar(int arr[], int tamano, int objetivo) {
    for (int i = 0; i < tamano; ++i) {
        if (arr[i] == objetivo) {
            return i; // Retorna el índice
        }
    }
    return -1; // No encontrado
}
