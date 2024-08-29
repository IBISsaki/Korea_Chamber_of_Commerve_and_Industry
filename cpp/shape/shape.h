#ifndef SHAPE_H
#define SHAPE_H

class Shape {   // ABC(순수 가상 함수를 가진 클래스)  Abstract Base Class         추상 기본 클래스
// private:
protected:
    int x_;
    int y_;

public:
    Shape(int x, int y);
    //Shape(const Shape& rhs);
    virtual ~Shape() { }

    // Shape& operator = (const Shape& rhs);
    // Shape *operator&();
    // const Shape *operator&() const;

    void move(int offsetX, int offsetY);
    virtual double area() const = 0;        // pure virtual function (순수 가상 함수)     구현 될 수 없음
};

#endif