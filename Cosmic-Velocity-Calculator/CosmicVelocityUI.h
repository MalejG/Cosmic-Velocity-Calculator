#ifndef __COSMICVELOCITYUI_h__
#define __COSMICVELOCITYUI_h__

#include <QWidget>
#include "ui_Widget.h"

#pragma message ("CosmicVelocityUI.h has been included.")


class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget* parent = nullptr);

private slots:
    void onCalculateButtonClicked();
    void onRadioButtonSelectedCenterObject();
    void onRadioButtonSelectedObject();

private:
    Ui::Form ui;

};



#endif __COSMICVELOCITYUI_h__
