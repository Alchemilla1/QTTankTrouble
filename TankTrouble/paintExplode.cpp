#include "paintExplode.h"
#include<qdebug.h>

paintExplode::paintExplode(int _x, int _y) :m_x(_x), m_y(_y)
{
	QPixmap pic1, pic2, pic3, pic4, pic5, pic6, pic7, pic8;
	pic1.load(":/TankTrouble/res/explodeNo1.png");
	pic2.load(":/TankTrouble/res/explodeNo2.png");
	pic3.load(":/TankTrouble/res/explodeNo3.png");
	pic4.load(":/TankTrouble/res/explodeNo4.png");
	pic5.load(":/TankTrouble/res/explodeNo5.png");
	pic6.load(":/TankTrouble/res/explodeNo6.png");
	pic7.load(":/TankTrouble/res/explodeNo7.png");
	pic8.load(":/TankTrouble/res/explodeNo8.png");

	source.push_back(pic1);
	source.push_back(pic2);
	source.push_back(pic3);
	source.push_back(pic4);
	source.push_back(pic5);
	source.push_back(pic6);
	source.push_back(pic7);
	source.push_back(pic8);

	m_index = 0;
	explode_record = 0;
	if_explode = true;

}


void paintExplode::updateExplode()
{
	if (!if_explode)
		return;
	if (++explode_record < Bomb_Interval)
		return;

	m_index++;

	if (m_index > Explode_Num - 1)
	{
		m_index = 0;
		if_explode = false;
	}
}