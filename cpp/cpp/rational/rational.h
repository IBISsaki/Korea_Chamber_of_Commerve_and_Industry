#ifndef RATIONAL_H
#define RATIONAL_H

class Rational{
private:
    int num;
    int den;

public:
    Rational();
    Rational(int num);
    Rational(int num, int den);
    ~Rational();

    int getDen();    // 분모
    int getNum();      // 분자

    void setDen(int den);
    void setNum(int num);
};

#endif