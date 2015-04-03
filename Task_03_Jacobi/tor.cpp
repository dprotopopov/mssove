#include "Header.hpp"
using namespace std;

/********************************************************
������, ����������� ������� �����, ��������� � ���

	int n; // ���������� ���������
	int *m; // ������ ����� �� ������� �� ���������
	int *x; // ������ ��������� ����� �����������
	double value; // �������� �����������
	int mode; // �����
*********************************************************/

int jacobi_tor(int n,int *m,int *x,double value,int mode){
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

	for(int i = 0; i < n; i++) x[i] %= m[i]; // ������������ ��������� � ����

	for(int i = 0; i < total; i++) prevMatrix[i]=0;
	int index = indexOf(x,m,n); // ������ ����� �����������
	prevMatrix[index] = value;

	for(int t=0; t<nmax; t++) {

		cout << "\t��� ��������:" << t << endl;

		cout << "\t�������� ��������� �������:" << endl; 
		for(int i = 0; i < total; i++) {
			cout << prevMatrix[i] << '\t'; 
			if(i%m[0]==m[0]-1) cout << endl;
		}

		// ��� ��������
		for(int i = 0; i < total; i++) {
			nextMatrix[i]=0;
			vectorOf(i, x0, m, n);
			// ��������� ������� �������� ����� � ����� x0 �� ������� �� ���������
			for(int j=0; j<n; j++) {
				for(int j1=0; j1<n; j1++) x1[j1]=(j1!=j)?x0[j1]:((x0[j]+1)%m[j]);
				nextMatrix[i] += prevMatrix[indexOf(x1, m, n)];
				for(int j1=0; j1<n; j1++) x1[j1]=(j1!=j)?x0[j1]:((x0[j]+m[j]-1)%m[j]);
				nextMatrix[i] += prevMatrix[indexOf(x1, m, n)];
			}
			nextMatrix[i] /= 2*n;
		}

		cout << "\t����� ��������� �������:" << endl; 
		for(int i = 0; i < total; i++) {
			cout << nextMatrix[i] << '\t'; 
			if(i%m[0]==m[0]-1) cout << endl;
		}

		// ������ ������� (����� ����� ����������� ��� ����������� �����������)
		double delta = 0;
		for(int i = 0; i < total; i++) 
			if(i==index&&mode==0) continue;
			else if(delta<abs(nextMatrix[i]-prevMatrix[i]))
				delta=abs(nextMatrix[i]-prevMatrix[i]);

		cout << "\t������������ ��������� �������:" << delta << endl; 

		cout << "\t������� ���� ��� �����������" << endl;
		getchar();
		getchar();

		// �������� ������� ����������� ��������
		if(delta<epsilon) break;

		double *temp = prevMatrix; prevMatrix = nextMatrix; nextMatrix = temp;
		if(mode==0) prevMatrix[index] = value;
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
	int *m; // ������ ����� �� ������� �� ���������
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
	int *m; // ������ ����� �� ������� �� ���������
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