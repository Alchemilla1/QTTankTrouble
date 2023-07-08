#pragma once

#include"config.h"
#include<qpixmap.h>
#include"Object.h"
#include<qpainter.h>




void paintingImage(Object* obj, QPainter& painter, int& flagColor)
{

	if (obj == nullptr)
		return;

	painter.translate(obj->x + Horizon_Bias * 2, obj->y + Vertical_Bias * 2);
	painter.rotate(obj->seta);

	if (obj->name == "Wall")
		painter.drawPixmap(-Wall_Length / 2, -Wall_Width / 2, obj->picture);
	else if (obj->name == "Tank")
		painter.drawPixmap(-Tank_Length / 2, -Tank_Width / 2, obj->picture);
	else if (obj->name == "Bullet")
		painter.drawPixmap(-Bullet_D / 2, -Bullet_D / 2, obj->picture);
	else if (obj->name == "ToolBox")
		painter.drawPixmap(-ToolBox_Length / 2, -ToolBox_Length / 2, obj->picture);
	else if (obj->name == "Mine")
		painter.drawPixmap(-Bullet_D / 2, -Bullet_D / 2, obj->picture);

	painter.resetTransform();
}