#include "mainwindow.h"
#include "ui_mainwindow.h"

std::vector<QColor> MainWindow::arColors = {Qt::red,Qt::blue,Qt::yellow,Qt::green,Qt::black};

void MainWindow::mousePressEvent(QMouseEvent *event)
{
   if(event->modifiers() & Qt::AltModifier)
   {

      if(initialX == 0 && initialY == 0){
          initialX = event->x();
          initialY = event->y();
      }
      else{

          Rect *rect = new Rect(initialX,initialY,event->x(),event->y(),0,true);
          initialX = 0;
          initialY = 0;
          delete rect;
      }
   }
   else
   {
      Rect::detectMultipleIntersection(event->x(),event->y());
   };
   repaint();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(Rect::arRects.size() > 0)
    {
     for(int i = 0; i < Rect::arRects.size(); i++)
     {
         Rect *rect = &Rect::arRects.at(i);
         painter.drawRect(rect->getX(),rect->getY(),rect->getWidth(),rect->getHeight());
         if(rect->getIntersectDepth() > 0){
             QBrush brush;
             painter.fillRect(rect->getX(),rect->getY(),rect->getWidth(),rect->getHeight(),arColors[rect->getIntersectDepth() - 2]);
         }
     }     
   }

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

