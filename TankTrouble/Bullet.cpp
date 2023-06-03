#include"Bullet.h"



Bullet::Bullet(string _name, int _x, int _y, int _seta, Tank* pTank)
	:Object(_name, _x, _y, _seta) {
	QVector<QPoint> point = { QPoint(-Bullet_D / 2,-Bullet_D / 2),QPoint(Bullet_D / 2,-Bullet_D / 2),
		QPoint(Bullet_D / 2,Bullet_D / 2),QPoint(-Bullet_D / 2,Bullet_D / 2) };
	polygon = QPolygon(point);
	object.push_back(this);
	p = pTank;
	lifeTime = 0;
}
Modify Bullet::collision(Modify _modify, Object* target) {
	//Modify _modify;
	if (!if_crash(target))return _modify;
	if (target->name == "Tank") {
		//explode(); 
		if (target == (Object*)p) {
			if (lifeTime < FPS / 4 && abs(seta - target->seta) < 90)
				return _modify;
		}
		target->explode();
		_modify.if_explode = true;
	}
	if (target->name == "Wall") {
		//modify_seta(target);
		_modify.if_modify_seta = true; _modify.if_move = false;
		int delta_x = abs(x - target->x);
		int delta_y = abs(y - target->y);
		if (target->seta == 0) {
			if (delta_x < Wall_Length / 2)
				_modify.seta = 360 - seta;
			else
				_modify.seta = 180 - seta;
		}
		else {
			if (delta_y < Wall_Length / 2)
				_modify.seta = 180 - seta;
			else
				_modify.seta = 360 - seta;
		}

		//if (target->seta == 0)_modify.seta = 360 - seta;
		//说明：对于横向墙，子弹角度会从seta变为360-seta
		//if (target->seta == 90)_modify.seta = 180 -seta;
		//说明：对于纵向墙，子弹角度会从seta变为180-seta
	}
	if (target->name == "Bullet") {

	}
	if (target->name == "ToolBox") {

	}
	return _modify;
}
void Bullet::explode() {

	Object* _bullet = this;
	alive = false;
}
void Bullet::modify_seta(Object* target) {
}
void Bullet::forward() {
	lifeTime++;
	if (lifeTime == Bullet_Life)
		alive = 0;
	int dx = x + round(cos(deg_to_rad(seta)) * (double)Bullet_Speed);
	int dy = y + round(sin(deg_to_rad(seta)) * (double)Bullet_Speed);
	Modify _modify;
	_modify.x = dx - x; _modify.y = dy - y; _modify.if_move = true;
	int oseta = seta;
	x = dx; y = dy;
	for (auto& obj : Object::object) {
		if (obj != nullptr)
			_modify = collision(_modify, obj);
	}
	Object* nearest_wall;
	int min_dis = 0x3f3f3f3f;
	for (auto& obj : Object::object) {
		if (obj != nullptr && obj->name == "Wall") {
			if (Manhattan(obj) < min_dis) {
				min_dis = Manhattan(obj);
				nearest_wall = obj;
			}
		}
		else if (obj != nullptr) {
			_modify = collision(_modify, obj);
		}
	}
	_modify = collision(_modify, nearest_wall);
	if (_modify.if_explode) explode();
	else {
		if (!_modify.if_move) {
			x -= _modify.x; y -= _modify.y;
		}
		if (_modify.if_modify_seta) {
			//if (if_crash(nearest_wall))seta = rand() % 360;
			seta = _modify.seta;
			if (if_crash(nearest_wall))seta = (seta + 180) % 360;
			if (if_crash(nearest_wall))seta = (-oseta + 360) % 360;
			x += cos(deg_to_rad(seta));
			y += sin(deg_to_rad(seta));
		}
	}
}

Bullet::~Bullet() {}