#include "fraction.h"
#include "imaginary.h"
#include "gtest/gtest.h"

namespace {
    //=======Tests for Fractions==============
    TEST(Fractions, Basics) {
        Fraction a = (Fraction) { 2, 3 },
                 b = (Fraction) { 4, 5 };
        EXPECT_EQ(add(a,b).num,22);
        EXPECT_EQ(add(a,b).den,15);
        EXPECT_EQ(multiply(a,b).num,8);
        EXPECT_EQ(multiply(a,b).den,15);
    }

    TEST(Fractions, NumZeros) {
        Fraction a = (Fraction) { 0, 3 },
                 b = (Fraction) { 1, 2 };
        EXPECT_EQ(add(a,b).num, 3);
        EXPECT_EQ(add(a,b).den, 6);
        EXPECT_EQ(multiply(a,b).num, 0);
        EXPECT_EQ(multiply(a,b).den, 1);
    }
    TEST(Fractions, DenZeros) {
        Fraction a = (Fraction) { 3, 0 },
                 b = (Fraction) { 3, 4 };
        EXPECT_EQ(add(a,b).num, 1);
        EXPECT_EQ(add(a,b).den, 0);
        EXPECT_EQ(multiply(a,b).num, 1);
        EXPECT_EQ(multiply(a,b).den, 0);
    }

    TEST(Fractions, ReduceBasics) {
        Fraction a = (Fraction) {21, 33};
        EXPECT_EQ(reduce(a).num,7);
        EXPECT_EQ(reduce(a).den,11);

        Fraction b = (Fraction) {3, 9};
        EXPECT_EQ(reduce(b).num,1);
        EXPECT_EQ(reduce(b).den,3);

        Fraction c = (Fraction) {1, 1};
        EXPECT_EQ(reduce(c).num,1);
        EXPECT_EQ(reduce(c).den,1);

        Fraction d = (Fraction) {0, 3};
        EXPECT_EQ(reduce(d).num,0);
        EXPECT_EQ(reduce(d).den,1);

        Fraction e = (Fraction) {5, 0};
        EXPECT_EQ(reduce(e).num,1);
        EXPECT_EQ(reduce(e).den,0);
    }
    //=======Tests for Complex==============
    TEST(Complex, Basics) {
        Imaginary a = (Imaginary) { 2, 3},
                 b = (Imaginary) { 4, 5};
        EXPECT_EQ(add(a,b).real,6);
        EXPECT_EQ(add(a,b).im,8);
        EXPECT_EQ(multiply(a,b).real,-7);
        EXPECT_EQ(multiply(a,b).im,22);
    }

    TEST(Complex, Zeros) {
        Imaginary a = (Imaginary) { 2, 3},
                 b = (Imaginary) { 4, 0};
        EXPECT_EQ(add(a,b).real,6);
        EXPECT_EQ(add(a,b).im,3);
        EXPECT_EQ(multiply(a,b).real,8);
        EXPECT_EQ(multiply(a,b).im,12);
    }

    TEST(Complex, Negate) {
        Imaginary a = (Imaginary) { 2.32, 3.14};
        EXPECT_EQ(negate(a).real, -2.32);
        EXPECT_EQ(negate(a).im, -3.14);
    }

    TEST(Complex, Magnitude) {
        Imaginary a = (Imaginary) { 3, 4};
        EXPECT_EQ(magnitude(a), 5);
    }

    TEST(Complex, Conjugate) {
        Imaginary a = (Imaginary) { -5.35, 10000323};
        EXPECT_EQ(negate(a).real, 5.35);
        EXPECT_EQ(negate(a).im, -10000323);
    }
}
