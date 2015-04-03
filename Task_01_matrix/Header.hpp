#include <iostream>

//����������
void quickSort(double *data, int left, int right);
void heapSort(double *data, int length);

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
void findMinMax(double **data, int height, int weight, double &min, double &max);