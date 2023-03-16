#include "DrawEllipse.h"
#include "Controller.h"

DrawEllipse::DrawEllipse(Controller *_ctrl, QWidget * parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

DrawEllipse::~DrawEllipse()
{}
