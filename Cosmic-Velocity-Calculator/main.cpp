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