#include "Widget.h"
#include "DrawLine.h"
#include "Controller.h"

Widget::Widget(QWidget* parent, Controller* ctrl)
    : QWidget(parent)
{
    ui.setupUi(this);

    connect(ui.pushButton,&QPushButton::clicked,ctrl->drawLine ,&QWidget::show);
    connect(ui.pushButton_2, &QPushButton::clicked, ctrl->drawRound, &QWidget::show);
    connect(ui.pushButton_3, &QPushButton::clicked, ctrl->drawEllipse, &QWidget::show);

}

Widget::~Widget()
{
  
}

