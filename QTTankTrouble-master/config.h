#pragma once
#define FPS 30//����֡��

#define Map_Height 768//��ͼ����߶�
#define Map_Width 1050//��ͼ������
#define Wall_Length 91//�������ӱ߳�
#define Wall_Width 8//ǽ�ڿ��
#define Tank_Length 40//̹�˵ĳ���
#define Tank_Width 22//̹�˵Ŀ��
#define Bullet_D 10//�ӵ��������ΰ������߳�8
#define Mine_D 15 //���װ뾶
#define Horizon_Block_Number 10//���������
#define Vertical_Block_Number 7//���������
#define Max_Block_Number Horizon_Block_Number*Vertical_Block_Number //�ܹ�������
#define Horizon_Bias Wall_Length / 2 + Wall_Width / 2//����ͼ��ƫ��
#define Vertical_Bias Wall_Width + Wall_Width / 2//����ͼ��ƫ��

#define Tank_Speed 6
#define Bullet_Speed 8
#define Rotate_Speed 8

#define Bullet_Life FPS*15 //���15s
#define Tool_Count 3

#define Bomb_Interval 10
#define Explode_Num 8
#define Explode_Bias 20

#define  Timer_Stop 80
#define ToolBox_Length 25 //������Ŀ��