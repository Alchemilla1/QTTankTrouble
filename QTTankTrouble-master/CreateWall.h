#pragma once
#include"config.h"
#include"Wall.h"
#include<qvector.h>
#include<qpolygon.h>
using namespace std;
struct Block {
	int x, y;
	Block(int _x,int _y):x(_x),y(_y){}
	int id() {
		return y * Horizon_Block_Number + x;
	}
};
struct Build_Wall {
	struct node {
		int x, y, seta;
	};
	QVector<node> horizon_wall, vertical_wall;
	Build_Wall(){}
};
//wall�ı�ʾ������pair<block,block>

Build_Wall::node get_node(pair<int, int> middle, int x_length, int y_length,int seta);
pair<int, int> Coor_Block(int i, int j);
void test_wall();//
void Create_Wall();
extern bool vis[Horizon_Block_Number][Vertical_Block_Number];//�����Ƿ����������
extern bool dead_wall[Max_Block_Number][Max_Block_Number];//ǽ�Ƿ񱻲����
extern vector<pair<Block, Block> >wall_que;//��ǰ������չ�ı�
extern int wall_x[4];
extern int wall_y[4];
