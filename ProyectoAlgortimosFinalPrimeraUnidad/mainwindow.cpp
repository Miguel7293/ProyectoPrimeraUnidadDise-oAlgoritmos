#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this))
    , timer(new QTimer(this))
    , indiceActual(0)
    , comparaciones(0)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

    // Conectar el temporizador a la función que realizará la comparación
    connect(timer, &QTimer::timeout, this, &MainWindow::realizarComparacion);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnBuscar_clicked()
{
    // Obtener el número objetivo desde la interfaz
    objetivo = ui->lineEdit->text().toInt();

    // Inicializar el array gráficamente
    inicializarArrayGraficamente();

    // Reiniciar contador de comparaciones y el índice actual
    indiceActual = 0;
    comparaciones = 0;
    actualizarComparaciones();

    // Iniciar el temporizador para hacer comparaciones paso a paso
    timer->start(1000); // Cada segundo hace una comparación
}

void MainWindow::inicializarArrayGraficamente()
{
    // Limpiar la escena anterior
    scene->clear();
    elementosGraficos.clear();

    // Crear los elementos gráficos para representar el array
    for (int i = 0; i < tamano; ++i) {
        QGraphicsTextItem *textItem = new QGraphicsTextItem(QString::number(arr[i]));
        textItem->setPos(i * 50, 0);
        scene->addItem(textItem);
        elementosGraficos.append(textItem);
    }
}

void MainWindow::realizarComparacion()
{
    // Verificar si ya hemos terminado de recorrer el array
    if (indiceActual >= tamano) {
        timer->stop();
        ui->label->setText("No encontrado");
        return;
    }

    // Obtener el elemento actual a comparar
    QGraphicsTextItem *elementoActual = elementosGraficos[indiceActual];

    // Comparar con el objetivo
    if (arr[indiceActual] == objetivo) {
        // Si el número es el objetivo, marcarlo de color verde y detener el temporizador
        elementoActual->setDefaultTextColor(Qt::green);
        timer->stop();
        ui->label->setText("Encontrado en índice: " + QString::number(indiceActual));
    } else {
        // Si no es el objetivo, marcarlo de color rojo
        elementoActual->setDefaultTextColor(Qt::red);
    }

    // Incrementar las comparaciones y actualizar el contador en la interfaz
    comparaciones++;
    actualizarComparaciones();

    // Pasar al siguiente elemento
    indiceActual++;
}

void MainWindow::actualizarComparaciones()
{
    // Actualiza el label que muestra el número de comparaciones
    ui->comparacionesLabel->setText("Comparaciones: " + QString::number(comparaciones));
}
