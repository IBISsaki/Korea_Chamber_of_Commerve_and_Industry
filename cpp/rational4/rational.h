#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include "gcd.h"

class Rational{
friend std::istream& operator >> (std::istream& in, Rational& rhs);
friend std::ostream& operator << (std::ostream& out, const Rational& rhs);

private:
    int num_;
    int den_;

    void reduce();                                          // helper func. tool func.

public:
    // Rational();
    // Rational(int num);
    Rational(int num = 0, int den = 1);                     // 생성자       

    // Rational() { } 생성자가 존재함으로 디폴트 생성자는 만들어 지지 않음
    // Rational(const Rational& rhs) {/* memverwise copy */}
    // ~Rational() { }
    // Rational& operator = (const Rational& rhs) {/* memberwise copy */ return *this; }
    // Rational* operator&()   { return this; }
    // const Rational* operator&() const{ return this; }

    const Rational& operator += (const Rational& rhs);
    // Rational& operator -= (const Rational& rhs);
    // Rational& operator *= (const Rational& rhs);
    // Rational& operator /= (const Rational& rhs);

    const Rational operator + (const Rational &rhs) const;
    // const Rational operator - (const Rational &rhs);
    // const Rational operator * (const Rational &rhs);
    // const Rational operator / (const Rational &rhs);

    const Rational& operator++();
    const Rational operator++(int );

    bool operator == (const Rational &rhs) const;             // 복사 생성자가 호출되어 오버헤드가 발생한다 (이를 줄이기 위해 포인터나 레퍼런스를 사용한다.)
    bool operator != (const Rational &rhs) const;
    // >, <, >=, <=

    int getNum() const;
    int getDen() const;

    void setNum(int num);
    void setDen(int den);

    Rational& operator = (const Rational &rhs);
};

#endif