#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPainter>
#include <vector>
#include <stack>
#include <tuple>
#include <QElapsedTimer>

#include "sorting_algorithms.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updateAnimations();
    void onStartSortingClicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    qint64 finalTimeBubble = 0;
    qint64 finalTimeQuick = 0;
    qint64 finalTimeMerge = 0;
    qint64 finalTimeInsertion = 0;
    qint64 finalTimeSelection = 0;

    // Arrays de datos
    std::vector<int> dataBubbleSort, dataQuickSort, dataMergeSort, dataInsertionSort, dataSelectionSort;

    // Variables de estado para cada algoritmo
    int comparisonsBubble = 0, comparisonsQuick = 0, comparisonsMerge = 0, comparisonsInsertion = 0, comparisonsSelection = 0;
    int swapsBubble = 0, swapsQuick = 0, swapsInsertion = 0, swapsSelection = 0;

    // Estado paso a paso de los algoritmos
    int bubbleSortI = 0, bubbleSortJ = 0;
    std::stack<std::pair<int, int>> quickSortStack;
    std::stack<std::tuple<int, int, bool>> mergeSortStack;  // Controlar pasos de Merge Sort
    int insertionSortI = 1, insertionSortJ = 0;
    int selectionSortI = 0;

    // Temporizadores para cada algoritmo
    QElapsedTimer elapsedTimerBubble, elapsedTimerQuick, elapsedTimerMerge, elapsedTimerInsertion, elapsedTimerSelection;
    bool sortingStarted = false;

    // Funciones de inicialización y estado
    void resetTimers();
    void generateInitialData();
    void drawArray(QPainter &painter, const std::vector<int>& arr, int algorithmIndex);
    bool isSorted(const std::vector<int>& arr);

    // Algoritmos paso a paso
    void bubbleSortStep();
    void quickSortStep();
    void mergeSortStep();
    void insertionSortStep();
    void selectionSortStep();
};

#endif // MAINWINDOW_H
