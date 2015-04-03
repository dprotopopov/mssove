#include "Header.hpp"
using namespace std;

/********************************************************
������, ����������� ������� ����� � ���������� ���������

	int n; // ���������� ���������
	int *m; // ���������� ����� �� ������� �� ���������
	double value; // �������� �������� �����������
*********************************************************/

int jacobi_field(int n,int *m,double value, int demo){
	double epsilon=1e-7; // ����������� ��������� ��� ����������� ��������
	int nmax=1000; // ������������ ����� ��������

	int total = 1; for(int i = 0; i < n; i++) total*=m[i];
	
	double *prevMatrix = new double[total]; // ����������� ������� �������� � ���� ���������� ������������������
	double *nextMatrix = new double[total]; // ����������� ������� �������� � ���� ���������� ������������������
	int *x0 = new int[n];
	int *x1 = new int[n];

	if(prevMatrix==NULL) return -1; // ������ ������������� ������
	if(nextMatrix==NULL) return -1; // ������ ������������� ������
	if(x0==NULL) return -1; // ������ ������������� ������
	if(x1==NULL) return -1; // ������ ������������� ������

	for(int i = 0; i < total; i++) prevMatrix[i]=0;

	for(int t=0; t<nmax; t++) {

		if(demo!=0) cout << "\t��� ��������:" << t << endl;

		if(demo!=0) {
			cout << "\t�������� ��������� �������:" << endl; 
			for(int i = 0; i < total; i++) {
				cout << prevMatrix[i] << '\t'; 
				if(i%m[0]==m[0]-1) cout << endl;
			}
		}

		// ��� ��������
		for(int i = 0; i < total; i++) {
			nextMatrix[i]=0;
			vectorOf(i, x0, m, n);
			// ��������� ������� �������� ����� � ����� x0 �� ������� �� ���������
			for(int j=0; j<n; j++) {
				if(x0[j]+1<m[j]) {
					for(int j1=0; j1<n; j1++) x1[j1]=(j1!=j)?x0[j1]:(x0[j]+1);
					nextMatrix[i] += prevMatrix[indexOf(x1, m, n)];
				}
				else 
					nextMatrix[i] += value; // ��������� ������������ �� �������� ������� ����������� ������ value

				if(x0[j]-1>=0) {
					for(int j1=0; j1<n; j1++) x1[j1]=(j1!=j)?x0[j1]:(x0[j]-1);
					nextMatrix[i] += prevMatrix[indexOf(x1, m, n)];
				}
				else 
					nextMatrix[i] += value; // ��������� ������������ �� �������� ������� ����������� ������ value
			}
			nextMatrix[i] /= 2*n;
		}

		if(demo!=0) {
			cout << "\t����� ��������� �������:" << endl; 
			for(int i = 0; i < total; i++) {
				cout << nextMatrix[i] << '\t'; 
				if(i%m[0]==m[0]-1) cout << endl;
			}
		}

		// ������ ������� (����� ����� ����������� ��� ����������� �����������)
		double delta = 0;
		for(int i = 0; i < total; i++) 
			if(delta<abs(nextMatrix[i]-prevMatrix[i]))
				delta=abs(nextMatrix[i]-prevMatrix[i]);

		if(demo!=0) cout << "\t������������ ��������� �������:" << delta << endl; 

		if(demo!=0) {
			cout << "\t������� ���� ��� �����������" << endl;
			getchar();
			getchar();
		}

		// �������� ������� ����������� ��������
		if(delta<epsilon) break;

		double *temp = prevMatrix; prevMatrix = nextMatrix; nextMatrix = temp;
	}


	delete prevMatrix;
	delete nextMatrix;
	delete x0;
	delete x1;
	return 0;
}


/********************************************************
�������������� ������� ��������� � ������ ����������� �������

	int *x; // ���������� �����
	int *m; // ���������� ����� �� ������� �� ���������
	int n; // ���������� ���������
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
�������������� ������� � ���������� ������� � ������ ���������

	int index - ������ � ���������� �������
	int *x; // ���������� �����
	int *m; // ���������� ����� �� ������� �� ���������
	int n; // ���������� ���������
*********************************************************/
int *vectorOf(int index, int *x, int *m, int n) {
	for(int i=n;--i>0;) {
		x[i] = index/m[i-1];
		index -= x[i]*m[i-1];
	}
	x[0] = index;
	return x;
}