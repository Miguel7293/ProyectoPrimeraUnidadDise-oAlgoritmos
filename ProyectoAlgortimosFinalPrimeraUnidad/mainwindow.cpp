#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BusquedaLineal.h"
#include "BusquedaBinaria.h"
#include "BusquedaSalto.h"
#include "BusquedaExponencial.h"
#include "BusquedaInterpolativa.h"
#include <QGraphicsTextItem>
#include <QTimer>
#include <QThread>
#include <cmath>
#include <QElapsedTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , sceneLineal(new QGraphicsScene(this))
    , sceneBinaria(new QGraphicsScene(this))
    , sceneSalto(new QGraphicsScene(this))
    , sceneExponencial(new QGraphicsScene(this))
    , sceneInterpolativa(new QGraphicsScene(this))
    , timer(new QTimer(this))
    , comparacionesLineal(0)
    , comparacionesBinario(0)
    , comparacionesSalto(0)
    , comparacionesExponencial(0)
    , comparacionesInterpolativa(0)
    , indiceActualLineal(0)
    , izquierdaBinaria(0)
    , derechaBinaria(tamano - 1)
    , indiceActualSalto(0)
    , indiceActualExponencial(0)
    , indiceActualInterpolativa(0)
{
    ui->setupUi(this);
    ui->graphicsViewLineal->setScene(sceneLineal);
    ui->graphicsViewBinario->setScene(sceneBinaria);
    ui->graphicsViewSalto->setScene(sceneSalto);
    ui->graphicsViewExponencial->setScene(sceneExponencial);
    ui->graphicsViewInterpolativa->setScene(sceneInterpolativa);

    connect(timer, &QTimer::timeout, this, &MainWindow::realizarComparacion);
    timer->start(500); // Ajusta el intervalo del temporizador según el tiempo que prefieras para la animación
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnBuscar_clicked()
{
    objetivo = ui->lineEdit->text().toInt();

    // Inicializar el array gráficamente
    inicializarArrayGraficamente();

    // Reiniciar resultados y contadores
    resultadoLineal.clear();
    resultadoBinario.clear();
    resultadoSalto.clear();
    resultadoExponencial.clear();
    resultadoInterpolativo.clear();

    comparacionesLineal = comparacionesBinario = comparacionesSalto = comparacionesExponencial = comparacionesInterpolativa = 0;
    indiceActualLineal = izquierdaBinaria = 0;
    derechaBinaria = tamano - 1;
    indiceActualSalto = indiceActualExponencial = indiceActualInterpolativa = 0;
}

void MainWindow::inicializarArrayGraficamente()
{
    // Limpiar escenas y reiniciar elementos gráficos
    sceneLineal->clear();
    sceneBinaria->clear();
    sceneSalto->clear();
    sceneExponencial->clear();
    sceneInterpolativa->clear();

    elementosGraficosLineal.clear();
    elementosGraficosBinaria.clear();
    elementosGraficosSalto.clear();
    elementosGraficosExponencial.clear();
    elementosGraficosInterpolativa.clear();

    for (int i = 0; i < tamano; ++i) {
        auto addItemToScene = [&](QGraphicsScene *scene, QList<QGraphicsTextItem *> &list) {
            QGraphicsTextItem *item = new QGraphicsTextItem(QString::number(arr[i]));
            item->setPos(i * 50, 0);
            scene->addItem(item);
            list.append(item);
        };
        addItemToScene(sceneLineal, elementosGraficosLineal);
        addItemToScene(sceneBinaria, elementosGraficosBinaria);
        addItemToScene(sceneSalto, elementosGraficosSalto);
        addItemToScene(sceneExponencial, elementosGraficosExponencial);
        addItemToScene(sceneInterpolativa, elementosGraficosInterpolativa);
    }
}

void MainWindow::realizarComparacion()
{
    bool todosTerminaron = true;

    // Búsqueda lineal
    if (indiceActualLineal < tamano && indiceActualLineal < elementosGraficosLineal.size()) {
        auto *item = elementosGraficosLineal[indiceActualLineal];
        comparacionesLineal++;
        item->setDefaultTextColor(arr[indiceActualLineal] == objetivo ? Qt::green : Qt::red);
        if (arr[indiceActualLineal] == objetivo) {
            resultadoLineal = "Encontrado en índice: " + QString::number(indiceActualLineal);
            indiceActualLineal = tamano; // Termina la búsqueda
        } else {
            indiceActualLineal++;
        }
        todosTerminaron = false;
        ui->resultadoLinealLabel->setText("Comparaciones: " + QString::number(comparacionesLineal));
    }

    // Búsqueda binaria
    if (izquierdaBinaria <= derechaBinaria) {
        int medio = (izquierdaBinaria + derechaBinaria) / 2;
        if (medio < elementosGraficosBinaria.size()) {
            comparacionesBinario++;
            elementosGraficosBinaria[medio]->setDefaultTextColor(arr[medio] == objetivo ? Qt::green : Qt::red);
            if (arr[medio] == objetivo) {
                resultadoBinario = "Encontrado en índice: " + QString::number(medio);
                izquierdaBinaria = tamano; // Termina la búsqueda
            } else if (arr[medio] < objetivo) {
                izquierdaBinaria = medio + 1;
            } else {
                derechaBinaria = medio - 1;
            }
            todosTerminaron = false;
            ui->resultadoBinarioLabel->setText("Comparaciones: " + QString::number(comparacionesBinario));
        }
    }

    // Búsqueda por salto
    if (comparacionesSalto < tamano) {
        int paso = std::sqrt(tamano);
        int inicioBloque = (comparacionesSalto / paso) * paso;
        int finBloque = std::min(inicioBloque + paso, tamano);

        for (int i = inicioBloque; i < finBloque && i < tamano && i < elementosGraficosSalto.size(); ++i) {
            auto *item = elementosGraficosSalto[i];
            comparacionesSalto++;
            item->setDefaultTextColor(arr[i] == objetivo ? Qt::green : Qt::red);

            if (arr[i] == objetivo) {
                resultadoSalto = "Encontrado en índice: " + QString::number(i);
                comparacionesSalto = tamano; // Finaliza búsqueda
                break;
            }
        }

        todosTerminaron = false;
        ui->resultadoSaltoLabel->setText("Comparaciones: " + QString::number(comparacionesSalto));
    }

    // Búsqueda exponencial
    if (indiceActualExponencial < tamano && comparacionesExponencial < tamano) {
        int i = pow(2, comparacionesExponencial);
        if (i < tamano && i < elementosGraficosExponencial.size() && arr[i] <= objetivo) {
            comparacionesExponencial++;
            elementosGraficosExponencial[i]->setDefaultTextColor(arr[i] == objetivo ? Qt::green : Qt::red);
            if (arr[i] == objetivo) {
                resultadoExponencial = "Encontrado en índice: " + QString::number(i);
                comparacionesExponencial = tamano; // Termina la búsqueda
            }
        } else {
            // Ejecuta búsqueda binaria en el rango final
            BusquedaBinaria busquedaBinaria;
            int resultadoBinaria = busquedaBinaria.buscar(arr, tamano, objetivo);
            if (resultadoBinaria != -1) {
                elementosGraficosExponencial[resultadoBinaria]->setDefaultTextColor(Qt::green);
                resultadoExponencial = "Encontrado en índice: " + QString::number(resultadoBinaria);
            }
            comparacionesExponencial = tamano; // Termina la búsqueda
        }
        todosTerminaron = false;
        ui->resultadoExponencialLabel->setText("Comparaciones: " + QString::number(comparacionesExponencial));
    }

    // Búsqueda interpolativa
    int posicionInterpolativa = indiceActualInterpolativa + ((objetivo - arr[indiceActualInterpolativa]) * (tamano - indiceActualInterpolativa)) / (arr[tamano - 1] - arr[indiceActualInterpolativa]);
    if (posicionInterpolativa >= 0 && posicionInterpolativa < tamano && posicionInterpolativa < elementosGraficosInterpolativa.size()) {
        comparacionesInterpolativa++;
        auto *item = elementosGraficosInterpolativa[posicionInterpolativa];
        item->setDefaultTextColor(arr[posicionInterpolativa] == objetivo ? Qt::green : Qt::red);
        if (arr[posicionInterpolativa] == objetivo) {
            resultadoInterpolativo = "Encontrado en índice: " + QString::number(posicionInterpolativa);
            comparacionesInterpolativa = tamano; // Termina la búsqueda
        }
        ui->resultadoInterpolativoLabel->setText("Comparaciones: " + QString::number(comparacionesInterpolativa));
    }

    // Detener temporizador si todos han terminado
    if (todosTerminaron) {
        timer->stop();
        updateResults();
    }
}

void MainWindow::updateResults()
{
    ui->resultadoLinealLabel->setText(resultadoLineal);
    ui->resultadoBinarioLabel->setText(resultadoBinario);
    ui->resultadoSaltoLabel->setText(resultadoSalto);
    ui->resultadoExponencialLabel->setText(resultadoExponencial);
    ui->resultadoInterpolativoLabel->setText(resultadoInterpolativo);
}
