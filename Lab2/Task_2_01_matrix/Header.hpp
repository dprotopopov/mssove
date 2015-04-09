#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */

//����������
void quickSort(double *data, int left, int right);
void heapSort(double *data, int length);
void host_bitonic_sort(double *data, int n, int direction);

//������������
double det(int size, double **data);

//������������ ������
double **mult(double **data1, double **data2, const int size1, const int size2, const int size3);

//���������� �������� �������
double **inverse(double **data, int size);

//���������� ������
double minor(double **data, int size, int strin, int colon);

//���������������� �������
void transposeSQR(double **data, int size);

//����� ������������� �������� �� �������, ������������ �� ��������
void findMinMax(double **data, int height, int width, double &min, double &max);