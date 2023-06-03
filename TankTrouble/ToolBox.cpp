#include"ToolBox.h"

string ToolBox::tool[Tool_Count] = { "MachineGun" };


ToolBox::ToolBox(string _name, int _x, int _y, int _seta) :Object(_name, _x, _y, _seta) {
	id = rand() % Tool_Count;
	name = _name + "_" + tool[id];
	x = _x; y = _y; seta = 0;
	object.push_back(this);
}
Modify ToolBox::collision(Modify _modify, Object* target) {
	if (!if_crash(target))return _modify;
	if (target->name == "Tank") {
		//explode();
		_modify.if_explode = true;
	}
	if (target->name == "Wall") {

	}
	if (target->name == "Bullet") {

	}
	if (target->name == "ToolBox") {

	}
	return _modify;
}
void ToolBox::explode() {
	alive = false;
}
ToolBox::~ToolBox() {}