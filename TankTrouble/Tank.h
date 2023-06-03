#pragma once
#include"Object.h"
#include"config.h"
#include<string>
#include<Qpixmap.h>
#include<qvector.h>
#include<cmath>
#include"Bullet.h"
using namespace std;

class Bullet;
class Tank :public Object {
public:
	int bullet_count;
	int tank_color;


	Tank(string _name, int _x, int _y, int _seta, int color);
	Modify collision(Modify _modify, Object* target);
	void explode() override;
	void modify_state(Object* target);
	void forward() override;
	void backward() override;
	void fire();
	void clock_rotate();
	void anticlock_rotate(); 
	virtual ~Tank();

	static Tank* A;
	static Tank* B;
};