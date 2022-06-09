#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QMouseEvent>
#include <QPaintEvent>
#include "rect.hpp"
#include <QPainter>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<Rect*> arRect;
    int initialX = 0;
    int initialY = 0;
    int intersectX = 0;
    int intersectY = 0;
    static  std::vector<QColor> arColors; //поле для класса

};
#endif // MAINWINDOW_H
