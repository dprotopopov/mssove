#include "Header.hpp"
using namespace std;

/********************************************************
ћодель, реализующа€ матрицу якоби с граничными услови€ми

n - количество измерений
*m - количество точек по каждому из измерений
*x - вектор координат точки воздействи€
value - величина воздействи€
mode - режим (0 - непрерывное воздействе, 1 - однократное воздействие)
*********************************************************/

int jacobi_field(int n,int *m,int *x,double value,int mode, int demo){
	double epsilon=1e-7; // минимальное изменение дл€ продолжени€ итераций
	int nmax=1000; // максимальное число итераций

	int total = 1; for(int i = 0; i < n; i++) total*=m[i];
	
	double *prevMatrix = new double[total]; // ћногомерные массивы хран€тс€ в виде одномерной последовательности
	double *nextMatrix = new double[total]; // ћногомерные массивы хран€тс€ в виде одномерной последовательности
	int *x0 = new int[n];
	int *x1 = new int[n];

	if(prevMatrix==NULL) return -1; // ќшибка аллокировани€ пам€ти
	if(nextMatrix==NULL) return -1; // ќшибка аллокировани€ пам€ти

	for(int i = 0; i < total; i++) prevMatrix[i]=0;
	int index = indexOf(x,m,n); // индекс точки воздействи€
	prevMatrix[index] = value;

	for(int t=0; t<nmax; t++) {

		if(demo!=0) cout << "\tЎаг итерации:" << t << endl;

		if(demo!=0) {
			cout << "\t»сходное состо€ние матрицы:" << endl; 
			for(int i = 0; i < total; i++) {
				cout << prevMatrix[i] << '\t'; 
				if(i%m[0]==m[0]-1) cout << endl;
			}
		}

		// Ўаг итераций

		for(int i = 0; i < total; i++) {
			nextMatrix[i]=0;
			vectorOf(i, x0, m, n);
			// ¬ычисл€ем среднее соседних точек к точке x0 по каждому из измерений
			for(int j=0; j<n; j++) {
				if(x0[j]+1<m[j]) {
					for(int j1=0; j1<n; j1++) x1[j1]=(j1!=j)?x0[j1]:(x0[j]+1);
					nextMatrix[i] += prevMatrix[indexOf(x1, m, n)];
				}
				else 
					nextMatrix[i] += 0; // состо€ние пространства за пределом матрицы принимаетс€ равным 0

				if(x0[j]-1>=0) {
					for(int j1=0; j1<n; j1++) x1[j1]=(j1!=j)?x0[j1]:(x0[j]-1);
					nextMatrix[i] += prevMatrix[indexOf(x1, m, n)];
				}
				else 
					nextMatrix[i] += 0; // состо€ние пространства за пределом матрицы принимаетс€ равным 0
			}
			nextMatrix[i] /= 2*n;
		}

		if(demo!=0) {
			cout << "\tЌовое состо€ние матрицы:" << endl; 
			for(int i = 0; i < total; i++) {
				cout << nextMatrix[i] << '\t'; 
				if(i%m[0]==m[0]-1) cout << endl;
			}
		}

		// –асчЄт разницы (кроме точки воздействи€ при непрерывном воздействии)
		double delta = 0;
		for(int i = 0; i < total; i++) 
			if(i==index&&mode==0) continue;
			else if(delta<abs(nextMatrix[i]-prevMatrix[i]))
				delta=abs(nextMatrix[i]-prevMatrix[i]);

		if(demo!=0) cout << "\tћаксимальное изменение матрицы:" << delta << endl; 

		if(demo!=0) {
			cout << "\tЌажмите ¬¬ќƒ дл€ продолжени€" << endl;
			getchar();
			getchar();
		}

		// ѕроверка услови€ прекращени€ итераций
		if(delta<epsilon) break;

		double *temp = prevMatrix; prevMatrix = nextMatrix; nextMatrix = temp;
		if(mode==0) prevMatrix[index] = value;
	}


	delete x0;
	delete x1;
	delete prevMatrix;
	delete nextMatrix;
	return 0;
}


/********************************************************
ѕреобразование вектора координат в индекс одномерного массива

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
ѕреобразование индекса в одномерном массиве в вектор координат

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