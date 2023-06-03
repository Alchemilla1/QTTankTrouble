#pragma once
#include"Object.h"
#include"config.h"
#include<string>
#include<Qpixmap.h>
#include<qvector.h>
using namespace std;

class Wall :public Object {
	//定义横向horizon墙旋转角为0，纵向为90度
private:

public:
	static int wallcount;
	Wall(string _name,int _x,int _y,int _seta);
	Modify collision(Modify _modify,Object* target) override;
	void explode() override;
	virtual ~Wall();
};