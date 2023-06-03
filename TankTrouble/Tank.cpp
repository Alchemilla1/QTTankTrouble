#include"Tank.h"
#include<qdebug.h>
Tank* Tank::A = nullptr;
Tank* Tank::B = nullptr;


Tank::Tank(string _name, int _x, int _y, int _seta, int color) :Object(_name, _x, _y, _seta), tank_color(color) {
	QVector<QPoint> points = { QPoint(-Tank_Length / 2,-Tank_Width / 2),QPoint(Tank_Length / 2,-Tank_Width / 2),
		QPoint(Tank_Length / 2,Tank_Width / 2),QPoint(-Tank_Length / 2,Tank_Width / 2) };
	polygon = QPolygon(points);
	if (color == 0)
		picture.load(":/TankTrouble/res/blueTank.png");
	else if (color == 1)
		picture.load(":/TankTrouble/res/greenTank.png");
	Object::object.push_back(this);
	bullet_count = 0;
}
Modify Tank::collision(Modify _modify, Object* target) {
	if (!if_crash(target))return _modify;
	if (target->name == "Tank") {

	}
	if (target->name == "Wall") {
		_modify.if_move = false;
		_modify.if_modify_seta = false;
	}
	//if (target->name == "Bullet") {
	//	//explode();
	//	
	//	target->explode();
	//	_modify.if_explode = true;
	//}
	if (target->name == "ToolBox") {
		//modify_state(target); 
		_modify.target = target;
		_modify.if_modify_state = true;
	}
	return _modify;
}
void Tank::explode() {
	//tank±¬Õ¨ÌØÐ§
	alive = false;
}

void Tank::modify_state(Object* target) {}

void Tank::forward() {
	if (this == nullptr)
		return;
	int dx = x + round(cos(deg_to_rad(seta)) * (double)Tank_Speed);
	int dy = y + round(sin(deg_to_rad(seta)) * (double)Tank_Speed);
	Modify _modify;
	_modify.x = dx - x; _modify.y = dy - y; _modify.if_move = true;
	x = dx; y = dy;
	for (int i = 0; i < object.size(); ++i) {
		_modify = collision(_modify, object[i]);
	}
	if (_modify.if_explode)explode();
	else {
		if (_modify.if_modify_state)modify_state(_modify.target);
		if (!_modify.if_move) {
			x -= _modify.x; y -= _modify.y;
		}
	}
}

void Tank::backward() {
	if (this == nullptr)
		return;
	int dx = x - round(cos(deg_to_rad(seta)) * (double)Tank_Speed);
	int dy = y - round(sin(deg_to_rad(seta)) * (double)Tank_Speed);
	Modify _modify;
	_modify.x = dx - x; _modify.y = dy - y; _modify.if_move = true;
	x = dx; y = dy;
	for (int i = 0; i < object.size(); ++i) {
		_modify = collision(_modify, object[i]);
	}
	if (_modify.if_explode)explode();
	else {
		if (_modify.if_modify_state)modify_state(_modify.target);
		if (!_modify.if_move) {
			x -= _modify.x; y -= _modify.y;
		}
	}
}
void Tank::fire() {

	
	qDebug() << bullet_count;
	if (bullet_count > 5)
		return;
	int dx = x + cos(deg_to_rad(seta)) * (Tank_Length - Bullet_D) / 2;
	int dy = y + sin(deg_to_rad(seta)) * (Tank_Width - Bullet_D) / 2;
	Object* nBullet = new Bullet("Bullet", dx, dy, seta,this);
	++bullet_count;
	Modify _modify;
	/*for (int i = 0; i < object.size(); ++i) {
		_modify = nBullet->collision(_modify, object[i]);
	}
	if (_modify.if_explode) nBullet->explode();*/
}

void Tank::clock_rotate() {
	if (this == nullptr)
		return;
	int dseta = (seta + Rotate_Speed) % 360;
	Modify _modify;
	_modify.seta = dseta - seta; _modify.if_modify_seta = true;
	seta = dseta;
	for (int i = 0; i < object.size(); ++i) {
		_modify = collision(_modify, object[i]);
	}
	if (_modify.if_explode)explode();
	else {
		if (_modify.if_modify_state)modify_state(_modify.target);
		if (!_modify.if_modify_seta)seta -= _modify.seta;
	}
}

void Tank::anticlock_rotate() {
	if (alive == 0)
		return;
	int dseta = (seta - Rotate_Speed) % 360;
	Modify _modify;
	_modify.seta = dseta - seta; _modify.if_modify_seta = true;
	seta = dseta;
	for (int i = 0; i < object.size(); ++i) {
		_modify = collision(_modify, object[i]);
	}
	if (_modify.if_explode)explode();
	else {
		if (_modify.if_modify_state)modify_state(_modify.target);
		if (!_modify.if_modify_seta)seta -= _modify.seta;
	}
}

Tank::~Tank() {}
