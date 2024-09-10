#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <stdexcept> // std::invalid_argument 예외 처리를 위해
#include <cmath>     // std::abs 및 std::gcd를 사용하기 위해

class Rational {
private:
    long num; // 분자
    long den; // 분모 (항상 > 0이어야 함)

    // 최대 공약수(GCD) 계산을 위한 도움 함수
    long gcd(long u, long v) const;

public:
    // 기본 생성자: 0/1로 초기화
    Rational() : num(0), den(1) {}

    // 매개변수화된 생성자: 주어진 분자와 분모로 초기화
    Rational(long n, long d = 1);

    // long 타입 할당 연산자
    Rational& operator=(long rhs);

    // 분자와 분모 접근 함수
    long numerator(void) const { return num; }
    long denominator(void) const { return den; }

    // 단항 연산자
    Rational operator+(void) const { return *this; }
    Rational operator-(void) const { return Rational(-num, den); }
    Rational invert(void) const { return Rational(den, num); }

    // 복합 할당 연산자
    const Rational& operator+=(const Rational& rhs);
    const Rational& operator-=(const Rational& rhs);
    const Rational& operator*=(const Rational& rhs);
    const Rational& operator/=(const Rational& rhs);

    const Rational& operator+=(long rhs);
    const Rational& operator-=(long rhs);
    const Rational& operator*=(long rhs);
    const Rational& operator/=(long rhs);

    const Rational& operator++(); // 전위 증가
    Rational operator++(int); // 후위 증가
    const Rational& operator--(); // 전위 감소
    Rational operator--(int); // 후위 감소

    // 친구 연산자
    friend const Rational operator+(const Rational& l, const Rational& r);
    friend const Rational operator-(const Rational& l, const Rational& r);
    friend const Rational operator*(const Rational& l, const Rational& r);
    friend const Rational operator/(const Rational& l, const Rational& r);

    friend bool operator==(const Rational& lhs, const Rational& rhs);
    friend bool operator!=(const Rational& lhs, const Rational& rhs);
    friend bool operator<=(const Rational& lhs, const Rational& rhs);
    friend bool operator>=(const Rational& lhs, const Rational& rhs);
    friend bool operator<(const Rational& lhs, const Rational& rhs);
    friend bool operator>(const Rational& lhs, const Rational& rhs);

    friend std::ostream& operator<<(std::ostream& s, const Rational& r);
    friend Rational rabs(const Rational& rhs);
};

// 인라인 및 변환 함수
inline double toDouble(const Rational& r) {
    return double(r.numerator()) / r.denominator();
}

inline long trunc(const Rational& r) {
    return r.numerator() / r.denominator();
}

inline long floor(const Rational& r) {
    long q = r.numerator() / r.denominator();
    return (r.numerator() < 0 && r.denominator() != 1) ? --q : q;
}

inline long ceil(const Rational& r) {
    long q = r.numerator() / r.denominator();
    return (r.numerator() >= 0 && r.denominator() != 1) ? ++q : q;
}

Rational toRational(double x, int iterations = 5);

#endif // RATIONAL_H
