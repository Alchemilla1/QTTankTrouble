#include "MenuWindow.h"
#include "QPainter"
#include "QPixmap"

menu_window::menu_window(QWidget* parent)
    : QWidget{ parent }
{
    setFixedSize(500, 500);
    QIcon icon2(":/TankTrouble/res/game_over.png");
    game_over = new QPushButton(this);
    game_over->setFixedSize(240, 80);
    game_over->setIcon(icon2);
    game_over->setIconSize(QSize(240, 80));
    game_over->setFlat(1);
    game_over->move(140, 280);
    QIcon icon1(":/TankTrouble/res/return_game.png");
    game_over = new QPushButton(this);
    game_over->setFixedSize(240, 80);
    game_over->setIcon(icon1);
    game_over->setIconSize(QSize(240, 80));
    game_over->setFlat(1);
    game_over->move(140, 180);
}
void menu_window::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    QPixmap pic;
    QPixmap title;
    title.load(":/TankTrouble/res/title1.png");
    pic.load(":/TankTrouble/res/menu_background.png");
    painter.drawPixmap(0, 0, width(), height(), pic);
    painter.drawPixmap(-40, -50, 600, 400, title);
}
