#pragma once
#include"Object.h"
#include"config.h"
#include<qstring.h>
#include<Qpixmap.h>
#include<qvector.h>
using namespace std;

class ToolBox :public Object {
private:

public:
	int id;
	const QString des[3]{ ":/TankTrouble/res/bomb.png",":/TankTrouble/res/shotgun.png",":/TankTrouble/res/machine_gun.png" };


	ToolBox(string _name, int _x, int _y, int _seta);
	Modify collision(Modify _modify, Object* target) override;
	void explode() override;
	virtual ~ToolBox();

};

void generate(int& toolCounter, int& num);
