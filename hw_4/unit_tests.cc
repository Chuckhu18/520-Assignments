#include <math.h>
#include <float.h> /* defines DBL_EPSILON */
#include <assert.h>
#include "complex.h"
#include "typed_array.h"
#include "gtest/gtest.h"


namespace {

    TEST(Examples,Complex) {
        Complex x(1,2), y(3);
    }

    template<typename T>
    int compare(const T& x, const T& y) {
        if ( x < y ) {
            return -1;
        } else if ( y < x ) {
            return 1;
        } else {
            return 0;
        }
    }    

    TEST(Examples,Templates) {
        EXPECT_EQ(compare(1.0, 2.0), -1);
        EXPECT_EQ(compare(Complex(5,4), Complex(-3,4)), 1);
    }

    TEST(Array,Push) {
        TypedArray <int> new_arr;
        new_arr.push(1);
        new_arr.push(2);
        new_arr.push(3);
        for(int i=0; i<new_arr.size(); i++)
            std::cout<< "[" << new_arr.get(i) << "] ";
        std::cout<<std::endl;
    }

    TEST(Array,Pop) {
        TypedArray <char> new_arr;
        new_arr.push('p');
        new_arr.push('u');
        new_arr.push('s');
        new_arr.push('h');//'push'
        for(int i=0; i<3; i++)//'p'
            new_arr.pop();
        new_arr.push('o');
        new_arr.push('p');//'pop'
        for(int i=0; i<new_arr.size(); i++)
            std::cout<< "[" << new_arr.get(i) << "] ";
        std::cout<<std::endl;

        // for(int i=0; i<4; i++)//when poping an empty array
        //     new_arr.pop();
    }

    TEST(Array, PushPop_front) {
        TypedArray <char> new_arr;
        new_arr.push('o');
        new_arr.push('p');
        new_arr.push_front('p');

        for(int i=0; i<new_arr.size(); i++)
            std::cout<< "[" << new_arr.get(i) << "] ";
        std::cout<<std::endl;

        new_arr.pop_front();
        for(int i=0; i<new_arr.size(); i++)
            std::cout<< "[" << new_arr.get(i) << "] ";
        std::cout<<std::endl;
    }

    TEST(Array, Concat) {
        TypedArray<int> a;
        a.set(0,0);
        a.set(1,1);
        TypedArray<int> b = a.concat(a).concat(a); // yields a new array [0,1,0,1,0,1]
                                                    // Should leave a untouched.

        for(int i=0; i<b.size(); i++)
            std::cout<< "[" << b.get(i) << "] ";
        std::cout<<std::endl;

    }

}