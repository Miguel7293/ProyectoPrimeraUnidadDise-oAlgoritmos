#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onExecuteAlgorithmClicked(); // Ejecutar el algoritmo seleccionado

private:
    Ui::MainWindow *ui;

    // Widgets de la interfaz
    QComboBox *algorithmComboBox;    // Selección del algoritmo
    QTextEdit *inputTextEdit;        // Texto en el que buscar
    QTextEdit *patternTextEdit;      // Patrón a buscar
    QPushButton *executeButton;      // Botón de ejecutar
    QTextEdit *outputTextEdit;       // Resultados de la búsqueda

    // Funciones para cada algoritmo
    void runBoyerMoore(const QString& text, const QString& pattern);
    void runKMP(const QString& text, const QString& pattern);
    void runRabinKarp(const QString& text, const QString& pattern);
    void runBruteForce(const QString& text, const QString& pattern);
    void runAhoCorasick(const QString& text, const QString& pattern);
};

#endif // MAINWINDOW_H
