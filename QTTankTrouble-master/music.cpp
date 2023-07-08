#include "music.h"
#include <QMediaPlayer>
#include <QSlider>
#include <QAudioOutput>
#include <QAudio>
#include <QVBoxLayout>
#include <QUrl>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>
#include <qlabel.h>
#include <qtimer.h>

int music::clickcount = 0;

music::music(QWidget* parent)
	: QWidget{ parent }
{
	setFixedSize(400, 200);
	volumeslider = new QSlider(Qt::Horizontal, this);
	musicplayer1 = new QMediaPlayer;
	QUrl resourceUrl(":/TankTrouble/res/muic1.mp3");
	musicplayer1->setSource(QUrl::fromLocalFile("res\\muic1.mp3"));
	connect(musicplayer1, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
		if (status == QMediaPlayer::EndOfMedia) {
			musicplayer1->setPosition(0);  // 将音频播放位置设置为起始位置
			musicplayer1->play();  // 重新开始播放音频
		}
		});


	volumeslider->setRange(0, 100);
	volumeslider->setValue(50);
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(volumeslider, 0, Qt::AlignCenter);
	volumeslider->setFixedWidth(200);
	QAudioOutput* audioOutput = new QAudioOutput;

	QString styleSheet = "QSlider::groove:horizontal {"
		"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));"
		"    height: 10px;"
		"    border-radius: 4px;"
		"}"
		"QSlider::handle:horizontal {"
		"    background-color: #FFFFFF;"
		"    border: 1px solid #777;"
		"    width: 16px;"
		"    margin: -8px 0;"
		"    border-radius: 8px;"
		"}";

	volumeslider->setStyleSheet(styleSheet);
	connect(volumeslider, &QSlider::valueChanged, this, [audioOutput](int value) {
		qreal volume = qreal(value) / 100.0;
		audioOutput->setVolume(volume);
		});
	musicplayer1->setAudioOutput(audioOutput);
	label_red = new QLabel(this);
	label_red->setFixedSize(60, 60);
	label_red->setPixmap(QPixmap(":/TankTrouble/res/red_smalltank.png"));
	label_red->setScaledContents(true);
	label_blue = new QLabel(this);
	label_blue->setPixmap(QPixmap(":/TankTrouble/res/blue_smalltank.png"));
	label_blue->move(10, 5);
	label_blue->setFixedSize(60, 60);
	label_blue->setScaledContents(true);
	label_red->move(320, 140);

	QIcon icon(":/TankTrouble/res/button_silence.png");
	button_silence = new QPushButton(this);
	button_silence->setFixedSize(40, 40);
	button_silence->setIcon(icon);
	button_silence->setIconSize(QSize(40, 40));
	button_silence->setFlat(1);
	button_silence->move(320, 80);

	connect(button_silence, &QPushButton::clicked, this, [&]() {
		music::clickcount++;
		if (clickcount % 2 == 1) {
			musicplayer1->stop();
		}
		else {
			musicplayer1->play();
		}
		});
}
