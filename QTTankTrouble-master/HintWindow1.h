#ifndef HINTWINDOW_1_H
#define HINTWINDOW_1_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>

class hintwindow_1 : public QWidget
{
    Q_OBJECT
public:
    explicit hintwindow_1(QWidget* parent = nullptr);
    QPushButton* button_volume;
    QPushButton* button_return;

signals:
private:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void drawKeyPressedImage(const QString& imagePath, int x, int y, int width, int height);
};

#endif // HINTWINDOW_1_H
