#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget.h"
class Controller;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent,Controller * ctrl);
    ~Widget();

private:
    Ui::WidgetClass ui;
};
