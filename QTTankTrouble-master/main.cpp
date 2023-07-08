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
//#include <QtMultimedia/QMediaPlayer>	// VS向.pro文件添加代码的方式
#include "AllWindow.h"
using namespace std;

int main(int argc, char* argv[])
{
	srand(time(0));
	QApplication a(argc, argv);
	allwindow e;
	return a.exec();
}
