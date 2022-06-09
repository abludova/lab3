#include "rect.hpp"

std::vector<Rect> Rect::arRects;
Rect::Rect(int x, int y, int x1, int y1,int depth = 0,bool insert = false)
{
   this->x = (x < x1 ? x : x1);
   this->y = (y < y1 ? y : y1);
   height = y - y1;
   width = x - x1;
   intersectDepth = depth;
   if (height < 0)
       height = height * (-1);
   if (width < 0)
       width = width * (-1);
   if(insert)
     arRects.push_back(*this);
}
bool Rect::contains(int x, int y)
{
    return ((x <= this->x + width) && (x >= this->x) && (y <= this->y + height) && (y >= this->y));
}
int Rect::getWidth() const
{
    return width;
}
int Rect::getHeight() const
{
    return height;
}
int Rect::getX() const
{
    return x;
}
int Rect::getY() const
{
    return y;
}
Rect *Rect::intersect(Rect *rect)
{
    int arX[4] = {this->x,this->x + this->width,rect->x,rect->x + rect->width};
    int arY[4] = {this->y,this->y+this->height,rect->y,rect->y+rect->height};
    int x,y = 0;
    int i = 0;
    while(arX[i])
    {
     int j = 0;
     while(arY[j])
     {
       if(this->contains(arX[i],arY[j]) && rect->contains(arX[i],arY[j]) && (!x && !y))
       {
        x = arX[i];
        y = arY[j];
       }
       else if(this->contains(arX[i],arY[j]) && rect->contains(arX[i],arY[j]) && (x && y) && (arX[i] != x && arY[j] != y))
       {
           return new Rect(x,y,arX[i],arY[j],0,false);
       }
       j++;
     }
     i++;
    }
}
void Rect::detectMultipleIntersection(int x, int y)
{
  std::vector<Rect> rects;
  for(int i = 0; i < arRects.size(); i++){
      if(arRects[i].contains(x,y)){
          rects.push_back(arRects[i]);
      }
  }
  int i=0;
  Rect *finalRect = nullptr;
  while (i < rects.size()) {
      if(finalRect == nullptr)
      {
       finalRect = &rects[i];
       i++;
       finalRect = finalRect->intersect(&rects[i]);
       continue;
      }
       qDebug(" ------------- \n x%d x1%d y%d y1%d",finalRect->getX(),rects[i].getX(),finalRect->getX(),rects[i].getY());
       finalRect = finalRect->intersect(&rects[i]);
       i++;
  }
  if(rects.size() > 1  &&finalRect != nullptr ){
      finalRect->setIntersectDepth(rects.size());
      arRects.push_back(*finalRect);
  }
}

int Rect::getIntersectDepth() const
{
    return intersectDepth;
}

void Rect::setIntersectDepth(int value)
{
    intersectDepth = value;
}


