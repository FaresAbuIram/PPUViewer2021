#include "PPUPainter.h"
#include <QPainter>

class MicroscopeDrawer {

public:
	MicroscopeDrawer(QPainter* p);
	void draw();

private:
	void drawArm();
	void drawBase();
	void drawHead();
	void drawTable();
	QPainter* painter;
	PPUPainter* inst_PPUPainter;
};