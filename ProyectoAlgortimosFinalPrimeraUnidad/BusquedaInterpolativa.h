#ifndef BUSQUEDAINTERPOLATIVA_H
#define BUSQUEDAINTERPOLATIVA_H

#include <QObject>

class BusquedaInterpolativa : public QObject
{
    Q_OBJECT

public:
    explicit BusquedaInterpolativa(QObject *parent = nullptr);
    int buscar(int arr[], int tamano, int objetivo);
};

#endif // BUSQUEDAINTERPOLATIVA_H
