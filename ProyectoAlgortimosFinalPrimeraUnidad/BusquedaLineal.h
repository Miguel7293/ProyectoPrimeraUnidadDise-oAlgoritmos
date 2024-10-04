#ifndef BUSQUEDALINEAL_H
#define BUSQUEDALINEAL_H

#include <QObject>

class BusquedaLineal : public QObject
{
    Q_OBJECT

public:
    explicit BusquedaLineal(QObject *parent = nullptr);
    int buscar(int arr[], int tamano, int objetivo);
};

#endif // BUSQUEDALINEAL_H
