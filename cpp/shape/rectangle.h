#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape{
private:
    int width_;   // 폭
    int height_;   // 높이

public:
    Rectangle(int x, int y, int w, int h);
    // virtual ~Rectangle() { }       // 받는 쪽은 안 써도 됨

    virtual double area() const;
    double getDiagonal() const;

};

#endif