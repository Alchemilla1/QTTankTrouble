#ifndef HINTWINDOW_2_H
#define HINTWINDOW_2_H

#include <QWidget>
#include <QPushButton>

class hintwindow_2 : public QWidget
{
    Q_OBJECT
public:
    explicit hintwindow_2(QWidget* parent = nullptr);
    QPushButton* button_volume;
    QPushButton* button_return;

signals:
private:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void drawKeyPressedImage(const QString& imagePath, int x, int y, int width, int height);

};

#endif // HINTWINDOW_2_H
