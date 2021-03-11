//
// copyright 2018 Palestine Polytechnic Univeristy
//
// This software can be used and/or modified for academich use as long as 
// this commented part is listed
//
// Last modified by: Zein Salah, on 24.02.2021
//


#include "RenderWidget.h"
#include "PPUPainter.h"
#include <QPainter>
#include<cmath>
#include<iostream>
using namespace std;

RenderWidget::RenderWidget(QWidget *parent) : QWidget(parent)
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

void RenderWidget::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

 //    painter.setRenderHint(QPainter::Antialiasing, false);
  QColor color(0, 0, 0);
  painter.setPen(color);

  painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
  

 // myDrawLine(50, 70, 500, 370);
  //myDrawLineUsingBresenhamAlgorithm(50, 70, 500, 370);
  myDrawCircle(200, 200,-60,120, 50);
  myDrawCircle(200, 200, -60, 59, 70);
  myDrawCircle(215, 139, 0, 360, 20);
  myDrawCircle(215, 139, 0, 360, 15);

  myDrawCircle(200, 320, -180, 0, 70);
  myDrawCircle(200, 200, 121, 142, 70);
  myDrawCircle(200, 280, 0, 360, 18);

  myDrawLineUsingBresenhamAlgorithm(100, 300, 132, 300);
  myDrawLineUsingBresenhamAlgorithm(268, 300, 300, 300);

  myDrawLineUsingBresenhamAlgorithm(100, 230, 205, 230);
  myDrawLineUsingBresenhamAlgorithm(100, 320, 300, 320);
  myDrawLineUsingBresenhamAlgorithm(100, 243, 205, 243);




  myDrawLine(100,300,100,320);
  myDrawLine(300, 300, 300, 320);
  myDrawLine(100, 230, 100, 243);
  myDrawLine(205, 230, 205, 243);
  myDrawLine(195, 170, 205, 155);
  myDrawLine(225, 121, 250, 85);
  myDrawLine(230, 70, 250, 85);
  myDrawLine(175, 155, 195, 170);
  myDrawLine(175, 155, 230, 70);
  myDrawLine(243, 58, 256, 68);
  myDrawLine(233.5, 72, 243, 58);
  myDrawLine(246, 82, 256, 68);

  myDrawLine(167.5, 174, 178, 158);
  myDrawLine(179, 185, 189, 169);
  myDrawLine(166, 175, 179, 185);


}


void RenderWidget::myDrawLine(float x1, float y1, float x2, float y2)
{
  QPainter painter(this);

  //    painter.setRenderHint(QPainter::Antialiasing, false);
  QColor color(0, 0, 0);
  painter.setPen(QPen(color, 3));

  float m = (y2 - y1) / (x2 - x1);
  //  SetPixel(x1, y1, color);   // first point
  painter.drawPoint(x1, y1);

  if (m < 1)
  {
    float y = y1;
    for (int i = x1 + 1; i < x2; ++i)
    {
      y = y + m;
      //      SetPixel(i, round(y), color);
      painter.drawPoint(i, round(y));
    }
  }
  else     // i.e., m > 1
  {
    float mm = 1 / m;
    float x = x1;
    for (int i = y1 + 1; i < y2; ++i)
    {
      x = x + mm;
      //      SetPixel(round(x), i, color);
      painter.drawPoint(round(x), i);
    }
  }

  //  SetPixel(x2, y2, color);   // last point
  painter.drawPoint(x2, y2);
}
void RenderWidget::myDrawLineUsingBresenhamAlgorithm(float x1, float y1, float x2, float y2) {
	QPainter painter(this);
	QColor color(0, 0, 0);
	painter.setPen(QPen(color, 3));
	painter.drawPoint(x1, y1);
	float dx = x2 - x1, dy = y2 - y1;
	float tDx = 2 * dx, tDy = 2*dy;
	float y = y1;
	float p = tDy - dx;
	for (int x = x1+1; x <= x2; x++)
	{
		if (p<0) {
			painter.drawPoint(x, y);
			p += tDy;
		}
		else
		{
			y++;
			painter.drawPoint(x, y);
			p += tDy - tDx;
		}

	}
}
void RenderWidget::myDrawCircle(float xc, float yc, float t1, float t2, float r) {
	QPainter painter(this);
	QColor color(0, 0, 0);
	painter.setPen(QPen(color,3));
	
	float theta = t1, dTheta = 1 / r;
	float x, y;
	while (theta<t2)
	{
		x = xc + (r * cos(theta * 3.14 / 180));
		y = yc + (r * sin(theta * 3.14 / 180));
		painter.drawPoint(x, y);
		theta += dTheta;
	}
	

}

