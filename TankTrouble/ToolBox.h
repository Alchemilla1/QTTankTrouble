#pragma once
#include"Object.h"
#include"config.h"
#include<string>
#include<Qpixmap.h>
#include<qvector.h>
using namespace std;

class ToolBox :public Object {
private:

public:
	static string tool[Tool_Count];
	int id;

	ToolBox(string _name,int _x,int _y,int _seta);
	Modify collision(Modify _modify,Object* target) override;
	void explode() override; 
	virtual ~ToolBox();
};
