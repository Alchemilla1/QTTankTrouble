#include "EndWindow.h"
#include "QPainter"

end_window::end_window(int _mode, int _blue_score, int _red_score, QWidget* parent)
    : QWidget{ parent }
{
    setFixedSize(800, 600);
    mode = _mode;
    blue_score = _blue_score;
    red_score = _red_score;
    QIcon icon(":/TankTrouble/res/exit.png");
    exit = new QPushButton(this);
    exit->setFixedSize(240, 80);
    exit->setIcon(icon);
    exit->setIconSize(QSize(240, 80));
    exit->setFlat(1);
    exit->move(280, 480);
}

void end_window::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    QPixmap pic1, pic2, bluescore, redscore;
    pic1.load(":/TankTrouble/res/end_background1.png");
    pic2.load(":/TankTrouble/res/end_background2.png");
    bluescore.load(":/TankTrouble/res/blue_scoreboard.png");
    redscore.load(":/TankTrouble/res/red_scoreboard.png");
    if (mode == 1) {
        painter.drawPixmap(0, 0, width(), height(), pic1);
    }
    else if (mode == 2) {
        painter.drawPixmap(0, 0, width(), height(), pic2);
    }
    painter.drawPixmap(180, 140, 280, 280, bluescore);
    painter.drawPixmap(330, 133, 280, 280, redscore);
    QFont font("Chalkduster", 68, QFont::Bold);
    painter.setFont(font);
    painter.setPen(Qt::white);
    painter.drawText(290, 290, QString::number(blue_score));
    painter.drawText(440, 290, QString::number(red_score));
    if (blue_score > red_score) {
        QPixmap blue_tank, red_tank;
        blue_tank.load(":/TankTrouble/res/blue_win.png");
        red_tank.load(":/TankTrouble/res/red_lose.png");
        painter.drawPixmap(20, 200, 230, 230, blue_tank);
        painter.drawPixmap(540, 200, 230, 230, red_tank);
        QPixmap blue_res, red_res;
        blue_res.load(":/TankTrouble/res/blue_win_tag.png");
        red_res.load(":/TankTrouble/res/red_lose_tag.png");
        painter.drawPixmap(40, 345, 230, 160, blue_res);
        painter.drawPixmap(540, 355, 190, 130, red_res);
    }
    else if (blue_score == red_score) {
        QPixmap blue_tank, red_tank;
        blue_tank.load(":/TankTrouble/res/blue_win.png");
        red_tank.load(":/TankTrouble/res/red_win.png");
        painter.drawPixmap(20, 200, 230, 230, blue_tank);
        painter.drawPixmap(540, 200, 230, 230, red_tank);
        QPixmap blue_res, red_res;
        blue_res.load(":/TankTrouble/res/blue_win_tag.png");
        red_res.load(":/TankTrouble/res/red_win_tag.png");
        painter.drawPixmap(40, 345, 230, 160, blue_res);
        painter.drawPixmap(540, 355, 190, 130, red_res);
    }
    else {
        QPixmap blue_tank, red_tank;
        blue_tank.load(":/TankTrouble/res/blue_lose.png");
        red_tank.load(":/TankTrouble/res/red_win.png");
        painter.drawPixmap(20, 200, 230, 230, blue_tank);
        painter.drawPixmap(540, 200, 230, 230, red_tank);
        QPixmap blue_res, red_res;
        blue_res.load(":/TankTrouble/res/blue_lose_tag.png");
        red_res.load(":/TankTrouble/res/red_win_tag.png");
        painter.drawPixmap(40, 345, 230, 160, blue_res);
        painter.drawPixmap(540, 355, 190, 130, red_res);
    }
}
void end_window::draw_end(QPainter& painter) {
    if (mode == 1) {
        QFont font("Comic Sans MS", 36, QFont::Bold);
        painter.setFont(font);
        painter.setPen(Qt::black);
        painter.drawText(50, 100, "Player");
        painter.drawText(500, 100, "Computer");
    }
    else if (mode == 2) {
        QFont font("Comic Sans MS", 36, QFont::Bold);
        painter.setFont(font);
        painter.setPen(Qt::black);
        painter.drawText(50, 100, "Player1");
        painter.drawText(500, 100, "Player2");
    }

}
