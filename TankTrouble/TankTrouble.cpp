#include "TankTrouble.h"
#include<qlabel.h>
#include<qstring.h>
#include"painting.h"
#include"CreateWall.h"
#include<qdebug.h>

class Object;

TankTrouble::TankTrouble(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	GameStart();
	QIcon icon_volume(":/TankTrouble/res/volume_black.png");
	QIcon icon_menu(":/TankTrouble/res/button_menu.png");
	button_volume = new QPushButton(this);
	button_volume->setFocusPolicy(Qt::NoFocus);
	button_volume->setFixedSize(50, 50);
	button_volume->setIcon(icon_volume);
	button_volume->setIconSize(QSize(50, 50));
	button_volume->setFlat(1);
	button_volume->move(930, 10);
	button_menu = new QPushButton(this);
	button_menu->setFocusPolicy(Qt::NoFocus);
	button_menu->setFixedSize(50, 50);
	button_menu->setIcon(icon_menu);
	button_menu->setIconSize(QSize(50, 50));
	button_menu->setFlat(1);
	button_menu->move(980, 10);
	bluescore = 0; redscore = 0;
	pic_tank_blue.load(":/TankTrouble/res/tank_blue.png");
	pic_tank_red.load(":/TankTrouble/res/tank_red.png");
	score_board.load(":/TankTrouble/res/score_board.png");
	pic.load(":/TankTrouble/res/newbackground.png");
}

TankTrouble::~TankTrouble()
{
	delete timer;
}
void TankTrouble::GameStart()
{

	Create_Wall();
	Tank::A = Set_Tank(0);
	Tank::B = Set_Tank(1);
	timer->setInterval(10);
	connect(timer, &QTimer::timeout, [=]() {
		updateAll();
	update();
		});
	timer->start(FPS); // 每隔16毫秒刷新一次（约60帧每秒）

}
void TankTrouble::draw_score(QPainter& painter)
{
	QFont font("Chalkduster", 52, QFont::Bold);
	painter.setFont(font);
	painter.setPen(Qt::white);
	painter.drawText(395, 750, QString::number(bluescore));
	painter.drawText(585, 750, QString::number(redscore));
}
void TankTrouble::update_score(int new_blue_score, int new_red_score)
{
	bluescore = new_blue_score;
	redscore = new_red_score;
	update(); // 触发重绘
}


void TankTrouble::keyPressEvent(QKeyEvent* event)
{
	qDebug() << event->key();
	switch (event->key())
	{
	case Qt::Key_E:

		//设置按键种类标志位
		key0.E = 1;
		return;

	case Qt::Key_S:

		key0.S = 1;
		return;

	case Qt::Key_D:

		key0.D = 1;
		return;

	case Qt::Key_F:

		key0.F = 1;
		return;

	case Qt::Key_Q:

		key0.Q = 2;
		return;

	case Qt::Key_Up:
		key1.Up = 1;
		return;
	case Qt::Key_Left:
		key1.Left = 1;
		return;
	case Qt::Key_Down:
		key1.Down = 1;
		return;
	case Qt::Key_Right:
		key1.Right = 1;
		return;

	case Qt::Key_M:
		key1.M = 2;
		return;
	default:
		break;
	}
}

void TankTrouble::keyReleaseEvent(QKeyEvent* event)
{
	switch (event->key())
	{
		//有按键松开时即将按键标志位置0
	case Qt::Key_E:
		key0.E = 0;
		return;

	case Qt::Key_S:
		key0.S = 0;
		return;

	case Qt::Key_D:
		key0.D = 0;
		return;

	case Qt::Key_F:
		key0.F = 0;
		return;

	case Qt::Key_Q:
		key0.Q = 0;
		return;

	case Qt::Key_Up:
		key1.Up = 0;
		return;
	case Qt::Key_Left:
		key1.Left = 0;
		return;
	case Qt::Key_Down:
		key1.Down = 0;
		return;
	case Qt::Key_Right:
		key1.Right = 0;
		return;

	case Qt::Key_M:
		key1.M = 0;
		return;

	default:
		break;

	}
}

void TankTrouble::DoOperation()
{
	QPainter painter(this);
	if (key0.E && isAliveA)
		Tank::A->forward();
	if (key0.D && isAliveA)
		Tank::A->backward();
	if (key0.S && isAliveA)
		Tank::A->anticlock_rotate();
	if (key0.F && isAliveA)
		Tank::A->clock_rotate();
	if (key0.Q == 2 && isAliveA)
	{
		Tank::A->fire();
		key0.Q = 1;
	}
	if (key1.Up && isAliveB)
		Tank::B->forward();
	if (key1.Down && isAliveB)
		Tank::B->backward();
	if (key1.Left && isAliveB)
		Tank::B->anticlock_rotate();
	if (key1.Right && isAliveB)
		Tank::B->clock_rotate();
	if (key1.M == 2 && isAliveB)
	{
		Tank::B->fire();
		key1.M = 1;
	}
}

void TankTrouble::updateAll()
{

	for (auto& obj : Object::object)
	{
		if (obj->alive == 0 && obj->name == "Tank")
		{
			paintExplode* p = new paintExplode(obj->x + Horizon_Bias, obj->y + Vertical_Bias);
			toExplode.push_back(p);
		}
	}

	Object::object.erase(std::copy_if(Object::object.begin(), Object::object.end(),
		Object::object.begin(),
		[this](Object* obj) -> bool {
			if (!obj->alive) {
				if (obj->name == "Tank")
				{
					dynamic_cast<Tank*>(obj)->tank_color == 0 ? isAliveA = 0 : isAliveB = 0;
					delete obj;
					return false;
				}
				else if (obj->name == "Bullet")
				{
					dynamic_cast<Bullet*>(obj)->p->bullet_count--;
				}
				delete obj;
				return false;
			}
			else {
				return true;
			}
		}),
		Object::object.end());

	for (auto& obj : Object::object)
	{
		if (obj->name == "Bullet")
		{
			obj->forward();
		}
	}


}

void TankTrouble::paintEvent(QPaintEvent* event) {


	QPainter painter(this);
	resize(Map_Width, Map_Height);

	//draw mainscene
	int flag = 0;
	painter.drawPixmap(0, 0, width(), height(), pic);
	painter.drawPixmap(270, 670, 100, 100, pic_tank_blue);
	painter.drawPixmap(680, 670, 100, 100, pic_tank_red);
	painter.drawPixmap(380, 690, 290, 70, score_board);
	draw_score(painter);
	for (auto& temp : Object::object)
	{
		if (temp)
		{
			QPolygon p = temp->Transform();
			paintingImage(temp, painter, flag);
		}
	}

	//draw explode
	for (vector<paintExplode*>::iterator it = toExplode.begin(); it != toExplode.end(); )
	{

		if ((*it)->if_explode == 0)
		{
			delete (*it);
			toExplode.erase(it);
		}
		else
		{
			painter.drawPixmap((*it)->m_x - Explode_Bias, (*it)->m_y - Explode_Bias, (*it)->source[(*it)->m_index]);
			(*it)->updateExplode();
			it++;
		}
		if (toExplode.size() == 0)
			break;
	}





	//keyboard operation

	DoOperation();

}



