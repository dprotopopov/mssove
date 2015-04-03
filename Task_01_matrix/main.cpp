#include "Header.hpp"
using namespace std;

int main(){
	const int size1 = 1;
	const int size2 = 1;
	const int size3 = 1;
	double massiv1[15];// = {-1.0, -3.0, 0.0, 6.0, 7.0, 2.0, 2.0, -1.0, -55.0, -99.0, 1505.0};
//	double massiv2[11] = {-111.0, -2223.0, 0.0, 6.0, 7777.0, 2.0, 2.0, -1.0, -55.0, -9229.0, 1505.0};
	double **a = new double*[size1];
	double **b = new double*[size2];
	double **c = new double*[size1];

	for(int i = 0; i < size1; i++)
		a[i] = new double[size2];
	for(int i = 0; i < size2; i++)
		b[i] = new double[size3];
	
/*
	setlocale(LC_ALL, "Russian");
	cout << "\tВведите матрицу 1х1:" << endl;
	for(int i = 0; i < size1; i++)
		for(int j = 0; j < size2; j++)
			cin >> a[i][j];
	if((b = inverse(a, size1)) == NULL)
	{
		cout << "Ошибка: определитель матрицы равен 0. Обратной матрицы не существует." << endl;
		getchar();
		getchar();
		return -1;
	}

	cout << "\tОбратная матрица: " << endl;
	for(int i = 0; i < size1; i++)
	{
		for(int j = 0; j < size1; j++)
			cout << b[i][j] << '\t';
		cout << endl;
	}
	getchar();
	getchar();*/
/*
	cout << "\tВведите матрицу 2х2:" << endl;
	for(int i = 0; i < size2; i++)
		for(int j = 0; j < size3; j++)
			cin >> b[i][j];

	c = mult(a, b, size1, size2, size3);

	cout << "\tРезультат произведения" << endl;
	for(int i = 0; i < size1; i++)
	{
		for(int j = 0; j < size3; j++)
			cout << c[i][j] << ' ';
		cout << endl;
	}
	getchar();
	getchar();
	double min, max;
	findMinMax(a, size1, size3, min, max);
	cout << "Минимальный элемент матрицы: " << min << endl
		<< "Максимальный элемент матрицы: " << max << endl;

*/
	/*
	for(int i = 0; i < size2; i++)
		for(int j = 0; j < size3; j++)
			cin >> b[i][j];



	cout << "\tОпределитель матрицы равен "  << det(size1, a) << endl;

	getchar();
	getchar();
	for(int i = 0; i < size1; i++)
	{
		for(int j = 0; j < size3; j++)
			cout << c[i][j] << ' ';
		cout << endl;
	}

	*/
/*	

	cout << "Введите число: " << endl << '\t';
	for(int i = 0; i < 1; i++)
		cin >> massiv1[i];

	
	heapSort(massiv1, 1);
	cout << endl << "Результат после сортировки: " << endl << '\t';
	for(int i = 0; i < 1; i++)
		cout << massiv1[i] << ' ';
	cout << endl;
	getchar();
	getchar();
*//*
	heapSort(massiv2, 11);
	for(int i = 0; i < 10; i++)
		cout << massiv2[i] << ' ';
	cout << endl;
*/


	return 0;
}