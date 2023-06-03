#ifndef ALLWINDOW_H
#define ALLWINDOW_H

#include <QWidget>

class allwindow : public QWidget
{
    Q_OBJECT
public:
    explicit allwindow(QWidget* parent = nullptr);
    ~allwindow();
    void start_1();
    void start_2();
    void return_1();
    void return_2();
    void menu_show();
    void close_window();

signals:
protected:
    //void keyPressEvent(QKeyEvent *event);
    bool eventFilter(QObject* obj, QEvent* event) override;

};

#endif // ALLWINDOW_H
