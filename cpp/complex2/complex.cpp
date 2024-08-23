#include "complex.h"

Complex::Complex()
{
    this -> re = 0.0;
    this -> im = 0.0;
}

Complex::Complex(double re)
{
    this -> re = re;
    this -> im = 0.0;
}

Complex::Complex(double re, double im)
{
    this -> re = re;
    this -> im = im;
}

Complex::Complex(const Complex &rc)
{
    this -> re = rc.re;
    this -> im = rc.im; 
}

Complex::~Complex()
{

}

void Complex::operator = (const Complex &rc)
{
    this -> re = rc.re;
    this -> im = rc.im;
}

// int Complex::operator == (Complex c)
// {
//     return (this -> re == c.re && this -> im == c.im);
// }

// int Complex::operator == (const Complex *pc)
// {
//     return this -> re == pc -> re && this -> im == pc -> im;                                         // 포인터형
// }

bool Complex::operator == (const Complex &rc)
{
    return this -> re == rc.re && this -> im == rc.im;         // C++에서는 bool형 true or false         // 래퍼런스형
}

double Complex::real()
{
    return this -> re;
}

double Complex::imag()
{
    return this -> im;
}

void Complex::real(double re)
{
    this -> re = re;
}

void Complex::imag(double im)
{
    this -> im = im;
}