#include "MicroscopeDrawer.h"

MicroscopeDrawer::MicroscopeDrawer(QPainter* p) {
	this->painter = p;
	this->inst_PPUPainter = new PPUPainter(p);
}

void MicroscopeDrawer::draw() {
	drawArm();
	drawBase();
	drawHead();
	drawTable();
}

void MicroscopeDrawer::drawTable() {
	inst_PPUPainter->drawLineBresenham(100, 230, 205, 230);
	inst_PPUPainter->drawLineBresenham(100, 243, 205, 243);
	inst_PPUPainter->drawLineBresenham(100, 230, 100, 243);
	inst_PPUPainter->drawLineBresenham(205, 230, 205, 243);
}

void MicroscopeDrawer::drawArm() {
	inst_PPUPainter->drawArcPolar(200, 200, -60, 120, 50);
	inst_PPUPainter->drawArcPolar(200, 200, -60, 59, 70);
	inst_PPUPainter->drawArcPolar(200, 200, 121, 142, 70);
	inst_PPUPainter->drawCirclePolar(215, 139, 15);
	inst_PPUPainter->drawCirclePolar(215, 139, 20);
}

void MicroscopeDrawer::drawBase() {
	inst_PPUPainter->drawLineBresenham(100, 300, 132, 300);
	inst_PPUPainter->drawLineBresenham(100, 300, 100, 320);
	inst_PPUPainter->drawLineBresenham(100, 320, 300, 320);
	inst_PPUPainter->drawArcPolar(200, 320, -180, 0, 70);
	inst_PPUPainter->drawLineBresenham(300, 300, 300, 320);
	inst_PPUPainter->drawCirclePolar(200, 280, 18);
	inst_PPUPainter->drawLineBresenham(268, 300, 300, 300);
}

void MicroscopeDrawer::drawHead() {
	inst_PPUPainter->drawLineBresenham(195, 170, 205, 155);
	inst_PPUPainter->drawLineBresenham(225, 121, 250, 85);
	inst_PPUPainter->drawLineBresenham(230, 70, 250, 85);
	inst_PPUPainter->drawLineBresenham(175, 155, 195, 170);
	inst_PPUPainter->drawLineBresenham(175, 155, 230, 70);
	inst_PPUPainter->drawLineBresenham(243, 58, 256, 68);
	inst_PPUPainter->drawLineBresenham(233.5, 72, 243, 58);
	inst_PPUPainter->drawLineBresenham(246, 82, 256, 68);
	inst_PPUPainter->drawLineBresenham(167.5, 174, 178, 158);
	inst_PPUPainter->drawLineBresenham(179, 185, 189, 169);
	inst_PPUPainter->drawLineBresenham(166, 175, 179, 185);
}