#ifndef COMPLEX
#define COMPLEX

#include <iostream>

class Complex {
    public:
    Complex(double x, double y) : re(x), im(y) {}
    Complex(double a) : re(a), im(0) {};
    double real();
    double imaginary();
    Complex conjugate();

    Complex operator + (Complex const &obj);

    Complex operator * (Complex const &obj);

    // bool operator==(const Complex& a, const Complex& b);

    double magnitude() const;

    private:
    double re, im;
}; 

bool operator==( Complex& a,  Complex& b);
bool operator<(const Complex& a, const Complex& b);

#endif