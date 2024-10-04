#ifndef BUSQUEDASALTO_H
#define BUSQUEDASALTO_H

#include <QObject>
#include <cmath>

class BusquedaSalto : public QObject
{
    Q_OBJECT

public:
    explicit BusquedaSalto(QObject *parent = nullptr);
    int buscar(int arr[], int tamano, int objetivo);
};

#endif
