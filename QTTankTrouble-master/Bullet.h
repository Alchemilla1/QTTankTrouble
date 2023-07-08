#pragma once
#include"Object.h"
#include"config.h"
#include<string>
#include<Qpixmap.h>
#include<qvector.h>
#include"Tank.h"
#include<qstring.h>

using namespace std;

class Tank;

class Bullet :public Object {
public:
	int lifeTime;
	Tank* p;
	int kind;
	const QString des[3] = { ":/TankTrouble/res/bulletbig.png" ,":/TankTrouble/res/bullet.png",":/TankTrouble/res/mineBomb.png" };
	Bullet(string _name, int _x, int _y, int _seta, Tank* pTank, int _kind);
	Modify collision(Modify _modify, Object* target) override;
	void explode() override;
	void modify_seta(Object* target);
	void forward() override;
	virtual ~Bullet();
};