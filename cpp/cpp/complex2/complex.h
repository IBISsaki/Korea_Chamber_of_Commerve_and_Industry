#ifndef COMPLEX_H
#define COMPLEX_H

struct Complex
{
private:
    double re;
    double im;

public: 
    Complex();                          // default construct
    Complex(double re);                 // convert construct
    Complex(double re, double im);
    Complex(const Complex &rc);
    ~Complex();

    void operator = (const Complex &rc);


    // int operator == (Complex c);
    // int operator == (const Complex *pc);
    bool operator == (const Complex &rc);

    double real();
    double imag();

    void real(double re);
    void imag(double im);
};

#endif