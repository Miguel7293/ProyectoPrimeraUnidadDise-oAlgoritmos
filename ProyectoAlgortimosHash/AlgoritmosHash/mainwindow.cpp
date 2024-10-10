#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hash_algorithms.h"  // Incluimos el archivo con las implementaciones de los hash
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Crear los widgets de la interfaz
    hashComboBox = new QComboBox(this);
    hashComboBox->addItem("MD5");
    hashComboBox->addItem("SHA-1");
    hashComboBox->addItem("SHA-256");
    hashComboBox->addItem("SHA-512");
    hashComboBox->addItem("Función Hash Básica");

    inputTextEdit = new QTextEdit(this);
    generateButton = new QPushButton("Generar Hash", this);
    outputTextEdit = new QTextEdit(this);
    outputTextEdit->setReadOnly(true);

    // Layout básico
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(new QLabel("Selecciona un Algoritmo Hash:"));
    layout->addWidget(hashComboBox);
    layout->addWidget(new QLabel("Introduce el texto:"));
    layout->addWidget(inputTextEdit);
    layout->addWidget(generateButton);
    layout->addWidget(new QLabel("Resultado del Hash:"));
    layout->addWidget(outputTextEdit);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Conectar el botón a la función que generará el hash
    connect(generateButton, &QPushButton::clicked, this, &MainWindow::onGenerateHashClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onGenerateHashClicked()
{
    QString text = inputTextEdit->toPlainText();
    QString selectedHash = hashComboBox->currentText();

    if (selectedHash == "MD5") {
        generateMD5(text);
    } else if (selectedHash == "SHA-1") {
        generateSHA1(text);
    } else if (selectedHash == "SHA-256") {
        generateSHA256(text);
    } else if (selectedHash == "SHA-512") {
        generateSHA512(text);
    } else if (selectedHash == "Función Hash Básica") {
        generateBasicHash(text);
    }
}

void MainWindow::generateMD5(const QString &text) {
    QString result = HashAlgorithms::MD5(text);
    outputTextEdit->setText(result);
}

void MainWindow::generateSHA1(const QString &text) {
    QString result = HashAlgorithms::SHA1(text);
    outputTextEdit->setText(result);
}

void MainWindow::generateSHA256(const QString &text) {
    QString result = HashAlgorithms::SHA256(text);
    outputTextEdit->setText(result);
}

void MainWindow::generateSHA512(const QString &text) {
    QString result = HashAlgorithms::SHA512(text);
    outputTextEdit->setText(result);
}

void MainWindow::generateBasicHash(const QString &text) {
    QString result = HashAlgorithms::BasicHash(text);
    outputTextEdit->setText(result);
}
