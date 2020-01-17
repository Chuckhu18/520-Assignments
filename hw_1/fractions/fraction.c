#include "fraction.h"

Fraction add ( Fraction a, Fraction b ) {
  int re_num = a.num * b.den + a.den * b.num;
  int re_den = a.den * b.den;

  if (re_num == 0) {
    return (Fraction) {0,1};
  }
  if (re_den == 0) {
    printf("Error! Denominator cannot be 0");
    return (Fraction) {1,0};
  }

  if (re_num > 0 && re_den < 0) {
    re_num *= -1;
    re_den *= -1;
  }

  return (Fraction) { re_num, re_den };
}

Fraction multiply ( Fraction a, Fraction b ) {
  int re_num = a.num * n.num;
  int re_den = a.den * n.den;

  if (re_num == 0) {
    return (Fraction) {0,1};
  }

  if (re_den == 0) {
    printf("Error! Denominator cannot be 0");
    return (Fraction) {1,0};
  }

  if (re_num > 0 && re_den < 0) {
    re_num *= -1;
    re_den *= -1;
  }
  return (Fraction) { re_num, re_den };
}

Fraction reduce (Fraction a) {
  if (a.num == 0) {return (Fraction) {0,1}; }
  if (a.den == 0) {
    printf("Error! Denominator cannot be 0");
    return (Fraction) {1,0};
  }

  for (int i = a.den * a.num; i > 1; i--) {  
    if ((a.den % i == 0) && (a.num % i == 0)) {
      a.den /= i;
      a.num /= i;
    }
  }
  return (Fraction) {a.num,a.den};
}