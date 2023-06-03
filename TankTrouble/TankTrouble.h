#pragma once

#include <QtWidgets/QMainWindow>
#include <QPaintEvent>
#include <qpainter.h>
#include "Object.h"
#include "ui_TankTrouble.h"
#include "Object.h"
#include "Tank.h"
#include "ToolBox.h"
#include "Bullet.h"
#include "Wall.h"
#include "Prepare.h"
#include <qvector.h>
#include <qtimer.h>
#include "paintExplode.h"
#include <QPushButton>

class TankTrouble : public QMainWindow
{
	Q_OBJECT

public:

	vector<paintExplode*> toExplode{};
	bool isAliveA = 1;
	bool isAliveB = 1;
	QPushButton* button_volume;
	QPushButton* button_menu;



	TankTrouble(QWidget* parent = nullptr);
	~TankTrouble();
	void keyPressEvent(QKeyEvent* event) override;
	void keyReleaseEvent(QKeyEvent* event) override;
	void GameStart();
	void DoOperation();
	void updateAll();
	void draw_score(QPainter& painter);
	void update_score(int new_bluescore, int new_redscore);


protected:
	void paintEvent(QPaintEvent* event) override;
private:
	Ui::TankTroubleClass ui;
	QTimer* timer = new QTimer(this);
	bool keyPressFlag;
	struct {
		bool E = 0;
		bool S = 0;
		bool D = 0;
		bool F = 0;
		int Q = 0;
	}key0;
	struct {
		bool Up = 0;
		bool Left = 0;
		bool Down = 0;
		bool Right = 0;
		int M = 0;
	}key1;

	int bluescore = 0;
	int redscore = 0;
	QPixmap pic;
	QPixmap pic_tank_blue, pic_tank_red, score_board;
};


