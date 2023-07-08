//#include"Mine.h"
//
//Mine::Mine(string _name, int _x, int _y, int _seta, Tank* pTank)
//	:Object(_name, _x, _y, _seta) {
//	QVector<QPoint> point = { QPoint(-Mine_D / 2,-Mine_D / 2),QPoint(Mine_D / 2,-Mine_D / 2),
//		QPoint(Mine_D / 2,Mine_D / 2),QPoint(-Mine_D / 2,Mine_D / 2) };
//	polygon = QPolygon(point);
//	object.push_back(this);
//	p = pTank;
//	lifeTime = 0;
//}
//Modify Mine::collision(Modify _modify, Object* target) {
//	//Modify _modify;
//	if (!if_crash(target))return _modify;
//	if (target->name == "Tank") {
//		//explode(); 
//		if (target == (Object*)p) {
//			if (lifeTime < FPS * 2)
//				return _modify;
//		}
//		target->explode();
//		_modify.if_explode = true;
//	}
//
//	return _modify;
//}
//void Mine::explode() {
//	alive = false;
//}
//
//
//Mine::~Mine() {}