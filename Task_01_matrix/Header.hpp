#include <iostream>

//Сортировки
void quickSort(double *data, int left, int right);
void heapSort(double *data, int length);

//Определитель
double det(int size, double **data);

//Произведение матриц
double **mult(double **data1, double **data2, const int size1, const int size2, const int size3);

//Вычисление обратной матрицы
double **inverse(double **data, int size);

//Вычисление минора
double minor(double **data, int size, int strin, int colon);

//Транспонирование матрицы
void transposeSQR(double **data, int size);

//Поиск максимального элемента по строкам, минимального по столбцам
void findMinMax(double **data, int height, int weight, double &min, double &max);