#include "Header.hpp"
/***********************************************************************
Поиск максимального элемента по строкам, минимального по столбцам

**data - матрица
height - высота матрицы (кол-во строк)
weight - ширина матрицы (кол-во столбцов)
&min - минимальный  элемент
&max - максимальный элемент
***********************************************************************/



void findMinMax(double **data, int height, int weight, double &min, double &max){

	min = max = data[0][0];

	//Поиск максимального элемента по строкам
	for(int str = 0; str < height; str++)
		for(int col = 0; col < weight; col++)
			if(max < data[str][col])
				max = data[str][col];
	

	//Поиск минимального элемента по столбцам
	for(int col = 0; col < weight; col++)
		for(int str = 0; str < height; str++)
			if(min > data[str][col])
				min = data[str][col];
}