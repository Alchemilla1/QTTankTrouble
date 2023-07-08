#pragma once
#include "Object.h"
#include "config.h"
#include <string>
#include <Qpixmap.h>
#include <qvector.h>
#include <qmediaplayer.h>
#include <QAudioOutput>
#include <cmath>
#include "Bullet.h"
#include "CreateWall.h"
#include "ToolBox.h"
using namespace std;

class Bullet;
class ToolBox;
class Mine;
class Tank :public Object {
public:
	int bullet_count;
	int tank_color;
	int state;
	int ai_rotate, ai_move, ai_fire;
	int target_x, target_y;
	QMediaPlayer* vfire;
	QMediaPlayer* vmgun;
	// 0_������1_���ף�2_���ӣ�3_����ǹ
	//���ף�10~13����λ��ʾ�Ѿ����õĵ�����
	//���ӣ�20��������˵����
	//����ǹ��30~39����λ��ʾ�Ѿ�������ӵ���
	Tank(string _name, int _x, int _y, int _seta, int color);
	Modify collision(Modify _modify, Object* target);
	void explode() override;
	void forward() override;
	void backward() override;
	void fire();
	void fire_mine();
	void fire_shotgun();
	void fire_machine_gun();
	void clock_rotate();
	void anticlock_rotate();
	void AI();
	void Random();
	int Rand();
	bool pd_move(int dx,int dy,int dseta);
	
	virtual ~Tank();


	static Tank* A;
	static Tank* B;
	static int rand_a, rand_b, rand_c, rand_d;
	int _xb, _yb;
};
extern bool visited[Horizon_Block_Number][Vertical_Block_Number];//̹���Ƿ��ߵ��ø��ӡ�
void get_block(int& X, int& Y, int x, int y);

