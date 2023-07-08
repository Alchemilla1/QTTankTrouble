#include "HintWindow1.h"
#include "QLabel"
#include "QPixmap"
#include "QKeyEvent"
#include "QTimer"
#include "QPushButton"

hintwindow_1::hintwindow_1(QWidget* parent)
	: QWidget{ parent }
{
	setFixedSize(800, 600);
	QLabel* label1 = new QLabel(this);
	QLabel* label2 = new QLabel(this);
	QLabel* label3 = new QLabel(this);// 创建指针类型的 QLabel 对象
	label1->setText("Press to move");
	label2->setText("Press to shot");
	label3->setText("Press 'Enter' to start");
	QFont font("Comic Sans MS", 40);
	QFont font_bold("Comic Sans MS", 30, QFont::Bold);
	QPalette palette;
	palette.setColor(QPalette::WindowText, Qt::black);
	label1->setFont(font);
	label1->setPalette(palette);
	label1->setGeometry(140, 360, 400, 70);
	label2->setFont(font);
	label2->setPalette(palette);
	label2->setGeometry(450, 320, 400, 70);
	label3->setFont(font_bold);
	label3->setPalette(palette);
	label3->setGeometry(200, 450, 500, 70);
	button_volume = new QPushButton(this);
	QIcon icon_volume(":/TankTrouble/res/volume_black.png");
	button_volume->setFixedSize(50, 50);
	button_volume->setIcon(icon_volume);
	button_volume->setIconSize(QSize(50, 50));
	button_volume->setFlat(1);
	button_volume->move(660, 30);
	button_return = new QPushButton(this);
	QIcon icon_return(":/TankTrouble/res/button_return.png");
	button_return->setFixedSize(50, 50);
	button_return->setIcon(icon_return);
	button_return->setIconSize(QSize(50, 50));
	button_return->setFlat(1);
	button_return->move(720, 30);
}
void hintwindow_1::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	QPixmap pic;
	QPixmap e1;
	e1.load(":/TankTrouble/res/press_E_1.png");
	QPixmap f1;
	f1.load(":/TankTrouble/res/press_F_1.png");
	QPixmap s1;
	s1.load(":/TankTrouble/res/press_S_1.png");
	QPixmap d1;
	d1.load(":/TankTrouble/res/press_D_1.png");
	QPixmap q1;
	q1.load(":/TankTrouble/res/press_Q_1.png");
	pic.load(":/TankTrouble/res/background.png");
	painter.drawPixmap(0, 0, width(), height(), pic);
	painter.drawPixmap(200, 170, 90, 100, e1);
	painter.drawPixmap(320, 275, 90, 100, f1);
	painter.drawPixmap(120, 275, 90, 100, s1);
	painter.drawPixmap(220, 275, 90, 100, d1);
	painter.drawPixmap(520, 225, 90, 100, q1);

}
void hintwindow_1::keyPressEvent(QKeyEvent* event) {
	QPainter painter(this);
	switch (event->key()) {

	case Qt::Key_E:
		drawKeyPressedImage(":/TankTrouble/res/press_E_2.png", 200, 170, 90, 100);
		break;
	case Qt::Key_S:
		drawKeyPressedImage(":/TankTrouble/res/press_S_2.png", 120, 275, 90, 100);
		break;
	case Qt::Key_D:
		drawKeyPressedImage(":/TankTrouble/res/press_D_2.png", 220, 275, 90, 100);
		break;
	case Qt::Key_F:
		drawKeyPressedImage(":/TankTrouble/res/press_F_2.png", 320, 275, 90, 100);
		break;
	case Qt::Key_Q:
		drawKeyPressedImage(":/TankTrouble/res/press_Q_2.png", 520, 225, 90, 100);
		break;
	default:
		break;
	}
}
void hintwindow_1::drawKeyPressedImage(const QString& imagePath, int x, int y, int width, int height) {
	QPixmap pixmap(imagePath);
	if (!pixmap.isNull()) {
		QLabel* label = new QLabel(this);
		label->setPixmap(pixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation));
		label->setGeometry(x, y, width, height);
		label->setScaledContents(true); // 设置自动适应大小
		label->setWindowFlags(Qt::WindowStaysOnTopHint);
		label->show();
		QTimer::singleShot(200, label, [label]() {
			label->deleteLater(); // 在一秒后删除label
			});
	}
}
