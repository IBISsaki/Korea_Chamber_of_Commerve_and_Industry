#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
    // implementation
    double re;                                  //real part         실수부
    double im;                                  // imaginary part   허수부

public:
    //interface
    Complex();                                  // 함수 중복(function overloading)
    Complex(double re);                         // 인자의 타입, 개수가 달라야 함
    Complex(double re, double im);              // --> 'one-interface multi-method
    ~Complex();

    double real();
    double imag();

    void real(double re);
    void imag(double im);

    // 
};

#endif