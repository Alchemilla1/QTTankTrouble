#ifndef ENTER_WINDOW_H
#define ENTER_WINDOW_H
#include <QWidget>
#include<QPainter>
#include<QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class enter_window : public QWidget
{
	Q_OBJECT

public:
	explicit enter_window(QWidget* parent = 0);
	~enter_window();
	QPushButton* button_volume;
	QPushButton* button_start1;
	QPushButton* button_start2;
	QPushButton* button_exit;

private:
	Ui::Widget* ui;
	void paintEvent(QPaintEvent* event) override;
};
#endif // ENTER_WINDOW_H
