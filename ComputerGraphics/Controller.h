#pragma once
#include "Widget.h"
#include <opencv2/opencv.hpp>
#include "DrawLine.h"
#include "DrawRound.h"
#include "DrawEllipse.h"
using namespace cv;

class Controller
{
public:
	Controller();
	~Controller();
	void run();
	void drawPoint(int x, int y);
	void clear();
	// 主窗口
	Widget* widget;
	// 画线窗口
	DrawLine *drawLine;
	// 画圆
	DrawRound *drawRound;
	// 画椭圆
	DrawEllipse *drawEllipse;


	// 图像
	Mat* image;
	// 放大后的图像
	Mat* image_large;

};

