#include "Object.h"
#include<qtransform.h>

std::vector<Object*> Object::object;

Object::Object(string _name, int _x, int _y, int _seta) :name(_name), x(_x), y(_y), seta(_seta), alive(true) {
	if (name == "Wall")
		picture.load(":/TankTrouble/res/hWall2.png");

}
double Object::deg_to_rad(int x) {
	return (double)(x)*M_PI / 180.0;
}
int Object::rad_to_deg(double x) {
	return (int)((x) * 180.0 / M_PI);
}
int Object::Manhattan(Object* target) {
	return abs(x - target->x) + abs(y - target->y);
}
QPolygon Object::Transform() {
	QTransform transform;
	QPolygon _polygon = polygon;
	transform.translate(this->x + Horizon_Bias,
		this->y + Vertical_Bias);
	transform.rotate(seta);

	_polygon = transform.map(polygon);
	transform.reset();
	return _polygon;
}
bool Object::if_crash(Object* target) {
	QPolygon transformedPolygon = Transform();
	QPolygon intersection = transformedPolygon.intersected(target->Transform());
	if (intersection.isEmpty())return false;
	return true;
}



void Object::forward() {}
void Object::backward() {}
void Object::explode() {}
Object::~Object() {}


