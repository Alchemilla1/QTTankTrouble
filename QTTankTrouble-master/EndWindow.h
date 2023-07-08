#pragma once

#include <QWidget>
#include <QPushButton>

class end_window : public QWidget
{
    Q_OBJECT
public:
    explicit end_window(int _mode = 0, int blue_score = 0, int red_score = 0, QWidget* parent = nullptr);
    int red_score, blue_score;
    int mode;//1为人机，2为双人
    void draw_end(QPainter& painter);
    QPushButton* exit;

signals:
private:
    void paintEvent(QPaintEvent* event);
};