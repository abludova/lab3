#ifndef RECT_HPP
#define RECT_HPP
#include <vector>
#include <QDebug>

class Rect
{
public:
    Rect();
    Rect(int x, int y, int x1, int y1,int depth,bool insert);
    bool contains(int x, int y);
    int getWidth() const;

    int getHeight() const;

    int getX() const;

    int getY() const;
    Rect *intersect(Rect* rect);
    static void detectMultipleIntersection(int x ,int y);
    static std::vector<Rect> arRects;

    int getIntersectDepth() const;
    void setIntersectDepth(int value);

private:

    int width;
    int height;
    int x;
    int y;
    int intersectDepth;

};

#endif // RECT_HPP
