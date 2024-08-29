#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle : public Shape{
private:
    int radius_; // 반지름

public:
    Circle(int x, int y, int r);
    // virtual ~Circle() { }       // 받는 쪽은 안 써도 됨

    virtual double area() const;      // 넓이
    double getCircumference() const;      // 원주
};


#endif