#include "Header.hpp"
using namespace std;

/********************************************************
Задача выделения областей

*matrix - матрица 
	int *m; // количество точек по каждому из измерений
	int n; // количество измерений
*********************************************************/
int area(int *matrix, int *m, int n, int demo){
	
	int total = 1; for(int i = 0; i < n; i++) total*=m[i];
	
	int *prevMatrix = new int[total]; // Многомерные массивы хранятся в виде одномерной последовательности
	int *nextMatrix = new int[total]; // Многомерные массивы хранятся в виде одномерной последовательности

	if(prevMatrix==NULL) return -1; // Ошибка аллокирования памяти
	if(nextMatrix==NULL) return -1; // Ошибка аллокирования памяти

	for(int i = 0; i < total; i++) prevMatrix[i]=i;

	for(int t=0; ; t++) {

		if(demo!=0) cout << "\tШаг итерации:" << t << endl;

		if(demo!=0) {
			cout << "\tИсходное состояние матрицы:" << endl; 
			for(int i = 0; i < total; i++) {
				cout << prevMatrix[i] << '\t'; 
				if(i%m[0]==m[0]-1) cout << endl;
			}
		}

		// Шаг итераций
#pragma omp parallel for
		for(int i = 0; i < total; i++) {
			int *x0 = new int[n];
			int *x1 = new int[n];
			nextMatrix[i]=prevMatrix[i];
			vectorOf(i, x0, m, n);
			for(int j=0; j<n; j++) {
				if(x0[j]+1<m[j]) {
					for(int j1=0; j1<n; j1++) x1[j1]=(j1!=j)?x0[j1]:(x0[j]+1);
					int index = indexOf(x1,m,n);
					if(matrix[i]==matrix[index] && nextMatrix[i]>prevMatrix[index])
						nextMatrix[i]=prevMatrix[index];
				}

				if(x0[j]-1>=0) {
					for(int j1=0; j1<n; j1++) x1[j1]=(j1!=j)?x0[j1]:(x0[j]-1);
					int index = indexOf(x1,m,n);
					if(matrix[i]==matrix[index] && nextMatrix[i]>prevMatrix[index])
						nextMatrix[i]=prevMatrix[index];
				}
			}
			delete x0;
			delete x1;
		}

		if(demo!=0) {
			cout << "\tНовое состояние матрицы:" << endl; 
			for(int i = 0; i < total; i++) {
				cout << nextMatrix[i] << '\t'; 
				if(i%m[0]==m[0]-1) cout << endl;
			}
		}

		// Расчёт разницы
		int delta = 0;
		for(int i = 0; i < total; i++) 
			if(delta<abs(nextMatrix[i]-prevMatrix[i]))
				delta=abs(nextMatrix[i]-prevMatrix[i]);

		if(demo!=0) cout << "\tМаксимальное изменение матрицы:" << delta << endl; 

		if(demo!=0) {
			cout << "\tНажмите ВВОД для продолжения" << endl;
			getchar();
			getchar();
		}

		// Проверка условия прекращения итераций
		if(delta==0) break;

		int *temp = prevMatrix; prevMatrix = nextMatrix; nextMatrix = temp;
	}

#pragma omp parallel for
	for(int i = 0; i < total; i++) nextMatrix[i]=0;
#pragma omp parallel for
	for(int i = 0; i < total; i++) nextMatrix[prevMatrix[i]]=1;
	int count = 0; for(int i = 0; i < total; i++) count+=nextMatrix[i];

	if(demo!=0) cout << "\tКоличество областей:" << count << endl;
	
	if(demo!=0) {
		int id = 0;
		for(int j = 0; j < total; j++) if(nextMatrix[j]!=0) {
			cout << "\tOбласть # " << id++ << endl;
			for(int i = 0; i < total; i++) {
				if(prevMatrix[i]==j) cout << matrix[i] << '\t'; 
				else cout << "X" << '\t'; 
				if(i%m[0]==m[0]-1) cout << endl;
			}
		}
	}

	delete prevMatrix;
	delete nextMatrix;
	return 0;
}

/********************************************************
Преобразование вектора координат в индекс одномерного массива

	int *x; // координаты точки
	int *m; // количество точек по каждому из измерений
	int n; // количество измерений
*********************************************************/
int indexOf(int *x, int *m, int n) {
	int index = 0;
	for(int i=n;--i>0;) {
		index += x[i];
		index *= m[i-1];
	}
	index += x[0];
	return index;
}

/********************************************************
Преобразование индекса в одномерном массиве в вектор координат

	int index - индекс в одномерном массиве
	int *x; // координаты точки
	int *m; // количество точек по каждому из измерений
	int n; // количество измерений
*********************************************************/
int *vectorOf(int index, int *x, int *m, int n) {
	for(int i=n;--i>0;) {
		x[i] = index/m[i-1];
		index -= x[i]*m[i-1];
	}
	x[0] = index;
	return x;
}