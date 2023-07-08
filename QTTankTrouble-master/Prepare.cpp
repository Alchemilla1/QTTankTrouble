#include "Prepare.h"

Tank* Set_Tank(int color) {

	int X, Y, x, y, seta;
	Tank* temp;
	X = rand() % Horizon_Block_Number;
	Y = rand() % Vertical_Block_Number;
	x = X * Wall_Length;
	y = Y * Wall_Length + Wall_Length / 2;
	seta = rand() % 360;
	temp = new Tank("Tank", x, y, seta, color);
	return temp;
}

