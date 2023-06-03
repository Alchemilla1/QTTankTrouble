#include "TankTrouble.h"
#include "config.h"
#include "CreateWall.h"
#include "Tank.h"
#include "Bullet.h"
#include "Wall.h"
#include "ToolBox.h"
#include "Prepare.h"
#include <QtWidgets/QApplication>
#include <qpainter.h>
#include <qlabel.h>
#include <iostream>
#include "AllWindow.h"
using namespace std;
int main(int argc, char* argv[])
{
	srand(time(0));
	QApplication a(argc, argv);

	allwindow e;
	//w.resize(Map_Width, Map_Height);
	//
	//w.show();
	return a.exec();
}
