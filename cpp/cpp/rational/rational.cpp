#include <cassert>
#include "rational.h"

Rational::Rational()
{
    this -> num = 0;
    this -> den = 1;
}

Rational::Rational(int num)
{
    this -> num = num;          // 분자
    this -> den = 1;          // 분모
}

Rational::Rational(int num, int den)
{
    assert(den != 0);

    this -> num = num;
    this -> den = den;
}

Rational::~Rational()
{

}

int Rational::getDen()    // 분모
{
    return this -> den;
}

int Rational::getNum()      // 분자
{
    return this -> num;
}

void Rational::setDen(int den)
{
    assert(den != 0);
    
    this -> den = den;
}

void Rational::setNum(int num)
{
    this -> num = num;
}