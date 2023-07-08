#include"Tank.h"
#include<qdebug.h>
Tank* Tank::A = nullptr;
Tank* Tank::B = nullptr;
int Tank::rand_a = 1;
int Tank::rand_b = 3;
int Tank::rand_c = 5;
int Tank::rand_d = 97;
bool visited[Horizon_Block_Number][Vertical_Block_Number];
Tank::Tank(string _name, int _x, int _y, int _seta, int color) :Object(_name, _x, _y, _seta), tank_color(color) {
	QVector<QPoint> points = { QPoint(-Tank_Length / 2,-Tank_Width / 2),QPoint(Tank_Length / 2,-Tank_Width / 2),
		QPoint(Tank_Length / 2,Tank_Width / 2),QPoint(-Tank_Length / 2,Tank_Width / 2) };
	polygon = QPolygon(points);
	if (color == 0)
		picture.load(":/TankTrouble/res/blueTank.png");
	else if (color == 1)
		picture.load(":/TankTrouble/res/redTank.png");
	Object::object.push_back(this);
	bullet_count = 0;
	state = 0;
	ai_move = ai_rotate = ai_fire = 0;
	target_x = target_y = 0;
	_xb = _yb = -1;
	vfire = new QMediaPlayer;
	vmgun = new QMediaPlayer;
	vfire->setSource(QUrl::fromLocalFile("res\\split.mp3"));
	vmgun->setSource(QUrl::fromLocalFile("res\\mgun.mp3"));
	QAudioOutput* audioOutput1 = new QAudioOutput;
	audioOutput1->setVolume(50);
	QAudioOutput* audioOutput2 = new QAudioOutput;
	audioOutput2->setVolume(50);
	vfire->setAudioOutput(audioOutput1);
	vmgun->setAudioOutput(audioOutput2);
}
Modify Tank::collision(Modify _modify, Object* target) {
	if (!if_crash(target))return _modify;
	if (target->name == "Wall") {
		_modify.if_move = false;
		_modify.if_modify_seta = false;
	}
	if (target->name == "ToolBox") {
		//modify_state(target); 
		_modify.state = (((ToolBox*)target)->id + 1) * 10;
		_modify.if_modify_state = true;
		target->explode();
	}
	if (target->name == "Mine") {
		if (dynamic_cast<Bullet*>(target)->lifeTime < FPS * 3)return _modify;
		this->explode();
		target->explode();
	}
	return _modify;
}
void Tank::explode() {
	//tank±¬Õ¨ÌØÐ§
	alive = false;
}


void Tank::forward() {
	if (this == nullptr)
		return;
	int dx = x + round(cos(deg_to_rad(seta)) * (double)Tank_Speed);
	int dy = y + round(sin(deg_to_rad(seta)) * (double)Tank_Speed);
	Modify _modify;
	_modify.x = dx - x; _modify.y = dy - y; _modify.if_move = true;
	x = dx; y = dy;
	for (int i = 0; i < object.size(); ++i) {
		_modify = collision(_modify, object[i]);
	}
	if (_modify.if_explode)explode();
	else {
		if (_modify.if_modify_state)state = _modify.state;
		if (!_modify.if_move) {
			x -= _modify.x; y -= _modify.y;
		}
	}
}

void Tank::backward() {
	if (this == nullptr)
		return;
	int dx = x - round(cos(deg_to_rad(seta)) * (double)Tank_Speed);
	int dy = y - round(sin(deg_to_rad(seta)) * (double)Tank_Speed);
	Modify _modify;
	_modify.x = dx - x; _modify.y = dy - y; _modify.if_move = true;
	x = dx; y = dy;
	for (int i = 0; i < object.size(); ++i) {
		_modify = collision(_modify, object[i]);
	}
	if (_modify.if_explode)explode();
	else {
		if (_modify.if_modify_state)state = _modify.state;
		if (!_modify.if_move) {
			x -= _modify.x; y -= _modify.y;
		}
	}
}
void Tank::fire() {



	if (state == 0) {

		if (bullet_count > 5)
			return;

		vfire->stop();
		vfire->setPosition(0);
		vfire->play();
		int dx = x + cos(deg_to_rad(seta)) * (Tank_Length - Bullet_D) / 2;
		int dy = y + sin(deg_to_rad(seta)) * (Tank_Width - Bullet_D) / 2;
		Object* nBullet = new Bullet("Bullet", dx, dy, seta, this, 0);
		++bullet_count;
	}
	else if (state / 10 == 1) {
		fire_mine();
	}
	else if (state / 10 == 2) {

		vfire->setPosition(0);
		vfire->play();
		fire_shotgun();
	}
	else if (state / 10 >= 3) {
		vmgun->setPosition(0);
		vmgun->play();
		fire_machine_gun();
	}

}
void Tank::fire_mine() {
	int dx = x, dy = y;
	Object* nMine = new Bullet("Mine", dx, dy, 0, this, 1);
	++state;
	if (state == 13) {
		state = 0;
	}
}
void Tank::fire_shotgun() {
	int dx = x, dy = y;
	int dseta = -19;
	for (int i = 1; i <= 10; i++) {
		Object* nBullet = new Bullet("Bullet", dx, dy, seta + dseta, this, 2);
		dseta += 4;
	}
	state = 0;
}
void Tank::fire_machine_gun() {
	int dx = x + cos(deg_to_rad(seta)) * (Tank_Length - Bullet_D) / 2;
	int dy = y + sin(deg_to_rad(seta)) * (Tank_Width - Bullet_D) / 2;
	Object* nBullet = new Bullet("Bullet", dx, dy, seta + (rand() % 7), this, 3);
	++state;
	if (state == 49) {
		state = 0;
	}

}

void Tank::clock_rotate() {
	if (this == nullptr)
		return;
	int dseta = (seta + Rotate_Speed) % 360;
	Modify _modify;
	_modify.seta = dseta - seta; _modify.if_modify_seta = true;
	seta = dseta;
	for (int i = 0; i < object.size(); ++i) {
		_modify = collision(_modify, object[i]);
	}
	if (_modify.if_explode)explode();
	else {
		if (_modify.if_modify_state)state = _modify.state;
		if (!_modify.if_modify_seta)seta -= _modify.seta;
	}
}

void Tank::anticlock_rotate() {
	if (alive == 0)
		return;
	int dseta = (seta - Rotate_Speed+360) % 360;
	Modify _modify;
	_modify.seta = dseta - seta; _modify.if_modify_seta = true;
	seta = dseta;
	for (int i = 0; i < object.size(); ++i) {
		_modify = collision(_modify, object[i]);
	}
	if (_modify.if_explode)explode();
	else {
		if (_modify.if_modify_state)state = _modify.state;
		if (!_modify.if_modify_seta)seta -= _modify.seta;
	}
}

bool Tank::pd_move(int dx, int dy, int dseta) {
	return dx == x && dy == y && dseta == seta;
}
void Tank::Random() {
	int dx = x, dy = y, dseta = seta;
	if (ai_move&&!ai_rotate) {
		if (ai_move > 0) {
			forward(); ai_move--;
			if (pd_move(dx,dy,dseta))ai_move = 0;
		}
		else {
			backward(); ai_move++;
			if (pd_move(dx,dy,dseta))ai_move = 0;
		}
	}
	else if(!ai_rotate) {
		int op = rand() % 2;
		if (op == 0) ai_move=rand()%10+10;
		else if (op == 1) ai_move=-rand()%10-10;
	}
	
	if (ai_rotate&&!ai_move) {
		if (ai_rotate > 0) {
			clock_rotate();
			if (abs(seta - ai_rotate) <= Rotate_Speed )ai_rotate = 0;
			if (pd_move(dx, dy, dseta))ai_rotate = 0;
		}
		else {
			anticlock_rotate();
			if (abs(seta + ai_rotate) <= Rotate_Speed )ai_rotate = 0;
			if (pd_move(dx,dy,dseta))ai_rotate = 0;
		}
	}
	else if(!ai_move) {
		int op = rand() % 2;
		if (op == 0) {
			int _seta = seta + 90; _seta %= 360;
			if (_seta <= 90)ai_rotate = 90;
			else if (_seta <= 180)ai_rotate = 180;
			else if (_seta <= 270)ai_rotate = 270;
			else if (_seta <= 360)ai_rotate = 1;
		}
		else if (op == 1) {
			int _seta = seta - 90 + 360; _seta %= 360;
			if (_seta <= 90)ai_rotate = -1;
			else if (_seta <= 180)ai_rotate = -90;
			else if (_seta <= 270)ai_rotate = -180;
			else if (_seta <= 360)ai_rotate = -270;
		}
	}
}

Tank::~Tank() {}
void get_block(int& X, int& Y, int x, int y) {
	X = (x+Wall_Length/2) / Wall_Length;
	Y = (y) / Wall_Length;
}
int Tank::Rand() {
	return rand_a=(rand_a * rand_b + rand_c) % rand_d;
}
void Tank::AI() {
	int xa, ya, xb, yb;
	get_block(xa, ya, Tank::A->x, Tank::A->y);
	get_block(xb, yb, Tank::B->x, Tank::B->y);
	visited[xb][yb] = true;
	if (xa == xb && ya == yb) {
		
		target_x = target_y = 0;
		int dx = Tank::A->x - x;
		int dy = Tank::A->y - y;
		double _tan = atan2(dy, dx);
		int _seta = rad_to_deg(_tan);
		_seta = (_seta + 360) % 360;
		if (abs(seta - _seta) % 360 > Rotate_Speed / 2 && abs(seta + 360 - _seta) % 360 > Rotate_Speed) {
			int seta1 = seta, seta2 = (seta + 180) % 360;
			if (seta1 <= seta2) {
				if (seta1 <= _seta && _seta <= seta2)clock_rotate();
				else anticlock_rotate();
			}
			else {
				if (_seta > seta1 || _seta < seta2)clock_rotate();
				else anticlock_rotate();
			}
		}
		else {
			fire();
		}
	}
	else if (target_x || target_y) {
		int dx = target_x - x;
		int dy = target_y - y;
		qDebug() << x << " " << y << " " << target_x << " " << target_y;
		double _tan = atan2(dy, dx);
		int _seta = rad_to_deg(_tan);
		_seta = (_seta + 360) % 360;
		qDebug() << " " << _seta << '\n';
		if (abs(seta - _seta) % 360 > Rotate_Speed / 2 && abs(seta + 360 - _seta) % 360 > Rotate_Speed) {
			int seta1 = seta, seta2 = (seta + 180) % 360;
			if (seta1 <= seta2) {
				if (seta1 <= _seta && _seta <= seta2)clock_rotate();
				else anticlock_rotate();
			}
			else {
				if (_seta > seta1 || _seta < seta2)clock_rotate();
				else anticlock_rotate();
			}
		}
		else {
			int nx, ny;
			nx = x; ny = y;
			forward();
			if (nx == x && ny == y) {
				Random();
				target_x = target_y = 0;
			}
		}
		if (abs(x - target_x) < 5 && abs(y - target_y) < 5) {
			get_block(_xb, _yb, x, y);
			target_x = target_y = 0;
		}
	}
	else if(!target_x&&!target_y) {
		vector<pair<int, int> > next_block;
		//qDebug() << next_block.size() << '\n';
		if (yb > 0) {
			if (dead_wall[Block(xb, yb).id()][Block(xb, yb - 1).id()])
				next_block.push_back(make_pair(xb, yb - 1));
		}
		if (yb < Vertical_Block_Number - 1) {
			if (dead_wall[Block(xb, yb).id()][Block(xb, yb + 1).id()])
				next_block.push_back(make_pair(xb, yb + 1));
		}
		if (xb > 0) {
			if (dead_wall[Block(xb, yb).id()][Block(xb - 1, yb).id()])
				next_block.push_back(make_pair(xb - 1, yb));
		}
		if (xb < Horizon_Block_Number - 1) {
			if (dead_wall[Block(xb, yb).id()][Block(xb+1, yb).id()])
				next_block.push_back(make_pair(xb+1, yb));
		}
		qDebug() << xb<<" "<<yb<<" "<<next_block.size() << " size" << '\n';
		if (next_block.size() == 1 && visited[next_block[0].first][next_block[0].second]) {
			qDebug() << "###################" << '\n';
			memset(visited, 0, sizeof(visited));
		}
		int op = Rand() % next_block.size();
		while (visited[next_block[op].first][next_block[op].second]) {
			op = (op + 1) % next_block.size();
		}
		target_x = next_block[op].first * Wall_Length;
		target_y = next_block[op].second * Wall_Length + Wall_Length/2;
	}
}