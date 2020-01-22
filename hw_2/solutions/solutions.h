#ifndef SOLUTION_H
#define SOLUTION_H

typedef struct {
   double x, y, z;
 } Point;

int running_total(int);

void reverse_in_place(int x[], int len);

int * reverse(int x[], int len);

#endif