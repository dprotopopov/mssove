#include "Header.hpp"
/***********************************************************************
Поиск максимального и минимального элемента

**data - матрица
height - высота матрицы (кол-во строк)
width - ширина матрицы (кол-во столбцов)
&min - минимальный  элемент
&max - максимальный элемент
***********************************************************************/



void findMinMax(double **data, int height, int width, double &min, double &max){

	min = max = data[0][0];

	double *temp = new double[height+1]; //+1 для нулевого размера

	//Поиск максимального элемента по строкам
	for(int str = 0; str < height; str++) {
		temp[str]=data[str][0];
		for(int col = 0; col < width; col++)
			if(temp[str] < data[str][col])
				temp[str] = data[str][col];
	}

	//Поиск максимального элемента среди максимальных элементов строк
	//непараллельные вычисления
	for(int str = 0; str < height; str++) {
		if(max < temp[str])
			max = temp[str];
	}

	//Поиск минимального элемента по столбцам
	for(int str = 0; str < height; str++) {
		temp[str]=data[str][0];
		for(int col = 0; col < width; col++)
			if(temp[str] > data[str][col])
				temp[str] = data[str][col];
	}

	//Поиск минимального элемента среди минимальных элементов строк
	//непараллельные вычисления
	for(int str = 0; str < height; str++) {
		if(min > temp[str])
			min = temp[str];
	}

	delete temp;
}