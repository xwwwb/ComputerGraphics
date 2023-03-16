#pragma once

#include <QWidget>
#include "ui_DrawLine.h"

class Controller;


class DrawLine : public QWidget
{
	Q_OBJECT

public:
	DrawLine(Controller* ctrl_, QWidget* parent);
	~DrawLine();
	void algorithmDDA();
	void algorithmBresenham();
	void algorithmBresenhamImprove();
	void randomLine();
	Controller* _ctrl;

private:
	Ui::DrawLineClass ui;	
};
