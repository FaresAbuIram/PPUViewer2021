#include <QPainter>
#include <math.h>

class PPUPainter {
	
public:
	PPUPainter(QPainter* p);
	void drawCircleBresenham(float xc, float yc, float r);

private: 
	QPainter* painter;
	void drowAllSimilarPoints(float x, float y, float xc, float yc);
};