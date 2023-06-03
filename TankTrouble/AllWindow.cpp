#include "AllWindow.h"
#include "EnterWindow.h"
#include "HintWindow1.h"
#include "HintWindow2.h"
#include "MenuWindow.h"
#include <QGraphicsOpacityEffect>
#include "QKeyEvent"
#include "QApplication"
#include "TankTrouble.h"
enter_window* Enter_window;
hintwindow_1* Hint_window_1;
hintwindow_2* Hint_window_2;
TankTrouble* Gamewindow;
menu_window* Menuwindow;

allwindow::allwindow(QWidget* parent)
    : QWidget{ parent }
{
    Enter_window = new enter_window;
    Enter_window->show();
    Hint_window_1 = new hintwindow_1;
    Hint_window_2 = new hintwindow_2;
    Gamewindow = new TankTrouble;
    Menuwindow = new menu_window;
    //Menuwindow->show();
    allwindow::start_1();
    allwindow::start_2();
    allwindow::return_1();
    allwindow::return_2();
    allwindow::menu_show();

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
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            if (Hint_window_1->isVisible()) {
                Hint_window_1->hide();
                Gamewindow->show();
            }
            else if (Hint_window_2->isVisible()) {
                Hint_window_2->hide();
                Gamewindow->show();
                Gamewindow->update_score(2, 16);
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
    connect(Menuwindow, &QObject::destroyed, this, [&]() {
        Gamewindow->setGraphicsEffect(nullptr);
        });
}
