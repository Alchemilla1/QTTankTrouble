#pragma once

class Object;
struct Modify {
	int x, y;
	int seta;
	int state;
	bool if_modify_seta;
	bool if_explode;
	bool if_move;
	int if_modify_state;//记录tank捡到道具后做何种变化
	Modify();
};