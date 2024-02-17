#include <iostream>
#include <cmath>
#include "CosmicVelocityCalculator.h"
#include <iomanip>

#include <QPushButton>
#include <QApplication>
#include <QWidget>
#include "ui_Widget.h"
#include "CosmicVelocityUI.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MyWidget myWidget;


    myWidget.show();

    return app.exec();
}

int m(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget mainWidget;

    Ui::Form ui;
    ui.setupUi(&mainWidget);

    mainWidget.show();

    return app.exec();
}

