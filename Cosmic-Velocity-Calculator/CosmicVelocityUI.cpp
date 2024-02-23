
#include "CosmicVelocityUI.h"
#include <iostream>
#include "CosmicVelocityCalculator.h"
#include <cmath>
#include <iomanip>
#include "ui_Widget.h"

using namespace std;

double* massCenter;
double* radiusCenter;

double* distanceObjects;

double* mass;
double* radius;


MyWidget::MyWidget(QWidget* parent) : QWidget(parent)
{
	ui.setupUi(this);


	mass = new double;
	radius = new double;
	distanceObjects = new double;
	massCenter = new double;
	radiusCenter = new double;

	*mass = 0.0;
	*radius = 0.0;
	*distanceObjects = 0.0;
	*massCenter = 0.0;
	*radiusCenter = 0.0;

	connect(ui.pushButton, &QPushButton::clicked, this, &MyWidget::onCalculateButtonClicked);

	connect(ui.radioButton, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Mercury
	connect(ui.radioButton_2, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Venus
	connect(ui.radioButton_3, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Earth
	connect(ui.radioButton_4, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Mars
	connect(ui.radioButton_5, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Jupiter
	connect(ui.radioButton_6, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Saturn
	connect(ui.radioButton_7, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedCenterObject); //sun
	connect(ui.radioButton_8, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedCenterObject); // own center
	connect(ui.radioButton_9, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Uranus
	connect(ui.radioButton_10, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Neptun
	connect(ui.radioButton_11, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); // own planet
	connect(ui.radioButton_12, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedCenterObject); // Sagitaruis
	connect(ui.radioButton_13, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedCenterObject); // PROXIMA

	connect(ui.lineEdit, &QLineEdit::textChanged, this, &MyWidget::onRadioButtonSelectedObject);
	connect(ui.lineEdit_2, &QLineEdit::textChanged, this, &MyWidget::onRadioButtonSelectedObject);
	connect(ui.lineEdit_3, &QLineEdit::textChanged, this, &MyWidget::onRadioButtonSelectedCenterObject);
	connect(ui.lineEdit_4, &QLineEdit::textChanged, this, &MyWidget::onRadioButtonSelectedCenterObject);
}


void MyWidget::onRadioButtonSelectedCenterObject()

{
	if (ui.radioButton_7->isChecked())
	{
		cout << "Sun";
		*massCenter = 1988435000;
		*radiusCenter = 695508;
	}
	else if (ui.radioButton_12->isChecked())
	{
		cout << "Sagittarius A*";
		*massCenter = 8540000000000000;
		*radiusCenter = 12000000;
	}
	else if (ui.radioButton_13->isChecked())
	{
		cout << "Proxima Centauri";
		*massCenter = 242800000;
		*radiusCenter = 107280;
	}
	else if (ui.radioButton_8->isChecked())
	{
		bool isFilled1, isFilled2, isFilled3;
		double massValue = ui.lineEdit_3->text().toDouble(&isFilled1);
		double radiusValue = ui.lineEdit_4->text().toDouble(&isFilled2);
		double distanceValue = ui.lineEdit_4->text().toDouble(&isFilled3);

		if (isFilled1 && isFilled2 && isFilled3)
		{
			cout << "Own";
			*massCenter = massValue;
			*radiusCenter = radiusValue;
			*distanceObjects = distanceValue;
		}
	}
}




void MyWidget::onRadioButtonSelectedObject()
{
	if (ui.radioButton->isChecked())
	{
		cout << "Mercury";
		*mass = 3302;
		*radius = 2439;
	}
	else if (ui.radioButton_2->isChecked())
	{
		cout << "Venus";
		*mass = 4868.5;
		*radius = 6052;
	}
	else if (ui.radioButton_3->isChecked())
	{
		cout << "Earth";
		*mass = 5974,2;
		*radius = 6378;
	}
	else if (ui.radioButton_4->isChecked())
	{
		cout << "Mars";
		*mass = 641.85;
		*radius = 3397;
	}
	else if (ui.radioButton_5->isChecked())
	{
		cout << "Jupiter";
		*mass = 1899000;
		*radius = 71398;
	}
	else if (ui.radioButton_6->isChecked())
	{
		cout << "Saturn";
		*mass = 568460;
		*radius = 60000;
	}
	else if (ui.radioButton_9->isChecked())
	{
		cout << "Uranus";
		*mass = 86832;
		*radius = 25000;
	}
	else if (ui.radioButton_10->isChecked())
	{
		cout << "Neptun";
		*mass = 102430;
		*radius = 24300;
	}

	else if (ui.radioButton_11->isChecked())
	{
		bool isFilled1, isFilled2;
		double massValue = ui.lineEdit->text().toDouble(&isFilled1);
		double radiusValue = ui.lineEdit_2->text().toDouble(&isFilled2);
		if (isFilled1 && isFilled2)
		{
			cout << "Own";
			*mass = massValue;
			*radius = radiusValue;
		}
	}
}


void MyWidget::onCalculateButtonClicked()
{
	//FirstCosmicVelocity
	constexpr size_t n = 5;
	int orbits[n] = { 200, 500, 5000, 10000, 100000 };

	ui.label_19->setText(QString::number(firstCosmicVelocity(*mass, *radius, &orbits[0]), 'f', 2) + " km/s");
	ui.label_20->setText(QString::number(firstCosmicVelocity(*mass, *radius, &orbits[1]), 'f', 2) + " km/s");
	ui.label_21->setText(QString::number(firstCosmicVelocity(*mass, *radius, &orbits[2]), 'f', 2) + " km/s");
	ui.label_22->setText(QString::number(firstCosmicVelocity(*mass, *radius, &orbits[3]), 'f', 2) + " km/s");
	ui.label_23->setText(QString::number(firstCosmicVelocity(*mass, *radius, &orbits[4]), 'f', 2) + " km/s");

	//SecondCosmicVelocity
	ui.label_11->setText(QString::number(secondCosmicVelocity(*mass, *radius), 'f', 2) + " km/s");
	//ThirdCosmicVelocity
	ui.label_24->setText(QString::number(thirdCosmicVelocity(*mass, *radius, *massCenter, *radiusCenter, *distanceObjects), 'f', 2) + " km/s");
}

