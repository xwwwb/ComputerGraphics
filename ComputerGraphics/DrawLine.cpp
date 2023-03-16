#include "DrawLine.h"
#include "Controller.h"
#include <QSpinBox>
#include <QMessageBox>

DrawLine::DrawLine(Controller* ctrl_, QWidget* parent)
{
	ui.setupUi(this);
	_ctrl = ctrl_;
	connect(ui.pushButton, &QPushButton::clicked, this, &DrawLine::algorithmDDA);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &DrawLine::randomLine);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &DrawLine::algorithmBresenham);
	connect(ui.pushButton_3, &QPushButton::clicked, this, &DrawLine::algorithmBresenhamImprove);
}

DrawLine::~DrawLine()
{}
void DrawLine::randomLine() {
	int b = rand() % 400;
	ui.spinBox->setValue(b);
	double list_2[20] = { 0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.5,2,3,4,5,6,7,8,9,10 };
	// 随意选一个作为k
	double k = list_2[rand() % 20];
	ui.doubleSpinBox->setValue(k);
}

void DrawLine::algorithmDDA() {
	_ctrl->clear();
	double k = ui.doubleSpinBox->value();
	int b = ui.spinBox->value();
	if (k <= 0) {
		QMessageBox::information(nullptr, "请输入k值", "请输入k值");
		return;
	}
	if (b >= 399) {
		QMessageBox::information(nullptr, "b值不能大于399", "b值不能大于399");
		return;
	}
	double x = 0;
	double y = b;

	if (k > 1) {
		while (y < 399) {
			_ctrl->drawPoint((int)(x + 1 / k + 0.5), int(y + 1));
			y = y + 1;
			x = x + 1 / k;
			waitKey(10);
		}
	}
	else if (k == 1) {
		while (y < 399) {
			_ctrl->drawPoint(x, y); waitKey(10);
			x = x + 1;
			y = y + 1;
		}
	}
	else {
		while (x < 399) {
			int dx = x + 1;
			int dy = (int)(y + k + 0.5);
			_ctrl->drawPoint(dx, dy);
			x = x + 1;
			y = y + k;
			waitKey(10);
		}
	}

	QMessageBox::information(nullptr, "生成完成", "生成完成");
}

void DrawLine::algorithmBresenham() {
	_ctrl->clear();
	double k = ui.doubleSpinBox->value();
	int b = ui.spinBox->value();
	if (k <= 0) {
		QMessageBox::information(nullptr, "请输入k值", "请输入k值");
		return;
	}
	if (b >= 399) {
		QMessageBox::information(nullptr, "b值不能大于399", "b值不能大于399");
		return;
	}
	int x = 0;
	int y = b;
	int x1 = 399;
	int y1 = (int)(k * 399 + b + 0.5);
	int D = (x1 - x) - 2 * (y1 - y);

	if (k >= 1) {
		while (y < 399) {
			_ctrl->drawPoint(x, y);
			if (D < 0) {
				y = y + 1;
				x = x + 1;
				D = D + 2 * (y1 - y) - 2 * (x1 - x);
			}
			else {
				y = y + 1;
				D = D - 2 * (x1 - x);
			}
			waitKey(10);
		}
	}
	else {
		while (x < 399) {
			_ctrl->drawPoint(x, y);
			if (D < 0) {
				x = x + 1;
				y = y + 1;
				D = D + 2 * (x1 - x) - 2 * (y1 - y);
			}
			else {
				x = x + 1;
				D = D - 2 * (y1 - y);
			}
			waitKey(10);
		}
	}

	QMessageBox::information(nullptr, "生成完成", "生成完成");
}

void DrawLine::algorithmBresenhamImprove() {
	_ctrl->clear();
	double k = ui.doubleSpinBox->value();
	int b = ui.spinBox->value();
	if (k <= 0) {
		QMessageBox::information(nullptr, "请输入k值", "请输入k值");
		return;
	}
	if (b >= 399) {
		QMessageBox::information(nullptr, "b值不能大于399", "b值不能大于399");
		return;
	}

	int x = 0;
	int y = b;
	int x1 = 399;
	int y1 = (int)(k * 399 + b + 0.5);
	int dx = x1 - x;
	int dy = y1 - y;
	int e = -1 * dx;
	if (k < 1) {
		while (x < 399) {
			_ctrl->drawPoint(x, y);
			e = e + 2 * dy;
			if (e > 0) {
				x = x + 1;
				y = y + 1;
				e = e - 2 * dx;
			}
			else {
				x = x + 1;
			}
			waitKey(10);
		}
	}
	else {
		// 交换x y 
		while (y < 399) {
			_ctrl->drawPoint(x, y);
			e = e + 2 * dx;
			if (e > 0) {
				x = x + 1;
				y = y + 1;
				e = e - 2 * dy;
			}
			else {
				y = y + 1;
			}
			waitKey(10);
		}
	}


	QMessageBox::information(nullptr, "生成完成", "生成完成");
}