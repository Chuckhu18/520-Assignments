#include "Imaginary.h"
#include <math.h>

Imaginary add ( Imaginary a, Imaginary b ) {
    return (Imaginary) { a.real + b.real, a.im + b.im };
}

Imaginary multiply ( Imaginary a, Imaginary b ) {
    return (Imaginary) {a.real*b.real - a.im*b.im, a.im*b.real + a.real*b.im};
}

Imaginary negate ( Imaginary a ){
    return (Imaginary) {-a.real, -a.im};
}

Imaginary magnitude ( Imaginary a ){
    return (Imaginary) {sqrt(a.real*a.real + a.im*a.im)};
}

Imaginary conjugate ( Imaginary a ) {
    return (Imaginary) {a.real, -a.im};
}