#include "rational.h"
#include <iostream>

int main() {
    // 1. 기본 생성자를 사용하여 Rational 객체 생성 (0/1)
    Rational r1;
    std::cout << "r1: " << r1 << " (Expected: 0)" << std::endl;

    // 2. 매개변수화된 생성자를 사용하여 Rational 객체 생성 (3/4)
    Rational r2(3, 4);
    std::cout << "r2: " << r2 << " (Expected: 3/4)" << std::endl;

    // 3. 정수로부터 Rational 객체 생성 (5/1)
    Rational r3(5);
    std::cout << "r3: " << r3 << " (Expected: 5)" << std::endl;

    // 4. 덧셈 연산자 사용
    Rational r4 = r2 + r3;  // (3/4) + (5/1) = (23/4)
    std::cout << "r4 (r2 + r3): " << r4 << " (Expected: 23/4)" << std::endl;

    // 5. 뺄셈 연산자 사용
    Rational r5 = r3 - r2;  // (5/1) - (3/4) = (17/4)
    std::cout << "r5 (r3 - r2): " << r5 << " (Expected: 17/4)" << std::endl;

    // 6. 곱셈 연산자 사용
    Rational r6 = r2 * r3;  // (3/4) * (5/1) = (15/4)
    std::cout << "r6 (r2 * r3): " << r6 << " (Expected: 15/4)" << std::endl;

    // 7. 나눗셈 연산자 사용
    Rational r7 = r3 / r2;  // (5/1) / (3/4) = (20/3)
    std::cout << "r7 (r3 / r2): " << r7 << " (Expected: 20/3)" << std::endl;

    // 8. 증감 연산자 (후위 증가)
    Rational r8 = r2++;
    std::cout << "r8 (r2++): " << r8 << " (Expected: 3/4)" << std::endl;
    std::cout << "r2 after r2++: " << r2 << " (Expected: 7/4)" << std::endl;

    // 9. 증감 연산자 (전위 증가)
    Rational r9 = ++r3;
    std::cout << "r9 (++r3): " << r9 << " (Expected: 6)" << std::endl;
    std::cout << "r3 after ++r3: " << r3 << " (Expected: 6)" << std::endl;

    // 10. 동등 비교 연산자 사용
    bool equal = (r2 == Rational(7, 4));
    std::cout << "r2 == 7/4: " << (equal ? "true" : "false") << " (Expected: true)" << std::endl;

    // 11. 부등 비교 연산자 사용
    bool notEqual = (r2 != r3);
    std::cout << "r2 != r3: " << (notEqual ? "true" : "false") << " (Expected: true)" << std::endl;

    return 0;
}

// r1: 0 (Expected: 0)
// r2: 3/4 (Expected: 3/4)
// r3: 5 (Expected: 5)
// r4 (r2 + r3): 23/4 (Expected: 23/4)
// r5 (r3 - r2): 17/4 (Expected: 17/4)
// r6 (r2 * r3): 15/4 (Expected: 15/4)
// r7 (r3 / r2): 20/3 (Expected: 20/3)
// r8 (r2++): 3/4 (Expected: 3/4)
// r2 after r2++: 7/4 (Expected: 7/4)
// r9 (++r3): 6 (Expected: 6)
// r3 after ++r3: 6 (Expected: 6)
// r2 == 7/4: true (Expected: true)
// r2 != r3: true (Expected: true)
