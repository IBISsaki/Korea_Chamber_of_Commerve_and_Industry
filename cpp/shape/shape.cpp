#include "shape.h"

Shape::Shape(int x, int y)
: x_(x), y_(y)
{

}

void Shape::move(int offsetX, int offsetY)
{
    x_ += offsetX;
    y_ += offsetY;
}

// double Shape::area() const           shape에서는 구현 할 수 없음
// {

// }  