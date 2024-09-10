#include "complex.h"

std::istream& operator >> (std::istream& in, Complex& rhs)
{
    double re = 0.0, im = 0.0;
    char c = 0;
    in >> c;
    if(c == '(') {
        in >> re >> c;
        if(c == ',') {
            in >> im >> c;
        }
        if(c == 'i') {
            in >> c;
        }
        if(c != ')') {
            in.clear(std::ios::failbit);
        }
    } else {
        in.putback(c);
        in >> re;
    }

    if(in) {
        rhs = Complex(re, im);
    }

    return in;
}
std::ostream& operator << (std::ostream& out, const Complex& rhs)
{
    return out << "(" << rhs.re_ << ", " << rhs.im_ << "i)";
    // out << "(" << rhs.re_ << ", " << rhs.im_ << "i)";
    // return out;
}

const Complex& Complex::operator += (const Complex& rhs)
{
    re_ += rhs.re_;
    im_ += rhs.im_;
    return *this;
}

bool Complex::operator == (const Complex& rhs) const
{
    return re_ == rhs.re_ && im_ == rhs.im_;         // C++에서는 bool형 true or false         // 래퍼런스형
}

bool Complex::operator != (const Complex& rhs) const
{
    return !this -> operator == (rhs);
}

const Complex Complex::operator + (const Complex& rhs) const
{
    Complex result(re_ + rhs.re_, im_ + rhs.im_);
    
    return result;
}

const Complex& Complex::operator++()
{
    re_ = re_ + 1;
    return *this;
}

const Complex Complex::operator++(int )
{
    Complex tmp = *this;
    re_ = re_ + 1;
    return tmp;
}

Complex &Complex::operator = (const Complex &rhs)
{
    re_ = rhs.re_;
    im_ = rhs.im_;

    return *this;
}