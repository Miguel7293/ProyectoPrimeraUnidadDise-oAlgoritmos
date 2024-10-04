#ifndef BUSQUEDABINARIA_H
#define BUSQUEDABINARIA_H

#include <QObject>

class BusquedaBinaria : public QObject
{
    Q_OBJECT

public:
    explicit BusquedaBinaria(QObject *parent = nullptr);
    int buscar(int arr[], int tamano, int objetivo);
};

#endif
