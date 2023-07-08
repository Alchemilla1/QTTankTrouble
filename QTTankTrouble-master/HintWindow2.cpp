#include "HintWindow2.h"
#include "QLabel"
#include "QPixmap"
#include "QKeyEvent"
#include "QTimer"
#include "QPushButton"
#include "QPainter"

hintwindow_2::hintwindow_2(QWidget* parent)
    : QWidget{ parent }
{
    setFixedSize(800, 600);
    QLabel* label1 = new QLabel(this);
    QLabel* label2 = new QLabel(this);
    QLabel* label3 = new QLabel(this);
    QLabel* label4 = new QLabel(this);
    QLabel* label5 = new QLabel(this);
    label1->setText("Press to move");
    label2->setText("Press to shot");
    label3->setText("Press 'Enter' to start");
    label4->setText("Press to move");
    label5->setText("Press to shot");
    QFont font("Comic Sans MS", 32);
    QFont font_bold("Comic Sans MS", 30, QFont::Bold);
    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::black);
    label1->setFont(font);
    label1->setPalette(palette);
    label1->setGeometry(100, 260, 400, 70);
    label4->setFont(font);
    label4->setPalette(palette);
    label4->setGeometry(460, 260, 400, 70);
    label2->setFont(font);
    label2->setPalette(palette);
    label2->setGeometry(100, 370, 400, 70);
    label5->setFont(font);
    label5->setPalette(palette);
    label5->setGeometry(460, 370, 400, 70);
    label3->setFont(font_bold);
    label3->setPalette(palette);
    label3->setGeometry(200, 450, 500, 70);
    button_volume = new QPushButton(this);
    button_volume->setFocusPolicy(Qt::NoFocus);
    QIcon icon_volume(":/TankTrouble/res/volume_black.png");
    button_volume->setFixedSize(50, 50);
    button_volume->setIcon(icon_volume);
    button_volume->setIconSize(QSize(50, 50));
    button_volume->setFlat(1);
    button_volume->move(660, 30);
    button_return = new QPushButton(this);
    button_return->setFocusPolicy(Qt::NoFocus);
    QIcon icon_return(":/TankTrouble/res/button_return.png");
    button_return->setFixedSize(50, 50);
    button_return->setIcon(icon_return);
    button_return->setIconSize(QSize(50, 50));
    button_return->setFlat(1);
    button_return->move(720, 30);
}
void hintwindow_2::paintEvent(QPaintEvent*)
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
    QPixmap up1;
    up1.load(":/TankTrouble/res/press_up_1.png");
    QPixmap right1;
    right1.load(":/TankTrouble/res/press_right_1.png");
    QPixmap left1;
    left1.load(":/TankTrouble/res/press_left_1.png");
    QPixmap down1;
    down1.load(":/TankTrouble/res/press_down_1.png");
    QPixmap m1;
    m1.load(":/TankTrouble/res/press_M_1.png");
    pic.load(":/TankTrouble/res/background.png");
    painter.drawPixmap(0, 0, width(), height(), pic);
    painter.drawPixmap(170, 150, 60, 65, e1);
    painter.drawPixmap(245, 210, 60, 65, f1);
    painter.drawPixmap(115, 210, 60, 65, s1);
    painter.drawPixmap(180, 210, 60, 65, d1);
    painter.drawPixmap(175, 325, 60, 65, q1);
    painter.drawPixmap(540, 150, 60, 57, up1);
    painter.drawPixmap(605, 210, 60, 57, right1);
    painter.drawPixmap(475, 210, 60, 57, left1);
    painter.drawPixmap(540, 210, 60, 57, down1);
    painter.drawPixmap(535, 325, 60, 60, m1);

}
void hintwindow_2::keyPressEvent(QKeyEvent* event) {
    QPainter painter(this);
    switch (event->key()) {

    case Qt::Key_E:
        drawKeyPressedImage(":/TankTrouble/res/press_E_2.png", 170, 150, 60, 65);
        break;
    case Qt::Key_S:
        drawKeyPressedImage(":/TankTrouble/res/press_S_2.png", 115, 210, 60, 65);
        break;
    case Qt::Key_D:
        drawKeyPressedImage(":/TankTrouble/res/press_D_2.png", 180, 210, 60, 65);
        break;
    case Qt::Key_F:
        drawKeyPressedImage(":/TankTrouble/res/press_F_2.png", 245, 210, 60, 65);
        break;
    case Qt::Key_Q:
        drawKeyPressedImage(":/TankTrouble/res/press_Q_2.png", 175, 325, 60, 65);
        break;
    case Qt::Key_Up:
        drawKeyPressedImage(":/TankTrouble/res/press_up_2.png", 540, 150, 60, 57);
        break;
    case Qt::Key_Left:
        drawKeyPressedImage(":/TankTrouble/res/press_left_2.png", 475, 210, 60, 57);
        break;
    case Qt::Key_Down:
        drawKeyPressedImage(":/TankTrouble/res/press_down_2.png", 540, 210, 60, 57);
        break;
    case Qt::Key_Right:
        drawKeyPressedImage(":/TankTrouble/res/press_right_2.png", 605, 210, 60, 57);
        break;
    case Qt::Key_M:
        drawKeyPressedImage(":/TankTrouble/res/press_M_2.png", 535, 325, 60, 60);
        break;
    }
}
void hintwindow_2::drawKeyPressedImage(const QString& imagePath, int x, int y, int width, int height) {
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

