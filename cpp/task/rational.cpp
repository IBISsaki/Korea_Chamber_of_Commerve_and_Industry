#include "rational.h"
#include <iostream>
#include <stdexcept> // std::invalid_argument 예외 처리를 위해
#include <cmath>     // std::abs를 사용하기 위해

long Rational::gcd(long u, long v) const {
    while (v != 0) {
        long tmp = v;
        v = u % v;
        u = tmp;
    }
    return std::abs(u);
}

Rational::Rational(long n, long d) {
    if (d == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if (d < 0) {
        n = -n; d = -d;
    }
    if (n == 0) {
        num = 0; den = 1;
    } else {
        long g = gcd(n, d);
        num = n / g; den = d / g;
    }
}

Rational& Rational::operator=(long rhs) {
    num = rhs; den = 1;
    return *this;
}

const Rational& Rational::operator+=(const Rational& rhs) {
    long newDen = den * rhs.den;
    long newNum = num * rhs.den + den * rhs.num;
    long g = gcd(newNum, newDen);
    num = newNum / g;
    den = newDen / g;
    return *this;
}

const Rational& Rational::operator-=(const Rational& rhs) {
    long newDen = den * rhs.den;
    long newNum = num * rhs.den - den * rhs.num;
    long g = gcd(newNum, newDen);
    num = newNum / g;
    den = newDen / g;
    return *this;
}

const Rational& Rational::operator*=(const Rational& rhs) {
    long newNum = num * rhs.num;
    long newDen = den * rhs.den;
    long g = gcd(newNum, newDen);
    num = newNum / g;
    den = newDen / g;
    return *this;
}

const Rational& Rational::operator/=(const Rational& rhs) {
    if (rhs.num == 0) {
        throw std::invalid_argument("Division by zero");
    }
    long newNum = num * rhs.den;
    long newDen = den * rhs.num;
    long g = gcd(newNum, newDen);
    num = newNum / g;
    den = newDen / g;
    return *this;
}

const Rational& Rational::operator+=(long rhs) {
    return *this += Rational(rhs);
}

const Rational& Rational::operator-=(long rhs) {
    return *this -= Rational(rhs);
}

const Rational& Rational::operator*=(long rhs) {
    return *this *= Rational(rhs);
}

const Rational& Rational::operator/=(long rhs) {
    return *this /= Rational(rhs);
}

const Rational& Rational::operator++() {
    return *this += 1;
}

Rational Rational::operator++(int) {
    Rational old = *this;
    ++(*this);
    return old;
}

const Rational& Rational::operator--() {
    return *this -= 1;
}

Rational Rational::operator--(int) {
    Rational old = *this;
    --(*this);
    return old;
}

const Rational operator+(const Rational& l, const Rational& r) {
    Rational result = l;
    result += r;
    return result;
}

const Rational operator-(const Rational& l, const Rational& r) {
    Rational result = l;
    result -= r;
    return result;
}

const Rational operator*(const Rational& l, const Rational& r) {
    Rational result = l;
    result *= r;
    return result;
}

const Rational operator/(const Rational& l, const Rational& r) {
    Rational result = l;
    result /= r;
    return result;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.numerator() == rhs.numerator() && lhs.denominator() == rhs.denominator();
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    return toDouble(lhs) < toDouble(rhs);
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
    return !(rhs < lhs);
}

bool operator>(const Rational& lhs, const Rational& rhs) {
    return rhs < lhs;
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& s, const Rational& r) {
    if (r.denominator() == 1)
        s << r.numerator();
    else
        s << r.numerator() << '/' << r.denominator();
    return s;
}

Rational rabs(const Rational& r) {
    return (r.numerator() < 0) ? Rational(-r.numerator(), r.denominator()) : r;
}
