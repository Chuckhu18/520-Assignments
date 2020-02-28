#include <math.h>
#include "complex.h"
#include "typed_array.h"


double Complex::real(){
    return re;
}

double Complex::imaginary(){
    return im;
}

Complex Complex::conjugate(){
    Complex p(re, -im);
    return p;
}

Complex Complex::operator + (Complex const &obj) { 
    Complex res(re + obj.re, im + obj.im);
    return res; 
} 

Complex Complex::operator * (Complex const &obj) { 
    Complex res(re*obj.re - obj.im*im, re*obj.im + obj.re*im);
    return res; 
} 

bool operator==(Complex& a,  Complex& b){
    if(a.real() != b.real() || a.imaginary() != b.imaginary())
        return false;
    return true;
}

double Complex::magnitude() const {
    return sqrt(re*re + im*im);
}

bool operator<(const Complex& a, const Complex& b) {
    return a.magnitude() < b.magnitude();
}