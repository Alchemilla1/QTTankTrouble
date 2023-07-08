#include"ToolBox.h"



ToolBox::ToolBox(string _name, int _x, int _y, int _seta) :Object(_name, _x, _y, _seta) {
	QVector<QPoint> point = { QPoint(-ToolBox_Length / 2,-ToolBox_Length / 2),QPoint(ToolBox_Length / 2,-ToolBox_Length / 2),
		QPoint(ToolBox_Length / 2,ToolBox_Length / 2),QPoint(-ToolBox_Length / 2,ToolBox_Length / 2) };
	polygon = QPolygon(point);
	id = rand() % Tool_Count;
	x = _x; y = _y; seta = 0;
	picture.load(des[id]);
	object.push_back(this);
}

Modify ToolBox::collision(Modify _modify, Object* target) {
	if (!if_crash(target))return _modify;
	return _modify;
}

void ToolBox::explode() {
	alive = false;
}

ToolBox::~ToolBox() {}

void generate(int& toolCounter, int& num) {
	toolCounter++;
	if (toolCounter == 250 && num <= 6)
	{
		toolCounter = 0;
		Object* tmp = new ToolBox(
			"ToolBox",
			rand() % Horizon_Block_Number * Wall_Length,
			rand() % Vertical_Block_Number * Wall_Length + Wall_Length / 2,
			0);
		num++;
	}
}