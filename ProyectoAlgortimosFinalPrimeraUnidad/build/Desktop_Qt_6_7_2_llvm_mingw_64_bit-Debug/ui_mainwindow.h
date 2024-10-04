/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnBuscar;
    QLineEdit *lineEdit;
    QLabel *resultadoLinealLabel;
    QLabel *resultadoBinarioLabel;
    QLabel *resultadoSaltoLabel;
    QLabel *resultadoExponencialLabel;
    QLabel *resultadoInterpolativoLabel;
    QGraphicsView *graphicsViewBinario;
    QGraphicsView *graphicsViewSalto;
    QGraphicsView *graphicsViewExponencial;
    QGraphicsView *graphicsViewInterpolativa;
    QGraphicsView *graphicsViewLineal;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnBuscar = new QPushButton(centralwidget);
        btnBuscar->setObjectName("btnBuscar");
        btnBuscar->setGeometry(QRect(70, 290, 80, 24));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(60, 250, 113, 24));
        resultadoLinealLabel = new QLabel(centralwidget);
        resultadoLinealLabel->setObjectName("resultadoLinealLabel");
        resultadoLinealLabel->setGeometry(QRect(430, 120, 251, 21));
        resultadoBinarioLabel = new QLabel(centralwidget);
        resultadoBinarioLabel->setObjectName("resultadoBinarioLabel");
        resultadoBinarioLabel->setGeometry(QRect(430, 220, 271, 16));
        resultadoSaltoLabel = new QLabel(centralwidget);
        resultadoSaltoLabel->setObjectName("resultadoSaltoLabel");
        resultadoSaltoLabel->setGeometry(QRect(430, 300, 241, 16));
        resultadoExponencialLabel = new QLabel(centralwidget);
        resultadoExponencialLabel->setObjectName("resultadoExponencialLabel");
        resultadoExponencialLabel->setGeometry(QRect(430, 390, 251, 16));
        resultadoInterpolativoLabel = new QLabel(centralwidget);
        resultadoInterpolativoLabel->setObjectName("resultadoInterpolativoLabel");
        resultadoInterpolativoLabel->setGeometry(QRect(430, 470, 251, 16));
        graphicsViewBinario = new QGraphicsView(centralwidget);
        graphicsViewBinario->setObjectName("graphicsViewBinario");
        graphicsViewBinario->setGeometry(QRect(360, 160, 421, 51));
        graphicsViewSalto = new QGraphicsView(centralwidget);
        graphicsViewSalto->setObjectName("graphicsViewSalto");
        graphicsViewSalto->setGeometry(QRect(360, 240, 421, 51));
        graphicsViewExponencial = new QGraphicsView(centralwidget);
        graphicsViewExponencial->setObjectName("graphicsViewExponencial");
        graphicsViewExponencial->setGeometry(QRect(360, 330, 421, 51));
        graphicsViewInterpolativa = new QGraphicsView(centralwidget);
        graphicsViewInterpolativa->setObjectName("graphicsViewInterpolativa");
        graphicsViewInterpolativa->setGeometry(QRect(360, 410, 421, 51));
        graphicsViewLineal = new QGraphicsView(centralwidget);
        graphicsViewLineal->setObjectName("graphicsViewLineal");
        graphicsViewLineal->setGeometry(QRect(360, 60, 421, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 70, 91, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 180, 91, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(260, 250, 91, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(220, 340, 121, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(210, 430, 131, 21));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 220, 151, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnBuscar->setText(QCoreApplication::translate("MainWindow", "Buscar", nullptr));
        resultadoLinealLabel->setText(QCoreApplication::translate("MainWindow", "Num. comparaciones", nullptr));
        resultadoBinarioLabel->setText(QCoreApplication::translate("MainWindow", "Num. comparaciones", nullptr));
        resultadoSaltoLabel->setText(QCoreApplication::translate("MainWindow", "Num. comparaciones", nullptr));
        resultadoExponencialLabel->setText(QCoreApplication::translate("MainWindow", "Num. comparaciones", nullptr));
        resultadoInterpolativoLabel->setText(QCoreApplication::translate("MainWindow", "Num. comparaciones", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Busqueda Lineal", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Busqueda Binaria", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Jump Search", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Busqueda Exponencial", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Busqueda Interpolativa", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "{3, 6, 8, 12, 14, 17, 19, 23}", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
