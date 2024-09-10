#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex {
friend std::istream& operator >> (std::istream& in, Complex& rhs);  
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

// inline 함수
inline Complex::Complex(double re, double im)
: re_(re), im_(im)                                  // 생성자 초기화 리스트 (constructor initialization list.)
{
    // re_ = re;
    // im_ = im;
}

inline double Complex::real() const
{
    return re_;
}
inline double Complex::imag() const
{
    return im_;
}

inline void Complex::real(double re)
{
    re_ = re;
}
inline void Complex::imag(double im)
{
    im_ = im;
}

#endif