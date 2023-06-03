#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#include <QWidget>
#include <QPushButton>

class menu_window : public QWidget
{
    Q_OBJECT
public:
    explicit menu_window(QWidget* parent = nullptr);
    QPushButton* return_game;
    QPushButton* game_over;

signals:
private:
    void paintEvent(QPaintEvent* event) override;

};

#endif // MENU_WINDOW_H
