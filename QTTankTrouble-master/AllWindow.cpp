#include "AllWindow.h"
#include "EnterWindow.h"
#include "HintWindow1.h"
#include "HintWindow2.h"
#include "MenuWindow.h"
#include <QGraphicsOpacityEffect>
#include "QKeyEvent"
#include "QApplication"
#include "TankTrouble.h"
#include "EndWindow.h"
#include "music.h"

music* allmusic;

allwindow::allwindow(QWidget* parent)
	: QWidget{ parent }
{
	Enter_window = new enter_window;
	Enter_window->show();
	Hint_window_1 = new hintwindow_1;
	Hint_window_2 = new hintwindow_2;
	Gamewindow = new TankTrouble;
	Menuwindow = new menu_window;
	allmusic = new music;
	//PVCGamewindow = new PVCGame;
	allmusic->musicplayer1->play();
	//Menuwindow->show();
	allwindow::start_1();
	allwindow::start_2();
	allwindow::return_1();
	allwindow::return_2();
	allwindow::menu_show();
	allwindow::close_window();
	allwindow::menu_over();

	allwindow::play_music1();
	allwindow::play_music2();
	allwindow::play_music3();
	allwindow::play_music4();



	QApplication::instance()->installEventFilter(this);
}

allwindow::~allwindow() {

}
void allwindow::start_1() {
	connect(Enter_window->button_start1, &QPushButton::clicked, this, [&]() {
		Enter_window->hide();
		Hint_window_1->show();
		});
}
void allwindow::start_2() {
	connect(Enter_window->button_start2, &QPushButton::clicked, this, [&]() {
		Enter_window->hide();
		Hint_window_2->show();
		});
}
void allwindow::return_1() {
	connect(Hint_window_1->button_return, &QPushButton::clicked, this, [&]() {
		Hint_window_1->hide();
		Enter_window->show();
		});
}
void allwindow::return_2() {
	connect(Hint_window_2->button_return, &QPushButton::clicked, this, [&]() {
		Hint_window_2->hide();
		Enter_window->show();
		});
}

bool allwindow::eventFilter(QObject* obj, QEvent* event)
{
	if (event->type() == QEvent::KeyPress) {
		QKeyEvent* keyEvent = dynamic_cast<QKeyEvent*>(event);
		if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
			if (Hint_window_1->isVisible()) {
				Hint_window_1->hide();
				Gamewindow->Gamemode = 0;
				Gamewindow->show();
			}
			else if (Hint_window_2->isVisible()) {
				Hint_window_2->hide();
				Gamewindow->Gamemode = 1;
				Gamewindow->show();
				Gamewindow->update_score(0, 0);
			}
		}
	}
	return QObject::eventFilter(obj, event);
}
void allwindow::menu_show() {
	connect(Gamewindow->button_menu, &QPushButton::clicked, this, [&]() {
		//Hint_window_2->hide();
		QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(Gamewindow);
		opacityEffect->setOpacity(0.5);
		Gamewindow->setGraphicsEffect(opacityEffect);
		Menuwindow->show();

		});
}
void allwindow::close_window() {
	connect(Menuwindow->return_game, &QPushButton::clicked, this, [&]() {
		Menuwindow->hide();
		});
}
void allwindow::menu_over() {
	connect(Menuwindow->game_over, &QPushButton::clicked, this, [&]() {
		Menuwindow->hide();
		Gamewindow->hide();
		Endwindow = new end_window(2, Gamewindow->bluescore, Gamewindow->redscore);
		Endwindow->show();
		connect(Endwindow->exit, &QPushButton::clicked, this, [&]() {

			Endwindow->hide();
			Enter_window->show();
			});
		});

}

void allwindow::play_music1() {
	connect(Enter_window->button_volume, &QPushButton::clicked, this, [&]() {
		allmusic->show();
		//allmusic->animation_blue();
		allmusic->show();
		//allmusic->musicplayer1->play();
		});
}

void allwindow::play_music2() {
	connect(Hint_window_1->button_volume, &QPushButton::clicked, this, [&]() {
		allmusic->show();
		//allmusic->musicplayer1->play();
		});
}

void allwindow::play_music3() {
	connect(Hint_window_2->button_volume, &QPushButton::clicked, this, [&]() {
		allmusic->show();
		//allmusic->animation_blue();
		//allmusic->musicplayer1->play();
		});
}

void allwindow::play_music4() {
	connect(Gamewindow->button_volume, &QPushButton::clicked, this, [&]() {
		allmusic->show();
		});
}