#include "MenuWindow.h"
#include "QPainter"
#include "QPixmap"
menu_window::menu_window(QWidget* parent)
    : QWidget{ parent }
{
    setFixedSize(500, 500);
    QIcon icon2(":/new/prefix1/res/game_over.png");
    game_over = new QPushButton(this);
    game_over->setFixedSize(240, 80);
    game_over->setIcon(icon2);
    game_over->setIconSize(QSize(240, 80));
    game_over->setFlat(1);
    game_over->move(140, 280);
    QIcon icon1(":/new/prefix1/res/return_game.png");
    return_game = new QPushButton(this);
    return_game->setFixedSize(240, 80);
    return_game->setIcon(icon1);
    return_game->setIconSize(QSize(240, 80));
    return_game->setFlat(1);
    return_game->move(140, 180);
}
void menu_window::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    QPixmap pic;
    QPixmap title;
    title.load(":/new/prefix1/res/title1.png");
    pic.load(":/new/prefix1/res/menu_background.png");
    painter.drawPixmap(0, 0, width(), height(), pic);
    painter.drawPixmap(-40, -50, 600, 400, title);
}
