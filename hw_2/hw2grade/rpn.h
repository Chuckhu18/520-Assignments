#ifndef RPN_H
#define RPN_H

#include <stdlib.h>
#include "gtest/gtest.h"

typedef enum {
    OK, 
    NOT_INITIALIZED_ERROR, 
    POP_ERROR, 
    UNARY_ERROR, 
    BINARY_ERROR, 
    OVERFLOW_ERROR,
    DIVIDE_BY_ZERO_ERROR
} RPN_ERROR;

bool rpn_check_stack_exceed();
int rpn_check_stack_size();
void rpn_reallocate_double_size();
void rpn_init();
void rpn_push(double x);
void rpn_add();
void rpn_negate();
void rpn_multiply();
void rpn_div();
double rpn_pop();
RPN_ERROR rpn_error();
void rpn_free();


#endif