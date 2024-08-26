#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex {
friend std::ostream& operator << (std::ostream& out, const Complex& rhs);        // 전역함수 (firend함수로 만들기 위해 class 안에 넣어줌)

private:
    double re;
    double im;

public: 
    // Complex();                              // default construct
    // Complex(double re);                     // convert construct
    Complex(double re = 0.0, double im = 0.0);    // default argument
    Complex(const Complex &rhs);
    ~Complex();

    Complex &operator = (const Complex &rhs);


    // int operator == (Complex c);             // 오버헤드 생김
    // int operator == (const Complex *pc);     // 수식이 이상함
    bool operator == (const Complex &rhs);      // 래퍼런스를 사용
    bool operator != (const Complex& rhs);

    const Complex operator + (const Complex& rhs);
    const Complex operator - (const Complex& rhs);
    // -, *, /
    // % ??? --> X
};

#endif