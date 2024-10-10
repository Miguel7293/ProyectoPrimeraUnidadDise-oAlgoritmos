#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algorithms.h"  // Incluimos el archivo con las implementaciones de los algoritmos
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Crear los widgets de la interfaz
    algorithmComboBox = new QComboBox(this);
    algorithmComboBox->addItem("Boyer-Moore");
    algorithmComboBox->addItem("Knuth-Morris-Pratt (KMP)");
    algorithmComboBox->addItem("Rabin-Karp");
    algorithmComboBox->addItem("Búsqueda por Fuerza Bruta");
    algorithmComboBox->addItem("Aho-Corasick");

    inputTextEdit = new QTextEdit(this);
    patternTextEdit = new QTextEdit(this);
    executeButton = new QPushButton("Ejecutar Algoritmo", this);
    outputTextEdit = new QTextEdit(this);
    outputTextEdit->setReadOnly(true);

    // Layout básico
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new QLabel("Selecciona un Algoritmo:"));
    layout->addWidget(algorithmComboBox);
    layout->addWidget(new QLabel("Introduce el texto:"));
    layout->addWidget(inputTextEdit);
    layout->addWidget(new QLabel("Introduce el patrón:"));
    layout->addWidget(patternTextEdit);
    layout->addWidget(executeButton);
    layout->addWidget(new QLabel("Resultados:"));
    layout->addWidget(outputTextEdit);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Conectar el botón a la función que ejecutará el algoritmo
    connect(executeButton, &QPushButton::clicked, this, &MainWindow::onExecuteAlgorithmClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onExecuteAlgorithmClicked()
{
    QString text = inputTextEdit->toPlainText();
    QString pattern = patternTextEdit->toPlainText();
    QString selectedAlgorithm = algorithmComboBox->currentText();

    if (selectedAlgorithm == "Boyer-Moore") {
        runBoyerMoore(text, pattern);
    } else if (selectedAlgorithm == "Knuth-Morris-Pratt (KMP)") {
        runKMP(text, pattern);
    } else if (selectedAlgorithm == "Rabin-Karp") {
        runRabinKarp(text, pattern);
    } else if (selectedAlgorithm == "Búsqueda por Fuerza Bruta") {
        runBruteForce(text, pattern);
    } else if (selectedAlgorithm == "Aho-Corasick") {
        runAhoCorasick(text, pattern);
    }
}

void MainWindow::runBoyerMoore(const QString& text, const QString& pattern) {
    QString result = Algorithms::BoyerMoore(text, pattern);
    outputTextEdit->setText(result);
}

void MainWindow::runKMP(const QString& text, const QString& pattern) {
    QString result = Algorithms::KMP(text, pattern);
    outputTextEdit->setText(result);
}

void MainWindow::runRabinKarp(const QString& text, const QString& pattern) {
    QString result = Algorithms::RabinKarp(text, pattern);
    outputTextEdit->setText(result);
}

void MainWindow::runBruteForce(const QString& text, const QString& pattern) {
    QString result = Algorithms::BruteForce(text, pattern);
    outputTextEdit->setText(result);
}

void MainWindow::runAhoCorasick(const QString& text, const QString& pattern) {
    QString result = Algorithms::AhoCorasick(text, pattern);
    outputTextEdit->setText(result);
}
