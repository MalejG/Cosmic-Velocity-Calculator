
#include "CosmicVelocityUI.h"
#include <iostream>
#include "CosmicVelocityCalculator.h"
#include <cmath>
#include <iomanip>
#include "ui_Widget.h"

using namespace std;

MyWidget::MyWidget(QWidget* parent) : QWidget(parent)
{
    ui.setupUi(this);

    connect(ui.pushButton, &QPushButton::clicked, this, &MyWidget::onCalculateButtonClicked);


    connect(ui.radioButton, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Merury
    connect(ui.radioButton_2, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Venus
    connect(ui.radioButton_3, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Earth
    connect(ui.radioButton_4, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Mars
    connect(ui.radioButton_5, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Jupiter
    connect(ui.radioButton_6, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //saturn
    connect(ui.radioButton_7, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedCenterObject); //sun
    connect(ui.radioButton_8, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); // own planet
    connect(ui.radioButton_9, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Uranus
    connect(ui.radioButton_10, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Neptun
    connect(ui.radioButton_11, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedCenterObject); // own center
    connect(ui.radioButton_12, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedCenterObject); // Sagitaruis
    connect(ui.radioButton_13, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedCenterObject); // PROXIMA

}


void MyWidget::onRadioButtonSelectedCenterObject()
{
    cout << "Hello Cosmic Velocity Calculator! Center Object\n";
}



void MyWidget::onRadioButtonSelectedObject()
{
    cout << "Hello Cosmic Velocity Calculator! Object\n";
}


void MyWidget::onCalculateButtonClicked()
{
    cout << "Hello Cosmic Velocity Calculator! Click\n";
    
}

