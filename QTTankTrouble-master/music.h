#ifndef MUSIC_H
#define MUSIC_H

#include <QWidget>
#include <QMediaPlayer>
#include <QSlider>
#include <QLabel>
#include <QPushButton>

class music : public QWidget
{
    Q_OBJECT
public:
    explicit music(QWidget* parent = nullptr);
    QMediaPlayer* musicplayer1;
    QSlider* volumeslider;

    QLabel* label_red;
    QLabel* label_blue;
    QPushButton* button_silence;
    static int clickcount;

signals:

};

#endif // MUSIC_H
