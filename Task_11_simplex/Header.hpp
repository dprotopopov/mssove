#include <iostream>

// Задача о рационе питания
double *ration(double **a, double *b, double *c, int m, int n);
int simplex(double **plan, int *index, int *flags, int m, int n, int extended);
void gauss_jordan(double **data, int r, int c, int m, int n);
