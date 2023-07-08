#pragma once
#define FPS 30//更新帧率

#define Map_Height 768//地图纵向高度
#define Map_Width 1050//地图横向宽度
#define Wall_Length 91//单个格子边长
#define Wall_Width 8//墙壁宽度
#define Tank_Length 40//坦克的长度
#define Tank_Width 22//坦克的宽度
#define Bullet_D 10//子弹用正方形包裹，边长8
#define Mine_D 15 //地雷半径
#define Horizon_Block_Number 10//横向格子数
#define Vertical_Block_Number 7//纵向格子数
#define Max_Block_Number Horizon_Block_Number*Vertical_Block_Number //总共格子数
#define Horizon_Bias Wall_Length / 2 + Wall_Width / 2//横向图形偏置
#define Vertical_Bias Wall_Width + Wall_Width / 2//纵向图形偏置

#define Tank_Speed 6
#define Bullet_Speed 8
#define Rotate_Speed 8

#define Bullet_Life FPS*15 //存活15s
#define Tool_Count 3

#define Bomb_Interval 10
#define Explode_Num 8
#define Explode_Bias 20

#define  Timer_Stop 80
#define ToolBox_Length 25 //道具箱的宽度