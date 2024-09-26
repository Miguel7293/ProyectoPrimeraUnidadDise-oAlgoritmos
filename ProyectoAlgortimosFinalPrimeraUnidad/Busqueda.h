#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <QObject>

class Busqueda : public QObject
{
    Q_OBJECT

public:
    explicit Busqueda(QObject *parent = nullptr);
    int busquedaLineal(int arr[], int tamano, int objetivo);

signals:
    void resultadoBusqueda(int indice);
};

#endif // BUSQUEDA_H
