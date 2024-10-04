#ifndef BUSQUEDAEXPONENCIAL_H
#define BUSQUEDAEXPONENCIAL_H

#include <QObject>

class BusquedaExponencial : public QObject
{
    Q_OBJECT

public:
    explicit BusquedaExponencial(QObject *parent = nullptr);
    int buscar(int arr[], int tamano, int objetivo);
};

#endif // BUSQUEDAEXPONENCIAL_H
