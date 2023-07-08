#include"Wall.h"

int Wall::wallcount = 0;

Wall::Wall(string _name, int _x, int _y, int _seta) :Object(_name, _x, _y, _seta) {
	++wallcount;
	QVector<QPoint> point = { QPoint(-Wall_Length / 2,-Wall_Width / 2),QPoint(Wall_Length / 2,-Wall_Width / 2),
		QPoint(Wall_Length / 2,Wall_Width / 2),QPoint(-Wall_Length / 2,Wall_Width / 2) };
	polygon = QPolygon(point);
	object.push_back(this);
}
Modify Wall::collision(Modify _modify, Object* target) {
	if (!if_crash(target))return _modify;
	if (target->name == "Tank") {

	}
	if (target->name == "Wall") {

	}
	if (target->name == "Bullet") {

	}
	if (target->name == "ToolBox") {

	}
	return _modify;
}

void Wall::explode() {
	alive = false;
}

Wall::~Wall() {}