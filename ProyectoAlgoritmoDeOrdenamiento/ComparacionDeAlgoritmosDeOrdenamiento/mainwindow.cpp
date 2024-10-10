#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Inicializar el temporizador para las animaciones
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateAnimations);

    // Conectar el botón de inicio
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::onStartSortingClicked);

    // Generar los datos iniciales para los algoritmos
    generateInitialData();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onStartSortingClicked() {
    if (!sortingStarted) {
        sortingStarted = true;

        // Reiniciar contadores de comparaciones y cronómetros
        resetTimers();

        // Iniciar el temporizador para las animaciones
        timer->start(100);  // Actualización cada 100 ms
    }
}

void MainWindow::resetTimers() {
    comparisonsBubble = comparisonsQuick = comparisonsMerge = comparisonsInsertion = comparisonsSelection = 0;
    swapsBubble = swapsQuick = swapsInsertion = swapsSelection = 0;

    elapsedTimerBubble.start();
    elapsedTimerQuick.start();
    elapsedTimerMerge.start();
    elapsedTimerInsertion.start();
    elapsedTimerSelection.start();
}


void MainWindow::generateInitialData() {
    // Generar los mismos datos iniciales para todos los algoritmos
    dataBubbleSort = { 45, 12, 78, 34, 23, 89, 56, 10 };
    dataQuickSort = dataBubbleSort;
    dataMergeSort = dataBubbleSort;
    dataInsertionSort = dataBubbleSort;
    dataSelectionSort = dataBubbleSort;

    // Inicializar estado para Bubble Sort
    bubbleSortI = 0;
    bubbleSortJ = 0;

    // Inicializar estado para Quick Sort (pila)
    quickSortStack = std::stack<std::pair<int, int>>();  // Limpiar pila
    quickSortStack.push({0, dataQuickSort.size() - 1});

    // Inicializar estado para Merge Sort (pila)
    mergeSortStack = std::stack<std::tuple<int, int, bool>>();  // Limpiar pila
    mergeSortStack.push(std::make_tuple(0, dataMergeSort.size() - 1, false));

    // Inicializar estado para Insertion Sort
    insertionSortI = 1;
    insertionSortJ = 0;

    // Inicializar estado para Selection Sort
    selectionSortI = 0;
}


void MainWindow::updateAnimations() {
    // Bubble Sort
    if (!isSorted(dataBubbleSort)) {
        bubbleSortStep();
    } else if (elapsedTimerBubble.isValid()) {
        finalTimeBubble = elapsedTimerBubble.elapsed(); // Capturar el tiempo final
        elapsedTimerBubble.invalidate(); // Detener el tiempo
    }

    // Quick Sort
    if (!isSorted(dataQuickSort)) {
        quickSortStep();
    } else if (elapsedTimerQuick.isValid()) {
        finalTimeQuick = elapsedTimerQuick.elapsed(); // Capturar el tiempo final
        elapsedTimerQuick.invalidate();
    }

    // Merge Sort
    if (!isSorted(dataMergeSort)) {
        mergeSortStep();
    } else if (elapsedTimerMerge.isValid()) {
        finalTimeMerge = elapsedTimerMerge.elapsed(); // Capturar el tiempo final
        elapsedTimerMerge.invalidate();
    }

    // Insertion Sort
    if (!isSorted(dataInsertionSort)) {
        insertionSortStep();
    } else if (elapsedTimerInsertion.isValid()) {
        finalTimeInsertion = elapsedTimerInsertion.elapsed(); // Capturar el tiempo final
        elapsedTimerInsertion.invalidate();
    }

    // Selection Sort
    if (!isSorted(dataSelectionSort)) {
        selectionSortStep();
    } else if (elapsedTimerSelection.isValid()) {
        finalTimeSelection = elapsedTimerSelection.elapsed(); // Capturar el tiempo final
        elapsedTimerSelection.invalidate();
    }

    // Forzar la actualización de la pantalla
    update();

    // Si todos los algoritmos han terminado, detener el temporizador global
    if (isSorted(dataBubbleSort) && isSorted(dataQuickSort) && isSorted(dataMergeSort) &&
        isSorted(dataInsertionSort) && isSorted(dataSelectionSort)) {
        timer->stop();
        sortingStarted = false;
    }
}





bool MainWindow::isSorted(const std::vector<int>& arr ) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    // Dibujar los arrays de los algoritmos
    drawArray(painter, dataBubbleSort, 0);
    drawArray(painter, dataQuickSort, 1);
    drawArray(painter, dataMergeSort, 2);
    drawArray(painter, dataInsertionSort, 3);
    drawArray(painter, dataSelectionSort, 4);

    // Mostrar los contadores de comparaciones y el tiempo (usar el tiempo final si está disponible)
    painter.drawText(50, 400, QString("BubbleSort Comparisons: %1").arg(comparisonsBubble));
    painter.drawText(50, 420, QString("Time: %1 ms").arg(elapsedTimerBubble.isValid() ? elapsedTimerBubble.elapsed() : finalTimeBubble));

    painter.drawText(300, 400, QString("QuickSort Comparisons: %1").arg(comparisonsQuick));
    painter.drawText(300, 420, QString("Time: %1 ms").arg(elapsedTimerQuick.isValid() ? elapsedTimerQuick.elapsed() : finalTimeQuick));

    painter.drawText(550, 400, QString("MergeSort Comparisons: %1").arg(comparisonsMerge));
    painter.drawText(550, 420, QString("Time: %1 ms").arg(elapsedTimerMerge.isValid() ? elapsedTimerMerge.elapsed() : finalTimeMerge));

    painter.drawText(800, 400, QString("InsertionSort Comparisons: %1").arg(comparisonsInsertion));
    painter.drawText(800, 420, QString("Time: %1 ms").arg(elapsedTimerInsertion.isValid() ? elapsedTimerInsertion.elapsed() : finalTimeInsertion));

    painter.drawText(1050, 400, QString("SelectionSort Comparisons: %1").arg(comparisonsSelection));
    painter.drawText(1050, 420, QString("Time: %1 ms").arg(elapsedTimerSelection.isValid() ? elapsedTimerSelection.elapsed() : finalTimeSelection));
}



void MainWindow::drawArray(QPainter &painter, const std::vector<int>& arr, int algorithmIndex) {
    int baseX = 50 + algorithmIndex * 250; // Aumentar el espacio entre arrays
    int baseY = 300;

    for (int i = 0; i < arr.size(); ++i) {
        int height = arr[i] * 2; // Escalar por simplicidad
        painter.drawRect(baseX + i * 20, baseY - height, 18, height);
    }
}

// Bubble Sort Paso a Paso
void MainWindow::bubbleSortStep() {
    SortingAlgorithms::bubbleSortStep(dataBubbleSort, bubbleSortI, bubbleSortJ, comparisonsBubble, swapsBubble);
}

// Quick Sort Paso a Paso
void MainWindow::quickSortStep() {
    SortingAlgorithms::quickSortStep(dataQuickSort, quickSortStack, comparisonsQuick, swapsQuick);
}

// Merge Sort Paso a Paso
void MainWindow::mergeSortStep() {
    SortingAlgorithms::mergeSortStep(dataMergeSort, mergeSortStack, comparisonsMerge);
}

// Insertion Sort Paso a Paso
void MainWindow::insertionSortStep() {
    SortingAlgorithms::insertionSortStep(dataInsertionSort, insertionSortI, insertionSortJ, comparisonsInsertion, swapsInsertion);
}

// Selection Sort Paso a Paso
void MainWindow::selectionSortStep() {
    SortingAlgorithms::selectionSortStep(dataSelectionSort, selectionSortI, comparisonsSelection, swapsSelection);
}
