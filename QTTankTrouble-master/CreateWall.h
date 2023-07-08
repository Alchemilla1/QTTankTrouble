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
//wall的表示方法：pair<block,block>

Build_Wall::node get_node(pair<int, int> middle, int x_length, int y_length,int seta);
pair<int, int> Coor_Block(int i, int j);
void test_wall();//
void Create_Wall();
extern bool vis[Horizon_Block_Number][Vertical_Block_Number];//格子是否加入生成树
extern bool dead_wall[Max_Block_Number][Max_Block_Number];//墙是否被拆除？
extern vector<pair<Block, Block> >wall_que;//当前可以拓展的边
extern int wall_x[4];
extern int wall_y[4];
