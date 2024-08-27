#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational{
friend std::ostream& operator << (std::ostream& out, const Rational& rhs);

private:
    int num;
    int den;

public:
    Rational(int num = 0, int den = 1);                     // 생성자       
    Rational(const Rational &rhs); // right - hand - side   // 복사 생성자
    ~Rational();                                            // 소멸자

    Rational& operator = (const Rational &rhs);

    bool operator == (const Rational &rhs);             // 복사 생성자가 호출되어 오버헤드가 발생한다 (이를 줄이기 위해 포인터나 레퍼런스를 사용한다.)
    bool operator != (const Rational &rhs);

    const Rational operator + (const Rational &rhs);
    const Rational operator - (const Rational &rhs);
    const Rational operator * (const Rational &rhs);
    const Rational operator / (const Rational &rhs);
};

#endif