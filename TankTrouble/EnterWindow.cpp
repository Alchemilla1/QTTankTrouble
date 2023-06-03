#include "EnterWindow.h"
//#include "widget.h"
#include"QPushButton"
#include"QLabel"
#include <QVBoxLayout>
#include <QMessageBox>


enter_window::enter_window(QWidget* parent)
	: QWidget(parent)
{

	setFixedSize(800, 600);
	QIcon icon_volume(":/TankTrouble/res/volume.png");
	QIcon icon1(":/TankTrouble/res/button1.png");
	QIcon icon2(":/TankTrouble/res/button2.png");
	QIcon icon3(":/TankTrouble/res/button3.png");
	button_volume = new QPushButton(this);
	button_volume->setFixedSize(50, 50);
	button_volume->setIcon(icon_volume);
	button_volume->setIconSize(QSize(50, 50));
	button_volume->setFlat(1);
	button_volume->move(720, 530);


	button_start1 = new QPushButton(this);
	button_start1->setFixedSize(240, 80);
	button_start1->setIcon(icon1);
	button_start1->setIconSize(QSize(240, 80));
	button_start1->setFlat(1);
	button_start1->move(280, 270);

	button_start2 = new QPushButton(this);
	button_start2->setFixedSize(240, 80);
	button_start2->setIcon(icon2);
	button_start2->setIconSize(QSize(240, 80));
	button_start2->setFlat(1);
	button_start2->move(280, 350);



	button_exit = new QPushButton(this);
	button_exit->setFixedSize(240, 80);
	button_exit->setIcon(icon3);
	button_exit->setIconSize(QSize(240, 80));
	button_exit->setFlat(1);
	button_exit->move(280, 430);

	connect(button_exit, &QPushButton::clicked, this, [&]() {
		QMessageBox messageBox;
	/*messageBox.setText("您是否要退出?");*/
	messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

	// 设置默认按钮为 No
	messageBox.setDefaultButton(QMessageBox::No);

	// 设置对话框图标为 Question 图标
	messageBox.setIcon(QMessageBox::Question);

	// 显示对话框并获取用户响应
	int response = messageBox.exec();

	// 判断用户选择的响应
	if (response == QMessageBox::Yes) {
		// 用户选择退出
		/*QApplication::quit();*/
	}
		});
}

enter_window::~enter_window()
{
	delete ui;
}

void enter_window::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	QPixmap pic;

	pic.load(":/TankTrouble/res/title1.png");
	painter.drawPixmap(0, 0, width(), height(), QPixmap(":/TankTrouble/res/24054060_0_final.png"));
	painter.drawPixmap(-100, -30, 1000, 700, pic);

}

