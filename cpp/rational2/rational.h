#ifndef RATIONAL_H
#define RATIONAL_H

class Rational{
private:
    int num;
    int den;

public:
    Rational();                                             // 디폴트 생성자
    Rational(int num);                                      // 변화 생성자
    Rational(int num, int den);                             // 생성자       
    Rational(const Rational &rhs); // right - hand - side   // 복사 생성자
    ~Rational();                                            // 소멸자

    void operator = (const Rational &rhs);

    // bool operator == (Rational r);                  // 성능상의 문제가 있음
    // bool operator == (const Rational *pr);          // (r1 == &r3)    포인터를 사용하면 식의 모양이 보기 이상해짐
    bool operator == (const Rational &rhs);             // 복사 생성자가 호출되어 오버헤드가 발생한다 (이를 줄이기 위해 포인터나 레퍼런스를 사용한다.)

    int getDen();    // 분모
    int getNum();      // 분자

    void setDen(int den);
    void setNum(int num);
};

#endif