//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Zein Salah, on 24.02.2021
//


#include "RenderWidget.h"
#include <QPainter>
#include<cmath>
#include<iostream>
using namespace std;

RenderWidget::RenderWidget(QWidget* parent) : QWidget(parent)
{
	// to be implemeted later
}

QSize RenderWidget::minimumSizeHint() const
{
	return QSize(100, 100);
}

QSize RenderWidget::sizeHint() const
{
	return QSize(600, 600);
}

void RenderWidget::paintEvent(QPaintEvent*)
{
	QPainter painter(this);

	//    painter.setRenderHint(QPainter::Antialiasing, false);
	QColor color(0, 0, 0);

	painter.setPen(QPen(color, 3));

	painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

	MicroscopeDrawer microscopeDrawer = MicroscopeDrawer(&painter);
	microscopeDrawer.draw();

}
