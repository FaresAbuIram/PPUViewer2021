#include <QPainter>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

class PPUPainter {

public:
	PPUPainter(QPainter* p);
	void drawCircleBresenham(int xc, int yc, int r);
	void drawLineBresenham(int x1, int y1, int x2, int y2);
	void drawSimpleLine(int x1, int y1, int x2, int y2);

private:
	QPainter* painter;
	void drowAllSimilarPoints(int x, int y, int xc, int yc);
	bool isSimpleLine(int x1, int y1, int x2, int y2);

};