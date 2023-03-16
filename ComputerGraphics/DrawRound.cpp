#include "DrawRound.h"
#include "Controller.h"
#include <QSpinBox>
#include <QMessageBox>
#include <cmath>
using namespace std;

const double PI = 3.1415926;

DrawRound::DrawRound(Controller* ctrl_, QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	_ctrl = ctrl_;
	connect(ui.pushButton, &QPushButton::clicked, this, &DrawRound::algorithmEquation);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &DrawRound::algorithmEquationPolar);
	connect(ui.pushButton_3, &QPushButton::clicked, this, &DrawRound::randomR);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &DrawRound::algorithmBresenham);

}

DrawRound::~DrawRound()
{}

void DrawRound::randomR() {
	int r = rand() % 200;
	ui.spinBox->setValue(r);
}

void DrawRound::drawFullRound(int x, int y) {
	_ctrl->drawPoint(x + 200, y + 200);
	_ctrl->drawPoint(y + 200, x + 200);

	_ctrl->drawPoint((-1 * x) + 200, y + 200);
	_ctrl->drawPoint((-1 * y) + 200, x + 200);

	_ctrl->drawPoint(x + 200, (-1 * y) + 200);
	_ctrl->drawPoint(y + 200, (-1 * x) + 200);

	_ctrl->drawPoint((-1 * x) + 200, (-1 * y) + 200);
	_ctrl->drawPoint((-1 * y) + 200, (-1 * x) + 200);
}

void DrawRound::algorithmEquation() {
	_ctrl->clear();
	int r = ui.spinBox->value();

	if (r <= 0) {
		QMessageBox::information(nullptr, "请输入k值", "请输入k值");
		return;
	}

	if (r > 199) {
		QMessageBox::information(nullptr, "r值不能超过199", "r值不能超过199");
	}
	int x = 0;
	int y = r;

	double edge = r / sqrt(2);
	int edgeInt = ceil(edge);
	while (x < edgeInt+1) {
		drawFullRound(x, y);
		x = x + 1;
		y = round(sqrt(r * r - x * x));
		waitKey(10);
	}

	QMessageBox::information(nullptr, "生成完成", "生成完成");
}

void DrawRound::algorithmEquationPolar()
{
	_ctrl->clear();
	int r = ui.spinBox->value();

	if (r <= 0) {
		QMessageBox::information(nullptr, "请输入k值", "请输入k值");
		return;
	}

	if (r > 199) {
		QMessageBox::information(nullptr, "r值不能超过199", "r值不能超过199");
	}
	int x = 0;
	int y = r;

	double edge = r / sqrt(2);
	int edgeInt = ceil(edge);

	double dTheta = 40.0/edgeInt;
	double theta = 90;
	while (theta > 45) {
		drawFullRound(x, y);
		theta -= dTheta;
		x = round(r * cos(theta / 180 * PI));
		y = round(r * sin(theta / 180 * PI));
		waitKey(10);
	}

	QMessageBox::information(nullptr, "生成完成", "生成完成");
}

void DrawRound::algorithmBresenham() {
	_ctrl->clear();
	int r = ui.spinBox->value();

	if (r <= 0) {
		QMessageBox::information(nullptr, "请输入k值", "请输入k值");
		return;
	}

	if (r > 199) {
		QMessageBox::information(nullptr, "r值不能超过199", "r值不能超过199");
	}
	int x = 0;
	int y = r;
	int d = 1 - r;

	double edge = r / sqrt(2);
	int edgeInt = ceil(edge);

	while (x < edgeInt+1) {
		drawFullRound(x, y);
		if (d < 0) {
			d = d + 2 * x + 3;
			x = x + 1;
		}
		else {
			d = d + 2 * (x - y) + 5;
			x = x + 1;
			y = y - 1;
		}
		waitKey(10);
	}

	QMessageBox::information(nullptr, "生成完成", "生成完成");
}