#pragma once
#include"Object.h"
#include"config.h"
#include<string>
#include<Qpixmap.h>
#include<qvector.h>
using namespace std;

class Wall :public Object {
	//�������horizonǽ��ת��Ϊ0������Ϊ90��
private:

public:
	static int wallcount;
	Wall(string _name,int _x,int _y,int _seta);
	Modify collision(Modify _modify,Object* target) override;
	void explode() override;
	virtual ~Wall();
};