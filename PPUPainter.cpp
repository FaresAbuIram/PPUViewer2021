#include "PPUPainter.h"

#define PI 3.14159265

PPUPainter::PPUPainter(QPainter* p) {
	this->painter = p;
}

void PPUPainter::drawCircleBresenham(int xc, int yc, int r) {

	int x = 0;
	int end_x = cos(PI / 4) * r;
	int y = r;
	int d = 3 - 2 * r;

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

void PPUPainter::drowAllSimilarPoints(int x, int y, int xc, int yc) {

	this->painter->drawPoint(x + xc, yc + y);
	this->painter->drawPoint(-x + xc, yc + y);
	this->painter->drawPoint(x + xc, yc + -y);
	this->painter->drawPoint(-x + xc, yc + -y);

	this->painter->drawPoint(xc + -y, -x + yc);
	this->painter->drawPoint(xc + y, x + yc);
	this->painter->drawPoint(xc + -y, x + yc);
	this->painter->drawPoint(xc + y, -x + yc);
}

void PPUPainter::drawLineBresenham(int x1, int y1, int x2, int y2) {

	if (x1 > x2) {
		swap(x1, x2);
		swap(y1, y2);
	}

	int dx = x2 - x1;
	int dy = y2 - y1;
	int _2dy = 2 * dy;
	int _2dx = 2 * dx;
	int y = y1;
	int x = x1;
	int incP = _2dy - (2 * dx);
	int p = _2dy - dx;
	float m = dy * 1.0 / dx;

	this->painter->drawPoint(x1, y1);

	if (isSimpleLine(x1, y1, x2, y2)) {
		drawSimpleLine(x1, y1, x2, y2);
		return;
	}

	if (m > 0) {
		if (m < 1) {
			incP = _2dy - _2dx;
			p = _2dy + dx;
			for (int x = x1 + 1; x <= x2; x++) {

				if (p < 0) {
					this->painter->drawPoint(x, y);
					p += _2dy;
				}
				else {
					y++;
					this->painter->drawPoint(x, y);
					p += incP;
				}
			}
		}
		else {
			incP = _2dx - _2dy;
			p = _2dx - dy;
			if (y1 > y2) {
				swap(x1, x2);
				swap(y1, y2);
			}
			for (int y = y1 + 1; y <= y2; y++) {

				if (p < 0) {
					this->painter->drawPoint(x, y);
					p += _2dx;
				}
				else {
					x++;
					this->painter->drawPoint(x, y);
					p += incP;
				}
			}

		}
	}
	else {
		if (m > -1) {

			this->painter->setPen(QColor(200, 0, 200));
			incP = _2dy + _2dx;
			p = _2dy + dx; cout << "$";

			for (int x = x1 + 1; x <= x2; x++) {

				if (p >= 0) {
					this->painter->drawPoint(x, y);
					p += _2dy;
				}
				else {
					y--;
					this->painter->drawPoint(x, y);
					p += incP;
				}
			}
			this->painter->setPen(QColor(0, 0, 0));

		}
		else {
			incP = _2dy + _2dx;
			p = _2dy - dx;

			if (y1 > y2) {
				swap(x1, x2);
				swap(y1, y2);
			}

			x = x1;
			for (int y = y1 + 1; y <= y2; y++) {
				if (p < 0) {
					this->painter->drawPoint(x, y);
					p += _2dx;
				}
				else {

					x--;
					this->painter->drawPoint(x, y);
					p += incP;
				}
			}
		}
	}

}

bool PPUPainter::isSimpleLine(int x1, int y1, int x2, int y2) {
	return x1 == x2 || y1 == y2 || (y2 - y1) == (x2 - x1);
}

void PPUPainter::drawSimpleLine(int x1, int y1, int x2, int y2) {


	int inc_x = 0;
	int inc_y = 0;

	if (x1 > x2) {
		inc_x = -1;
	}
	else if (x1 < x2) {
		inc_x = 1;
	}

	if (y1 > y2) {
		inc_y = -1;
	}
	else if (y1 < y2) {
		inc_y = 1;
	}


	while (x1 != x2 || y1 != y2) {
		this->painter->drawPoint(x1, y1);
		x1 += inc_x;
		y1 += inc_y;
	}
}
