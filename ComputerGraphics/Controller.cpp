#include "Controller.h"
#include <iostream>
using namespace cv;
using namespace std;

Controller::Controller()
{
	image = new Mat(400, 400, CV_8UC1, Scalar(0));
	image_large = new Mat(1600, 1600, CV_8UC1, Scalar(0));
	drawLine = new DrawLine(this, nullptr);
	drawRound = new DrawRound(this, nullptr);
	drawEllipse = new DrawEllipse(this, nullptr);

	widget = new Widget(nullptr, this);
}

Controller::~Controller()
{
}

void Controller::run() {
	widget->show();
	imshow("图像绘制", *image_large);
}

void Controller::drawPoint(int x, int y) {
	qDebug()<< "x:" << x << "y:" << y;
	// 首先x,y不得超过1000
	if (x > 400 || y > 400) {
		return;
	}
	// y坐标转换 0,0在左下角
	
	y = 399 - y;

	// 调整为黑色
	//image->at<uchar>(y, x) = 255;

	// 放大图像 遍历image_large 将image中的点放大
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			image_large->at<uchar>(y * 4 + i, x * 4 + j) = 255;
		}
	}



	// 如果widget是关闭状态
	imshow("图像绘制", *image_large);

}

void Controller::clear() {
	// 全部置为0
	//image->setTo(0);
	image_large->setTo(0);
	imshow("图像绘制", *image_large);
}