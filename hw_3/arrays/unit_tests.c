#include <math.h>
#include <float.h> /* defines DBL_EPSILON */
#include "dynamic_array.h"
#include "gtest/gtest.h"

#define X 1.2345

namespace {

    TEST(DynamicArray, CreateAndDestroy) {
        DynamicArray * a = DynamicArray_new();
        DynamicArray_destroy(a);
    }

    TEST(DynamicArray, DeathTests) {
        DynamicArray * a = DynamicArray_new();
        ASSERT_DEATH(DynamicArray_pop(a), ".*Assertion.*");
        ASSERT_DEATH(DynamicArray_pop_front(a), ".*Assertion.*");
        DynamicArray_destroy(a);
        ASSERT_DEATH(DynamicArray_size(a), ".*Assertion.*");
    }    

    TEST(DynamicArray, SmallIndex) {
        DynamicArray * da = DynamicArray_new();
        ASSERT_EQ(DynamicArray_size(da),0);
        DynamicArray_set(da, 0, -X);        
        DynamicArray_set(da, 3, X);
        ASSERT_EQ(DynamicArray_size(da),4);
        ASSERT_EQ(DynamicArray_get(da,0), -X);
        ASSERT_EQ(DynamicArray_get(da,3), X);
        DynamicArray_destroy(da);
    }

    TEST(DynamicArray, BigIndex) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_set(da, 8, X);
        ASSERT_EQ(DynamicArray_get(da,8), X);
        DynamicArray_destroy(da);              
    }

    TEST(DynamicArray, ReallyBig) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_set(da, 400, X);
        DynamicArray_set(da, 200, X/2);        
        ASSERT_EQ(DynamicArray_get(da,200), X/2);
        ASSERT_EQ(DynamicArray_get(da,400), X);
        DynamicArray_destroy(da);              
    }  

    TEST(DynamicArray, Push) {
        DynamicArray * da = DynamicArray_new();
        double x = 0;
        while ( x < 10 ) {
            DynamicArray_push(da, x);  
            x += 0.25;
        }
        ASSERT_EQ(DynamicArray_size(da),40);
        printf("Push test Intermediate Result: %s\n", 
               DynamicArray_to_string(da));
        while ( DynamicArray_size(da) > 0 ) {
            DynamicArray_pop(da);
        }
        ASSERT_EQ(DynamicArray_size(da),0);
        DynamicArray_destroy(da);          
    }

    TEST(DynamicArray, PushFront) {
        DynamicArray * da = DynamicArray_new();
        double x = 0;
        while ( x < 10 ) {
            DynamicArray_push_front(da, x);  
            x += 0.25;
        }
        ASSERT_EQ(DynamicArray_size(da),40);
        while ( DynamicArray_size(da) > 0 ) {
            DynamicArray_pop_front(da);
        }
        ASSERT_EQ(DynamicArray_size(da),0);
        DynamicArray_destroy(da);
    } 

    TEST(DynamnicArray,ToString) {
        DynamicArray * da = DynamicArray_new();
        double x = 1.0;
        while ( x <= 5 ) {
            DynamicArray_push(da, x);  
            x += 1.0;
        }
        ASSERT_STREQ(
            DynamicArray_to_string(da),
            "[1.00000,2.00000,3.00000,4.00000,5.00000]"
        );
        DynamicArray_destroy(da);
    }

    TEST(DynamicArray, Pop) {
        DynamicArray * da = DynamicArray_new();
        double x;
        DynamicArray_push(da, X);  
        DynamicArray_push(da, X);  
        x = DynamicArray_pop(da);  
        ASSERT_EQ(DynamicArray_size(da),1);
        ASSERT_EQ(x,X);
        ASSERT_EQ(DynamicArray_get(da,1), 0.0);
        DynamicArray_destroy(da);          
    }
/*
    TEST(DynamicArray, Map) {
        DynamicArray * t = DynamicArray_new(),
                     * y;
        double s = 0.0;
        for ( int i=0; i<628; i++ ) {
            DynamicArray_set(t, i, s);
            s = s + 0.1;
        }
        y = DynamicArray_map(t,sin);
        for (int i=0; i<DynamicArray_size(t); i++) {
            ASSERT_NEAR(
                DynamicArray_get(y,i),sin(0.1*i), 0.0001
            );
        }
        DynamicArray_destroy(t);    
        DynamicArray_destroy(y);                    
    }         
*/
    TEST(DynamicArray, mathematical_op) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push(da, 1.0000);
        DynamicArray_push(da, 2.0000);
        DynamicArray_push(da, 3.0000);
        DynamicArray_push(da, 4.0000);
        ASSERT_EQ(DynamicArray_min(da), 1.0000);
        ASSERT_EQ(DynamicArray_max(da), 4.0000);
        ASSERT_EQ(DynamicArray_sum(da), 10.0000);
        ASSERT_EQ(DynamicArray_mean(da), 2.5000);
        ASSERT_EQ(DynamicArray_median(da), 2.5000);
        DynamicArray_push(da, 5.0000);
        ASSERT_EQ(DynamicArray_median(da), 3.0000);
        DynamicArray_push(da, 1.0000);
        DynamicArray_push(da, 0.5000);
        ASSERT_EQ(DynamicArray_median(da), 2.0000);

        DynamicArray_destroy(da);
    }

    TEST(DynamicArray, Last_First) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray_push(da, 1.0000);
        DynamicArray_push(da, 2.0000);
        DynamicArray_push(da, 3.0000);
        DynamicArray_push(da, 4.0000);
        DynamicArray_push(da, 5.0000);
        ASSERT_EQ(DynamicArray_last(da), 1.0000);
        ASSERT_EQ(DynamicArray_first(da), 5.0000);
        DynamicArray_destroy(da);
    }

    TEST(DynamicArray, Copy){
        DynamicArray * da = DynamicArray_new();

        DynamicArray_push(da, 1.0000);
        DynamicArray_push(da, 2.0000);
        DynamicArray_push(da, 1.0000);

        DynamicArray * cp = DynamicArray_copy(da);
        DynamicArray_print_debug_info(cp);

        DynamicArray_destroy(da);
        DynamicArray_destroy(cp);
    }

    TEST(DynamicArray, Range_step) {
        DynamicArray * da = DynamicArray_new();
        DynamicArray * range= DynamicArray_range(0,5,0.1);
        DynamicArray_push(da, 0.0000);
        DynamicArray_push(da, 0.1000);
        DynamicArray_push(da, 0.2000);
        DynamicArray_push(da, 0.3000);
        DynamicArray_push(da, 0.4000);
        DynamicArray_push(da, 0.5000);
        // DynamicArray_print_debug_info(da);
        
        // ASSERT_EQ(range, da);
        // ASSERT_EQ(compare(da, range), 1);

        DynamicArray_destroy(da);
        DynamicArray_destroy(range);
    }

    TEST(DynamicArray, Concat) {
        DynamicArray * a = DynamicArray_range(0, 1, 0.1);
        DynamicArray * b = DynamicArray_range(1.1, 2, 0.1);
        DynamicArray * c = DynamicArray_concat(a, b);
        DynamicArray_print_debug_info(c);

        DynamicArray_destroy(a);
        DynamicArray_destroy(b);
        DynamicArray_destroy(c);
    }

    TEST(DynamicArray, Take) {
        DynamicArray * a = DynamicArray_new();
        DynamicArray * b = DynamicArray_new();
        DynamicArray * c = DynamicArray_new();
        DynamicArray * d = DynamicArray_new();
        DynamicArray * e = DynamicArray_new();

        a = DynamicArray_range(1, 5, 1);
        b = DynamicArray_take(a, 2);  /* yields [ 1, 2 ] */
        c = DynamicArray_take(a, -2); /* yields [ 4, 5 ] */
        d = DynamicArray_take(a, 7);  /* yields [ 1, 2, 3, 4, 5, 0, 0 ] */
        e = DynamicArray_take(a, -7);  /* yields [0, 0, 1, 2, 3, 4, 5 ] */

        // DynamicArray_print_debug_info(a);
        // DynamicArray_print_debug_info(b);
        // DynamicArray_print_debug_info(c);
        // DynamicArray_print_debug_info(d);
        // DynamicArray_print_debug_info(e);

        DynamicArray_destroy(a);
        DynamicArray_destroy(b);
        DynamicArray_destroy(c);
        DynamicArray_destroy(d);
        DynamicArray_destroy(e);
    }
}