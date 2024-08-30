#include <cassert>
#include "rational.h"
#include "gcd.h"

std::istream& operator >> (std::istream& in, Rational& rhs)
{
    int num, den;
    in >> num;

    if(in.peek() == '/') {
        in.ignore();
        in >> den;
    }

    if(in) {
        rhs = Rational(num, den);
    }

    return in;
}

std::ostream& operator << (std::ostream& out, const Rational& rhs)
{
    return out << rhs.num_ << "/" << rhs.den_;
    // out << "( " << rhs.num_ << "/" << rhs.den_ << " )";
    // return out;
}

void Rational::reduce()
{
    int g = gcd(num_, den_);
    num_ = num_ / g;
    den_ = den_ / g;
}

Rational::Rational(int num, int den)
:num_(num), den_(den)
{
    assert(den );
    this -> reduce();

    // num_ = num;
    // den_ = den;
}

const Rational& Rational::operator += (const Rational &rhs)
{
    // num_ += rhs.num_;
    // den_ += rhs.den_;
    // return *this;
    *this = *this + rhs;
    return *this;
}

const Rational& Rational::operator++()
{
    num_ = num_ + den_;
    return *this;
}

const Rational Rational::operator++(int )
{
    Rational temp = *this;
    num_ = num_ + den_;
    return temp;
}

bool Rational::operator == (const Rational &rhs) const
{
    return(num_ == rhs.num_ && den_ == rhs.den_);
}

bool Rational::operator != (const Rational &rhs) const
{
    return !this -> operator == (rhs);
}

const Rational Rational::operator + (const Rational &rhs) const
{
    Rational result(num_ * rhs.den_ + rhs.num_ * den_, den_ * rhs.den_);
    
    return result;
}

int Rational::getNum() const
{
    return num_;
}

int Rational::getDen() const
{
    return den_;
}

void Rational::setNum(int num)
{
    num_ = num;
}

void Rational::setDen(int den)
{
    assert(den );
    den_ = den;
}

Rational& Rational::operator = (const Rational &rhs)
{
    num_ = rhs.num_;
    den_ = rhs.den_;

    return *this;
}