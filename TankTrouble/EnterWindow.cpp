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
	/*messageBox.setText("���Ƿ�Ҫ�˳�?");*/
	messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

	// ����Ĭ�ϰ�ťΪ No
	messageBox.setDefaultButton(QMessageBox::No);

	// ���öԻ���ͼ��Ϊ Question ͼ��
	messageBox.setIcon(QMessageBox::Question);

	// ��ʾ�Ի��򲢻�ȡ�û���Ӧ
	int response = messageBox.exec();

	// �ж��û�ѡ�����Ӧ
	if (response == QMessageBox::Yes) {
		// �û�ѡ���˳�
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

