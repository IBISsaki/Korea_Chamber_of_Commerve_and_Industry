#include "complex.h"

std::ostream& operator << (std::ostream& out, const Complex& rhs)
{
    out << "(" << rhs.re << ", " << rhs.im << "i)";

    return out;
}

// Complex::Complex()
// {
//     this -> re = 0.0;
//     this -> im = 0.0;
// }

// Complex::Complex(double re)
// {
//     this -> re = re;
//     this -> im = 0.0;
// }

Complex::Complex(double re, double im)
{
    this -> re = re;
    this -> im = im;
}

Complex::Complex(const Complex &rhs)
{
    this -> re = rhs.re;
    this -> im = rhs.im; 
}

Complex::~Complex()
{

}

Complex &Complex::operator = (const Complex &rhs)
{
    this -> re = rhs.re;
    this -> im = rhs.im;

    return *this;
}

bool Complex::operator == (const Complex &rhs)
{
    return this -> re == rhs.re && this -> im == rhs.im;         // C++에서는 bool형 true or false         // 래퍼런스형
}

bool Complex::operator != (const Complex& rhs)
{
    return !this -> operator == (rhs);
    // return !(*this == rhs);
    // return this -> re != rhs.re || this -> im != rhs.im;
}

const Complex Complex::operator + (const Complex& rhs)
{
    Complex result(this -> re + rhs.re, this -> im + rhs.im);
    
    return result;
}

const Complex Complex::operator - (const Complex& rhs)
{
    Complex result(this -> re - rhs.re, this -> im - rhs.im);
    
    return result;
}