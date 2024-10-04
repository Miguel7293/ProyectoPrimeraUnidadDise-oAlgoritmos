#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QThread>

// Incluir los encabezados de las clases de búsqueda
#include "BusquedaLineal.h"
#include "BusquedaBinaria.h"
#include "BusquedaSalto.h"
#include "BusquedaExponencial.h"
#include "BusquedaInterpolativa.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Declaración de la clase MainWindow
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnBuscar_clicked();  // Slot para manejar el botón de búsqueda
    void realizarComparacion();   // Slot para realizar las comparaciones
    void updateResults();         // Función para actualizar resultados

private:
    Ui::MainWindow *ui;

    // Escenas y contadores
    QGraphicsScene *sceneLineal;
    QGraphicsScene *sceneBinaria;
    QGraphicsScene *sceneSalto;
    QGraphicsScene *sceneExponencial;
    QGraphicsScene *sceneInterpolativa;

    QTimer *timer;

    // Ejemplo de arreglo
    int arr[8] = {3, 6, 8, 12, 14, 17, 19, 23};
    int tamano = sizeof(arr) / sizeof(arr[0]);
    int objetivo;
    QList<QGraphicsTextItem*> elementosGraficosLineal;
    QList<QGraphicsTextItem*> elementosGraficosBinaria;
    QList<QGraphicsTextItem*> elementosGraficosSalto;
    QList<QGraphicsTextItem*> elementosGraficosExponencial;
    QList<QGraphicsTextItem*> elementosGraficosInterpolativa;

    // Resultados de cada algoritmo
    QString resultadoLineal;
    QString resultadoBinario;
    QString resultadoSalto;
    QString resultadoExponencial;
    QString resultadoInterpolativo;

    // Contadores de comparaciones
    int comparacionesLineal;
    int comparacionesBinario;
    int comparacionesSalto;
    int comparacionesExponencial;
    int comparacionesInterpolativa;
    int indiceActual; // Índice actual para las comparaciones
    int indiceActualLineal;
    int indiceActualBinario;
    int indiceActualSalto;
    int indiceActualExponencial;
    int indiceActualInterpolativa;
    int izquierdaBinaria;
    int derechaBinaria;

    // Declaraciones de las funciones de animación para cada búsqueda
    void buscarConAnimacionLineal(BusquedaLineal &busquedaLineal);
    void buscarConAnimacionBinaria(BusquedaBinaria &busquedaBinaria);
    void buscarConAnimacionSalto(BusquedaSalto &busquedaSalto);
    void buscarConAnimacionExponencial(BusquedaExponencial &busquedaExponencial);
    void buscarConAnimacionInterpolativa(BusquedaInterpolativa &busquedaInterpolativa);

    void inicializarArrayGraficamente();  // Inicializa la vista del array
    void realizarBusqueda();              // Método para iniciar todas las búsquedas
    void actualizarComparaciones();       // Actualiza el contador de comparaciones
};

#endif // MAINWINDOW_H
