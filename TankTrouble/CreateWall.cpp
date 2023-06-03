#include"CreateWall.h"
#include<qdebug.h>
bool vis[Horizon_Block_Number][Vertical_Block_Number];//格子是否加入生成树
bool dead_wall[Max_Block_Number][Max_Block_Number];//墙是否被拆除？
vector<pair<Block, Block> >wall_que;//当前可以拓展的边
const int wall_x[4] = { 0,0,1,-1 };
const int wall_y[4] = { -1,1,0,0 };
pair<int, int> Coor_Block(int i, int j) {
	return make_pair(i * Wall_Length + Wall_Length / 2, j * Wall_Length + Wall_Length / 2);
}
Build_Wall::node get_node(pair<int, int> middle, int X_length, int Y_length,int seta) {
	Build_Wall::node temp;
	temp.x = middle.first - X_length / 2;
	temp.y = middle.second - Y_length / 2;
	temp.seta = seta;
	return temp;
}
void test_wall() {//随机生成地图，将信息放入dead_wall。
	memset(vis, 0, sizeof(vis));
	memset(dead_wall, 0, sizeof(dead_wall));
	vis[0][0] = 1;
	wall_que.push_back(make_pair(Block(0, 0), Block(0, 1)));
	while (!wall_que.empty()) {
		int pos = rand() % wall_que.size();
		pair<Block, Block> temp_wall = wall_que[pos];
		wall_que.erase(wall_que.begin() + pos);
		if (!vis[temp_wall.second.x][temp_wall.second.y]) {
			dead_wall[temp_wall.first.id()][temp_wall.second.id()] = true;
			dead_wall[temp_wall.second.id()][temp_wall.first.id()] = true;
			vis[temp_wall.second.x][temp_wall.second.y] = true;
			for (int i = 0; i < 4; ++i) {
				int nx = temp_wall.second.x + wall_x[i];
				int ny = temp_wall.second.y + wall_y[i];
				if (nx < 0 || nx >= Horizon_Block_Number || ny < 0 || ny >= Vertical_Block_Number)continue;
				if (vis[nx][ny])continue;
				wall_que.push_back(make_pair(Block(temp_wall.second.x, temp_wall.second.y), Block(nx, ny)));
			}
		}
	}
}
void Create_Wall() {
	Build_Wall ans;
	test_wall();
	for (int j = 0; j < Vertical_Block_Number; ++j) {
		//边界墙
		pair<int, int> middle = make_pair(0, 
			j * Wall_Length + Wall_Length / 2);
		ans.vertical_wall.push_back(get_node(middle, Wall_Length, Wall_Width, 90));
		middle = make_pair(Horizon_Block_Number * Wall_Length, 
			j * Wall_Length + Wall_Length / 2);
		ans.vertical_wall.push_back(get_node(middle, Wall_Length, Wall_Width, 90));
		//其余墙
		for (int i = 0; i < Horizon_Block_Number-1; ++i) {
			if (!dead_wall[Block(i, j).id()][Block(i + 1, j).id()]) {
				pair<int, int> L = Coor_Block(i, j), R = Coor_Block(i + 1, j);
				middle = make_pair((L.first + R.first) / 2, 
					(L.second + R.second) / 2);
				ans.vertical_wall.push_back(get_node(middle,Wall_Length,Wall_Width,90));
			}
		}
	}
	for (int i = 0; i < Horizon_Block_Number; ++i) {
		//边界墙
		pair<int, int> middle = make_pair(i*Wall_Length+Wall_Length/2,0);
		ans.horizon_wall.push_back(get_node(middle, Wall_Length, Wall_Width, 0));
		middle = make_pair(i * Wall_Length + Wall_Length / 2,
			Vertical_Block_Number*Wall_Length);
		ans.horizon_wall.push_back(get_node(middle, Wall_Length, Wall_Width, 0));
		for (int j = 0; j < Vertical_Block_Number - 1; ++j) {
			if (!dead_wall[Block(i, j).id()][Block(i, j + 1).id()]) {
				pair<int, int> U = Coor_Block(i, j), D = Coor_Block(i, j+1);
				middle = make_pair((U.first + D.first) / 2, 
					(U.second + D.second) / 2);
				ans.horizon_wall.push_back(get_node(middle,Wall_Length,Wall_Width,0));
			}
		}
	}
	for (int i = 0; i < ans.horizon_wall.size(); ++i) {
		Build_Wall::node temp = ans.horizon_wall[i];
		qDebug() << temp.x << " " << temp.y << " " << temp.seta << '\n';
		Wall* nwall = new Wall("Wall", temp.x, temp.y, temp.seta);
	}
	for (int i = 0; i < ans.vertical_wall.size(); ++i) {
		Build_Wall::node temp = ans.vertical_wall[i];
		qDebug() << temp.x << " " << temp.y << " " << temp.seta << '\n';
		Wall* nwall = new Wall("Wall", temp.x, temp.y, temp.seta);
	}
}

/*
void Create_Wall() {
	Build_Wall ans;
	test_wall();
	for (int j = 0; j < Vertical_Block_Number; ++j) {
		//边界墙
		pair<int, int> middle = make_pair(Wall_Width,
			j * Wall_Length + Wall_Length / 2);
		ans.vertical_wall.push_back(get_node(middle, Wall_Width, Wall_Length, 90));
		middle = make_pair(Horizon_Block_Number * Wall_Length+Wall_Width,
			j * Wall_Length + Wall_Length / 2);
		ans.vertical_wall.push_back(get_node(middle, Wall_Width, Wall_Length, 90));
		//其余墙
		for (int i = 0; i < Horizon_Block_Number-1; ++i) {
			if (!dead_wall[Block(i, j).id()][Block(i + 1, j).id()]) {
				pair<int, int> L = Coor_Block(i, j), R = Coor_Block(i + 1, j);
				middle = make_pair((L.first + R.first) / 2+Wall_Width,
					(L.second + R.second) / 2);
				ans.vertical_wall.push_back(get_node(middle,Wall_Width,Wall_Length,90));
			}
		}
	}
	for (int i = 0; i < Horizon_Block_Number; ++i) {
		//边界墙
		pair<int, int> middle = make_pair(i*Wall_Length+Wall_Length/2,0);
		ans.horizon_wall.push_back(get_node(middle, Wall_Length, Wall_Width, 0));
		middle = make_pair(i * Wall_Length + Wall_Length / 2,
			Vertical_Block_Number*Wall_Length);
		ans.horizon_wall.push_back(get_node(middle, Wall_Length, Wall_Width, 0));
		for (int j = 0; j < Vertical_Block_Number - 1; ++j) {
			if (!dead_wall[Block(i, j).id()][Block(i, j + 1).id()]) {
				pair<int, int> U = Coor_Block(i, j), D = Coor_Block(i, j+1);
				middle = make_pair((U.first + D.first) / 2,
					(U.second + D.second) / 2);
				ans.horizon_wall.push_back(get_node(middle,Wall_Length,Wall_Width,0));
			}
		}
	}
	for (int i = 0; i < ans.horizon_wall.size(); ++i) {
		Build_Wall::node temp = ans.horizon_wall[i];
		qDebug() << temp.x << " " << temp.y << " " << temp.seta << '\n';
		Wall* nwall = new Wall("Wall", temp.x, temp.y, temp.seta);
	}
	for (int i = 0; i < ans.vertical_wall.size(); ++i) {
		Build_Wall::node temp = ans.vertical_wall[i];
		qDebug() << temp.x << " " << temp.y << " " << temp.seta << '\n';
		Wall* nwall = new Wall("Wall", temp.x, temp.y, temp.seta);
	}
}
*/