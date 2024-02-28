
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
	connect(ui.radioButton_9, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Uranus
	connect(ui.radioButton_10, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); //Neptun
	connect(ui.radioButton_11, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedObject); // own planet


	connect(ui.radioButton_7, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedCenterObject); //sun
	connect(ui.radioButton_8, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedCenterObject); // own center
	connect(ui.radioButton_12, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedCenterObject); // Sagitaruis
	connect(ui.radioButton_13, &QRadioButton::toggled, this, &MyWidget::onRadioButtonSelectedCenterObject); // PROXIMA

	connect(ui.lineEdit_3, &QLineEdit::textChanged, this, &MyWidget::onRadioButtonSelectedCenterObject);
	connect(ui.lineEdit_4, &QLineEdit::textChanged, this, &MyWidget::onRadioButtonSelectedCenterObject);

	connect(ui.lineEdit, &QLineEdit::textChanged, this, &MyWidget::onRadioButtonSelectedObject);
	connect(ui.lineEdit_2, &QLineEdit::textChanged, this, &MyWidget::onRadioButtonSelectedObject);
	connect(ui.lineEdit_5, &QLineEdit::textChanged, this, &MyWidget::onRadioButtonSelectedObject);
	connect(ui.lineEdit_6, &QLineEdit::textChanged, this, &MyWidget::onRadioButtonSelectedObject);// Altitude

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
		bool isFilled1, isFilled2;
		double massValue = ui.lineEdit_4->text().toDouble(&isFilled1);
		double radiusValue = ui.lineEdit_3->text().toDouble(&isFilled2);

		if (isFilled1 && isFilled2)
		{
			cout << "Own";
			*massCenter = massValue;
			*radiusCenter = radiusValue;
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
		*distanceObjects = 0.39;

	}
	else if (ui.radioButton_2->isChecked())
	{
		cout << "Venus";
		*mass = 4868.5;
		*radius = 6052;
		*distanceObjects = 0.72;
	}
	else if (ui.radioButton_3->isChecked())
	{
		cout << "Earth";
		*mass = 5974,2;
		*radius = 6378;
		*distanceObjects = 1;
	}
	else if (ui.radioButton_4->isChecked())
	{
		cout << "Mars";
		*mass = 641.85;
		*radius = 3397;
		*distanceObjects = 1.52;
	}
	else if (ui.radioButton_5->isChecked())
	{
		cout << "Jupiter";
		*mass = 1899000;
		*radius = 71398;
		*distanceObjects = 5.2;
	}
	else if (ui.radioButton_6->isChecked())
	{
		cout << "Saturn";
		*mass = 568460;
		*radius = 60000;
		*distanceObjects = 9.54;
	}
	else if (ui.radioButton_9->isChecked())
	{
		cout << "Uranus";
		*mass = 86832;
		*radius = 25000;
		*distanceObjects = 19.22;
	}
	else if (ui.radioButton_10->isChecked())
	{
		cout << "Neptun";
		*mass = 102430;
		*radius = 24300;
		*distanceObjects = 30.06;
	}

	else if (ui.radioButton_11->isChecked())
	{
		bool isFilled1, isFilled2, isFilled3;
		double massValue = ui.lineEdit_2->text().toDouble(&isFilled1);
		double radiusValue = ui.lineEdit->text().toDouble(&isFilled2);
		double distanceValue = ui.lineEdit_5->text().toDouble(&isFilled3);

		if (isFilled1 && isFilled2 && isFilled3)
		{
			cout << "Own";
			*mass = massValue;
			*radius = radiusValue;
			*distanceObjects = distanceValue;

		}
	}
}


void MyWidget::onCalculateButtonClicked()
{

	//FirstCosmicVelocity
	constexpr size_t n = 5;
	double userAltitude;
	
	bool ok;
	userAltitude = ui.lineEdit_6->text().toDouble(&ok);

	if (!ok) 
	{
		userAltitude = 0;
	}

	double orbits[n] = { 200, 500, 5000, 10000, userAltitude };
	QLabel* qtlabels[n] = { ui.label_19, ui.label_20, ui.label_21, ui.label_22, ui.label_23 };
	
	for (size_t i = 0; i < n; ++i) 
	{
		double velocity = firstCosmicVelocity(*mass, *radius, &orbits[i]);
		if (velocity == -1) {
			qtlabels[i]->setText("Exceeds light limit");
		}
		else {
			qtlabels[i]->setText(QString::number(velocity, 'f', 2) + " km/s");
		}
	}

	//SecondCosmicVelocity
	double secondVelocity = secondCosmicVelocity(*mass, *radius);
	
	if (secondVelocity == -1) 
	{
		ui.label_11->setText("Exceeds light limit");
	}
	else 
	{
		ui.label_11->setText(QString::number(secondVelocity, 'f', 2) + " km/s");
	}
	
	//ThirdCosmicVelocity
	double thirdVelocity = thirdCosmicVelocity(*mass, *radius, *massCenter, *radiusCenter, *distanceObjects);
	
	if (thirdVelocity == -1) 
	{
		ui.label_24->setText("Exceeds light limit");
	}
	else 
	{
		ui.label_24->setText(QString::number(thirdVelocity, 'f', 2) + " km/s");
	}
}
