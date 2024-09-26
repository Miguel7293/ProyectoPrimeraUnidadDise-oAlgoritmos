#include "Busqueda.h"

Busqueda::Busqueda(QObject *parent) : QObject(parent)
{
}

int Busqueda::busquedaLineal(int arr[], int tamano, int objetivo)
{
    for (int i = 0; i < tamano; ++i)
    {
        if (arr[i] == objetivo)
        {
            emit resultadoBusqueda(i);
            return i; // Retorna el índice donde se encuentra el objetivo
        }
    }
    emit resultadoBusqueda(-1); // No encontrado
    return -1;
}
