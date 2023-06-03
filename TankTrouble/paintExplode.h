#pragma once
#include<qpixmap.h>
#include "config.h"
class paintExplode
{
public:
	int m_x;
	int m_y;
	bool if_explode;
	int explode_record;
	int m_index;
	std::vector<QPixmap> source;

	paintExplode(int _x, int _y);
	void updateExplode();
};

