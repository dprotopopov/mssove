#include <iostream>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */

// Задача о рационе питания
double *ration(double **a, double *b, double *c, int m, int n, int demo);
int simplex(double **plan, int *index, int *flags, int m, int n, int extended, int demo);
void gauss_jordan(double **data, int r, int c, int m, int n);
