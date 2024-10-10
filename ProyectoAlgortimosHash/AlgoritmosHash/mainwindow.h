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
    void onGenerateHashClicked();  // Generar el hash seleccionado

private:
    Ui::MainWindow *ui;

    // Widgets de la interfaz
    QComboBox *hashComboBox;       // Selección del algoritmo hash
    QTextEdit *inputTextEdit;      // Texto en el que generar el hash
    QPushButton *generateButton;   // Botón para generar el hash
    QTextEdit *outputTextEdit;     // Resultado del hash generado

    // Funciones para cada algoritmo hash
    void generateMD5(const QString &text);
    void generateSHA1(const QString &text);
    void generateSHA256(const QString &text);
    void generateSHA512(const QString &text);
    void generateBasicHash(const QString &text);
};

#endif // MAINWINDOW_H
