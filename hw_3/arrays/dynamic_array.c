#include "dynamic_array.h"
// #include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* private functions *********************************************************/

/* Position in the buffer of the array element at position index */
static int index_to_offset ( const DynamicArray * da, int index ) {
    return index + da->origin;
}

/* Position of the element at buffer position 'offset' */
static int offset_to_index ( const DynamicArray * da, int offset ) {
    return offset - da->origin;
}

/* Non-zero if and only if offset lies ouside the buffer */
static int out_of_buffer ( DynamicArray * da, int offset ) {
    return offset < 0 || offset >= da->capacity;
}

/* Makes a new buffer that is twice the size of the old buffer,
   copies the old information into the new buffer, and deletes
   the old buffer */
static void extend_buffer ( DynamicArray * da ) {

    double * temp = (double *) calloc ( 2 * da->capacity, sizeof(double) );
    int new_origin = da->capacity - (da->end - da->origin)/2,
           new_end = new_origin + (da->end - da->origin);

    for ( int i=0; i<DynamicArray_size(da); i++ ) {
        temp[new_origin+i] = DynamicArray_get(da,i);
    }

    free(da->buffer);
    da->buffer = temp;

    da->capacity = 2 * da->capacity;
    da->origin = new_origin;
    da->end = new_end;

    return;

}

/* public functions **********************************************************/

DynamicArray * DynamicArray_new(void) {
    DynamicArray * da = (DynamicArray *) malloc(sizeof(DynamicArray));
    da->capacity = DYNAMIC_ARRAY_INITIAL_CAPACITY;    
    da->buffer = (double *) calloc ( da->capacity, sizeof(double) ); 
    da->origin = da->capacity / 2;
    da->end = da->origin;
    return da;
}

void DynamicArray_destroy(DynamicArray * da) {
    free(da->buffer);
    da->buffer = NULL;
    return;
}

int DynamicArray_size(const DynamicArray * da) {
    assert(da->buffer != NULL);
    return da->end - da->origin;
}

char * DynamicArray_to_string(const DynamicArray * da) {
    assert(da->buffer != NULL);
    char * str = (char *) calloc (20,DynamicArray_size(da)),
         temp[20];
    int j = 1;
    str[0] = '[';
    for ( int i=0; i < DynamicArray_size(da); i++ ) {
        if ( DynamicArray_get(da,i) == 0 ) {
            snprintf ( temp, 20, "0" );
        } else {
            snprintf ( temp, 20, "%.5lf", DynamicArray_get(da,i) ); 
        }
        if ( i < DynamicArray_size(da) - 1 ) {
            sprintf( str + j, "%s,", temp);
            j += strlen(temp) + 1;
        } else {
            sprintf( str + j, "%s", temp);
            j += strlen(temp);
        }

    }
    str[j] = ']';
    return str;
}

void DynamicArray_print_debug_info(const DynamicArray * da) {

    char * s = DynamicArray_to_string(da);
    printf ( "  %s\n", s);
    printf ( "  capacity: %d\n  origin: %d\n  end: %d\n  size: %d\n\n",
      da->capacity, 
      da->origin, 
      da->end,
      DynamicArray_size(da));

    free(s);

}

void DynamicArray_set(DynamicArray * da, int index, double value) {
    assert(da->buffer != NULL);
    assert ( index >= 0 );
    while ( out_of_buffer(da, index_to_offset(da, index) ) ) {
        extend_buffer(da);
    }
    da->buffer[index_to_offset(da, index)] = value;
    if ( index >= DynamicArray_size(da) ) {
        da->end = index_to_offset(da,index+1);
    }

}

double DynamicArray_get(const DynamicArray * da, int index) {
    assert(da->buffer != NULL);
    assert ( index >= 0 );
    if ( index >= DynamicArray_size(da) ) {
        return 0;
    } else {
        return da->buffer[index_to_offset(da,index)];
    }
}

void DynamicArray_push(DynamicArray * da, double value ) {
    DynamicArray_set(da, DynamicArray_size(da), value );
}

void DynamicArray_push_front(DynamicArray * da, double value) {
    assert(da->buffer != NULL);
    while ( da->origin == 0 ) {
        extend_buffer(da);
    }
    da->origin--;
    DynamicArray_set(da,0,value);
}

double DynamicArray_pop(DynamicArray * da) {
    assert(DynamicArray_size(da) > 0);
    double value = DynamicArray_get(da, DynamicArray_size(da)-1);
    DynamicArray_set(da, DynamicArray_size(da)-1, 0.0);
    da->end--;
    return value;
}

double DynamicArray_pop_front(DynamicArray * da) {
    assert(DynamicArray_size(da) > 0);
    double value = DynamicArray_last(da);
    da->origin++;
    return value;
}

double DynamicArray_first ( const DynamicArray * da ){
    assert(DynamicArray_size(da) > 0);
    return DynamicArray_get(da,DynamicArray_size(da)-1);
}
double DynamicArray_last ( const DynamicArray * da ){
    assert(DynamicArray_size(da) > 0);
    return DynamicArray_get(da, 0);
}

DynamicArray * DynamicArray_map(const DynamicArray * da, double (*f) (double)) {
    assert(da->buffer != NULL);
    // DynamicArray * result = DynamicArray_new();
    DynamicArray * result = DynamicArray_copy(da);
    for ( int i=0; i<DynamicArray_size(da); i++ ) {
        DynamicArray_set(result, i, f(DynamicArray_get(da, i)));
    }
    return result;
}

DynamicArray * DynamicArray_copy ( const DynamicArray * da ){
    assert(da->buffer != NULL);
    DynamicArray * copy = DynamicArray_new();
    for ( int i=0; i<DynamicArray_size(da); i++ ) {
        DynamicArray_set(copy, i, DynamicArray_get(da, i));
    }
    return copy;
}

DynamicArray * DynamicArray_subarray(DynamicArray * da, int a, int b) {

  assert(da->buffer != NULL);
  assert(b >= a);

  DynamicArray * result = DynamicArray_new();

  for (int i=a; i<b; i++) {
      DynamicArray_push(result,DynamicArray_get(da, i));
  }

  return result;
}

double DynamicArray_min ( const DynamicArray * da ){
    double min = DynamicArray_get(da, 0);
    assert(DynamicArray_size(da) > 0);

    for(int i=0; i< DynamicArray_size(da); i++){
        if(DynamicArray_get(da, i)< min)
            min = DynamicArray_get(da, i);
    }
    return min;
}

double DynamicArray_max ( const DynamicArray * da ){
    double max = DynamicArray_get(da, 0);
    assert(DynamicArray_size(da) > 0);

    for(int i=0; i< DynamicArray_size(da); i++){
        if(DynamicArray_get(da, i)> max)
            max = DynamicArray_get(da, i);
    }
    return max;
}

double DynamicArray_mean ( const DynamicArray * da ){
    assert(DynamicArray_size(da) > 0);

    return DynamicArray_sum(da)/DynamicArray_size(da);
}
 
// A function to implement bubble sort 
void bubbleSort(DynamicArray * arr, int n) { 
   for (int i = 0; i < n-1; i++) {   
       // Last i elements are already in place    
       for (int j = 0; j < n-i-1; j++)  
           if (DynamicArray_get(arr,j) > DynamicArray_get(arr,j+1)) {
               double temp = DynamicArray_get(arr,j);
               DynamicArray_set(arr, j, DynamicArray_get(arr,j+1));
               DynamicArray_set(arr, j+1, temp);
           }
   }
} 

double DynamicArray_median ( const DynamicArray * da ){
    assert(DynamicArray_size(da) > 0);

    // qsort(arr, N, sizeof(int), compare);
    DynamicArray * sort_arr = DynamicArray_copy(da);
    double median = 0.0000;
    bubbleSort(sort_arr, DynamicArray_size(sort_arr));

    if (DynamicArray_size(sort_arr)%2 == 1)
        return DynamicArray_get(sort_arr, DynamicArray_size(sort_arr)/2);
    return (DynamicArray_get(sort_arr, DynamicArray_size(sort_arr)/2) + DynamicArray_get(sort_arr, DynamicArray_size(sort_arr)/2 - 1))/2;
}

double DynamicArray_sum ( const DynamicArray * da ){
    if (DynamicArray_size(da) == 0)
        return 0.0000;
    double sum = 0.0000;
    for(int i=0; i<DynamicArray_size(da); i++){
        sum += DynamicArray_get(da, i);
    }
    return sum;
}

DynamicArray * DynamicArray_range ( double a, double b, double step){
    DynamicArray * re = DynamicArray_new();
    double count = a;
    if(b >= a && step >= 0){
        while(count <= b){
            DynamicArray_push(re, count);
            count += step;
            // printf("count:%lf, step:%lf\n", count, step);
        }
    }else if(b < a && step <= 0) {//0, -1, -.1
        while(count >= b){
            DynamicArray_push(re, count);
            count += step;
            // printf("count:%lf, step:%lf\n", count, step); 
        }
    }else{return re;}
    return re;
}

DynamicArray * DynamicArray_concat ( const DynamicArray * a, const DynamicArray * b ){
    DynamicArray * concat = DynamicArray_copy(a);
    DynamicArray * copy_b = DynamicArray_copy(b);
    for (int i = 0; i < DynamicArray_size(b); i++ ){
        DynamicArray_push(concat, DynamicArray_pop_front(copy_b));
    }
    return concat;
}

DynamicArray * DynamicArray_take(const DynamicArray * a, const int value) {
    DynamicArray * take_arr = DynamicArray_new();
    int a_size = DynamicArray_size(a);// 5
    if (value > 0){
        for (int i=0; i < value; i++)
            if(i < a_size){
                DynamicArray_push(take_arr, DynamicArray_get(a,i));
            }else{
                DynamicArray_push(take_arr, 0);
            }
    }
    if (value < 0){
        if(-value > a_size){
            for(int i=0; i < -value-a_size; i++)
                DynamicArray_push_front(take_arr, 0);
            take_arr = DynamicArray_concat(take_arr, a);
        }else{
            for (int i=0; i < -value; i++)
                DynamicArray_push_front(take_arr, DynamicArray_get(a, DynamicArray_size(a)-i-1));
        }
        
        
    }

    return take_arr;
}

