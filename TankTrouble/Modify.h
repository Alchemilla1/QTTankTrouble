#pragma once

class Object;
struct Modify {
	int x, y;
	int seta;
	Object* target;
	bool if_modify_seta;
	bool if_explode;
	bool if_move;
	int if_modify_state;//��¼tank�񵽵��ߺ������ֱ仯
	Modify();
};