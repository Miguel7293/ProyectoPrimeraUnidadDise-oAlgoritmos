#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnBuscar_clicked();
    void realizarComparacion(); // Slot para hacer la comparación paso a paso

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    int arr[8] = {3, 6, 8, 12, 14, 17, 19, 23}; // Arreglo de prueba
    int tamano = 8;
    int indiceActual;
    int comparaciones;
    int objetivo;
    QList<QGraphicsTextItem*> elementosGraficos;

    void inicializarArrayGraficamente(); // Inicializa la vista del array
    void actualizarComparaciones(); // Actualiza el contador de comparaciones
};

#endif // MAINWINDOW_H
