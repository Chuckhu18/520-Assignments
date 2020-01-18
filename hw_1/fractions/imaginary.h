#ifndef IMAGINARY_H
#define IMAGINARY_H

/*! @file */

/*! \breif Imaginary object and method definitions
 *
 *  Make a new header file called imaginary.h. Similar to the 
 * fraction.h file, define a structure with a two members, real 
 * and im which should have type double. Add function prototypes 
 * for add, negate, conjugate, multiply, and magnitude.
 */

typedef struct {
    double real;
    double im;
} Imaginary;

Imaginary add ( Imaginary a, Imaginary b );

Imaginary multiply ( Imaginary a, Imaginary b );

Imaginary negate ( Imaginary a);

Imaginary conjugate ( Imaginary a);

double magnitude ( Imaginary a);

#endif