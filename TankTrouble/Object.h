#pragma once
#include"config.h"
#include<string>
#include<Qpixmap.h>
#include<qvector.h>
#include<qpolygon.h>
#include<qtransform.h>
#include<cmath>
#include"Modify.h"
using namespace std;
class Object {
public:
	static vector<Object*> object;
	int seta;//多边形旋转的角度
	int x, y;//矩形左上角的坐标
	string name;//指向的派生类名称
	bool alive;//物品是否还存在，每帧结尾清扫
	QPixmap picture;
	QPolygon polygon;

	Object();
	Object(string name,int _x=0,int _y=0,int _seta=0);
	QPolygon Transform();
	bool if_crash(Object* target);
	virtual Modify collision(Modify _modify,Object* target)=0;//多态，对不同组合的碰撞做出不同反应
	virtual void explode();
	virtual void forward();
	virtual void backward();
	double deg_to_rad(int x);
	int Manhattan(Object* target);
	virtual ~Object();
};


