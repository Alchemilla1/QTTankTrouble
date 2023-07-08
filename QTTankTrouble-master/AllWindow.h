#ifndef ALLWINDOW_H
#define ALLWINDOW_H
#include "EnterWindow.h"
#include "HintWindow1.h"
#include "HintWindow2.h"
#include "MenuWindow.h"
#include "QKeyEvent"
#include "QApplication"
#include "TankTrouble.h"
#include "EndWindow.h"
#include <QWidget>


class TankTrouble;
class menu_window;
class hint_window_1;
class hint_window_2;
class end_window;
class enter_window;
//class PVCGame;

class allwindow : public QWidget
{
	Q_OBJECT
public:
	explicit allwindow(QWidget* parent = nullptr);
	~allwindow();
	void start_1();
	void start_2();
	void return_1();
	void return_2();
	void menu_show();
	void close_window();
	void menu_over();
	//void exit();
	void play_music1();
	void play_music2();
	void play_music3();
	void play_music4();



	enter_window* Enter_window;
	hintwindow_1* Hint_window_1;
	hintwindow_2* Hint_window_2;
	TankTrouble* Gamewindow;
	menu_window* Menuwindow;
	end_window* Endwindow;
	//PVCGame* PVCGamewindow;
	int gamemode, redscore, bluescore;

signals:
protected:

	bool eventFilter(QObject* obj, QEvent* event) override;

};

#endif // ALLWINDOW_H
