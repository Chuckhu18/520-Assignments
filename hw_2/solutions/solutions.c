#include "solutions.h"
#include <stdio.h>
#include <stdlib.h>

int re_total = 0;

int running_total(int a){
  re_total += a;
  return re_total;
}

void reverse_in_place(int x[], int len){
  int arr[len];

  for (int i=0; i<len; i++)
    arr[i] = x[i];

  for (int i=0; i<len; i++)
    x[i] = arr[len-i-1];
}

int * reverse(int x[], int len){
  int * arr;
  arr = (int *) calloc(len,sizeof(int));

  for (int i=0; i<len; i++){
    arr[i] = x[len-i-1];
    // printf("a[%d]=%d\n",i,x[i]);
  }

  return arr;
}


int num_instances(int a[], int len, int value){
  int count = 0;
  for(int i =0; i<len; i++){
    if(a[i]==value)
      count++;
  }

  return count;
}

Point * map(Point a[], int len, Point (* f_ptr)(Point)){
  Point * arr = (Point *) calloc(len,sizeof(Point));
  for(int i = 0; i<len; i++){
    arr[i] = (* f_ptr)(a[i]);
    // printf("==============================%lf \n", arr[i].x);
    // printf("==============================%lf \n", arr[i].y);
    // printf("==============================%lf \n", arr[i].z);
  }
  
  return arr;
}