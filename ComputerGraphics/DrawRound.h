#pragma once

#include <QWidget>
#include "ui_DrawRound.h"

class Controller;

class DrawRound : public QWidget
{
	Q_OBJECT

public:
	DrawRound(Controller* ctrl_, QWidget* parent);
	~DrawRound();
	void randomR();
	Controller* _ctrl;

	void algorithmEquation();
	void algorithmEquationPolar();
	void algorithmBresenham();

	void drawFullRound(int x, int y);

private:
	Ui::DrawRoundClass ui;
};
