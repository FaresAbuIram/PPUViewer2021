#include "PPUPainter.h"

#define PI 3.14159265

PPUPainter::PPUPainter(QPainter* p) {
	this->painter = p;
}

void PPUPainter::drawCircleBresenham(float xc, float yc, float r) {

    float x = 0;
    float end_x = cos(PI / 4) * r;
    float y = r;
    float d = 3 - 2 * r;

    painter->drawPoint(x, y);
    while (x <= end_x) {
        if (d <= 0) {
            drowAllSimilarPoints(x, y, xc, yc);
            d += (4 * x) + 6;
        }
        else {
            drowAllSimilarPoints(x, y, xc, yc);
            y--;
            d += (4 * (x - y)) + 10;
        }
        x++;
    }
}

void PPUPainter::drowAllSimilarPoints(float x, float y, float xc, float yc) {

    this->painter->drawPoint(x + xc, yc + y);
    this->painter->drawPoint(-x + xc, yc + y);
    this->painter->drawPoint(x + xc, yc + -y);
    this->painter->drawPoint(-x + xc, yc + -y);
    
    this->painter->drawPoint(xc + -y, -x + yc);
    this->painter->drawPoint(xc + y, x + yc);
    this->painter->drawPoint(xc + -y, x + yc);
    this->painter->drawPoint(xc + y, -x + yc);
}