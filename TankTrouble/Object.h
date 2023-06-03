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
	int seta;//�������ת�ĽǶ�
	int x, y;//�������Ͻǵ�����
	string name;//ָ�������������
	bool alive;//��Ʒ�Ƿ񻹴��ڣ�ÿ֡��β��ɨ
	QPixmap picture;
	QPolygon polygon;

	Object();
	Object(string name,int _x=0,int _y=0,int _seta=0);
	QPolygon Transform();
	bool if_crash(Object* target);
	virtual Modify collision(Modify _modify,Object* target)=0;//��̬���Բ�ͬ��ϵ���ײ������ͬ��Ӧ
	virtual void explode();
	virtual void forward();
	virtual void backward();
	double deg_to_rad(int x);
	int Manhattan(Object* target);
	virtual ~Object();
};


