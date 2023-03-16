#pragma once

#include <QWidget>
#include "ui_DrawEllipse.h"

class Controller;

class DrawEllipse : public QWidget
{
	Q_OBJECT

public:
	DrawEllipse(Controller *_ctrl,QWidget *parent);
	~DrawEllipse();

	Controller* ctrl_;

private:
	Ui::DrawEllipseClass ui;
};
