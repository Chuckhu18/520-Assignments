#include "imaginary.h"

Imaginary add ( Imaginary a, Imaginary b ) {
    return (Imaginary) { a.real + b.real, a.im + b.im };
}

Imaginary multiply ( Imaginary a, Imaginary b ) {
    return (Imaginary ) {a.real*b.real - a.img*b.img, c.img = a.img*b.real + a.real*b.img;}
}

Imaginary negate ( Imaginary a, Imaginary b );

Imaginary conjugate ( Imaginary a, Imaginary b );

Imaginary magnitude ( Imaginary a, Imaginary b );