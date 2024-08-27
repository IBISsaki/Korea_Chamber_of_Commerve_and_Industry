#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex {
friend std::ostream& operator << (std::ostream& out, const Complex& rhs);        // 전역함수 (firend함수로 만들기 위해 class 안에 넣어줌)

private:
    double re_;
    double im_;

public: 
    // Complex();                              // default construct
    // Complex(double re);                     // convert construct
    Complex(double re = 0.0, double im = 0.0);    // default argument

    // Complex() { } 생성자가 존재함으로 디폴트 생성자는 만들어 지지 않음
    // Complex(const Complex& rhs) {/* memverwise copy */}
    // ~Complex() { }
    // Complex& operator = (const Complex& rhs) {/* memberwise copy return *this; */}
    // Complex& operator&()   { return this; }
    // const Complex& operator&() const{ return this; }

    const Complex& operator += (const Complex& rhs);
    // Complex& operator -= (const Complex& rhs);
    // Complex& operator *= (const Complex& rhs);
    // Complex& operator /= (const Complex& rhs);
    // %=                       X
    // &=, |=, ^=, >>=          X

    const Complex operator + (const Complex& rhs) const;
    // const Complex operator - (const Complex& rhs) const;
    // const Complex operator * (const Complex& rhs) const;
    // const Complex operator / (const Complex& rhs) const;
    // %                        X

    const Complex& operator++();               // prefix
    const Complex operator++(int );           // postfix
    // ++, --                   X

    bool operator == (const Complex& rhs) const;
    bool operator != (const Complex& rhs) const;
    // bool operator > (const Complex& rhs) const;
    // bool operator < (const Complex& rhs) const;
    // bool operator >= (const Complex& rhs) const;
    // bool operator <= (const Complex& rhs) const;
    // &&, ||, !                X


    double real() const;
    double imag() const;

    void real(double re);
    void imag(double im);

    Complex &operator = (const Complex &rhs);
};

#endif