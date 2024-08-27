#include <cassert>
#include "rational.h"

std::ostream& operator << (std::ostream& out, const Rational& rhs)
{
    out << "( " << rhs.num << "/" << rhs.den << " )";

    return out;
}

Rational::Rational(int num, int den)
{
    assert(den );
    // reduce(약분)


    this -> num = num;
    this -> den = den;
}

Rational::Rational(const Rational &rhs)
{
    this -> num = rhs.num;
    this -> den = rhs.den;
}

Rational::~Rational()
{

}

Rational& Rational::operator = (const Rational &rhs)
{
    this -> num = rhs.num;
    this -> den = rhs.den;

    return *this;
}

bool Rational::operator == (const Rational &rhs)
{
    return(this -> num == rhs.num && this -> den == rhs.den);
}

bool Rational::operator != (const Rational &rhs)
{
    return !this -> operator == (rhs);
}

const Rational Rational::operator + (const Rational &rhs)
{
    Rational result(this -> num * rhs.den + rhs.num * this -> den, this -> den * rhs.den);
    
    return result;
}

const Rational Rational::operator - (const Rational &rhs)
{
    Rational result(this -> num * rhs.den - rhs.num * this -> den, this -> den * rhs.den);
    
    return result;
}

const Rational Rational::operator * (const Rational &rhs)
{
    Rational result(this -> num * rhs.num, this -> den * rhs.den);
    
    return result;
}

const Rational Rational::operator / (const Rational &rhs)
{
    Rational result(this -> num * rhs.den, this -> den * rhs.num);
    
    return result;
}