#include "Header.hpp"
using namespace std;

/********************************************************
���������� ����� �������� �������� ������� f(x)=cx
��� ����������� ���� ax>=b � ����������� b>=0,x>=0

**a - ������� ������������� ����� ����� �����������
*b - ������ �������� ������ ����� �����������
*c - ������������ �������� �������
m - ���������� ���������� (�����)
n - ���������� ���������� (��������)
*********************************************************/
double *ration(double **a, double *b, double *c, int m, int n, int demo){
	
	// ����� �������������� ������
	// http://matesha.ru/book/lp5.php

	double **plan; // ��������-�������
	int *index; // ������� ���������� � ������ 
	int *flags; // ����� ���������� � ������ 

	index = new int[m]; 
	flags = new int[m+n]; 
	for(int i = 0; i < m; i++) 
		index[i] = m+n+i; // ������� ������������� ����������
	for(int i = 0; i < m+n; i++) 
		flags[i] = 0; // ����� ����������

	plan = new double *[m+2];
	for(int i = 0; i < m+2; i++)
		plan[i] = new double[1+m+n];

#pragma omp parallel for
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m+n; j++)
			plan[i][j+1]=(j<n)?(a[i][j]):((j==(n+i))?-1:0);

	// ��������� F ������ ������� 
#pragma omp parallel for
	for(int j = 0; j < m+n; j++) {
		plan[m][j+1] = (j<n)?(-c[j]):0;
	}

	// ��������� M ������ ������� 
#pragma omp parallel for
	for(int j = 0; j < m+n; j++) {
		plan[m+1][j+1] = (j<n)?0:-1;
		if(j<n) for(int i = 0; i < m; i++) plan[m+1][j+1] += a[i][j];
	}
	
	for(int i = 0; i < m; i++)
		plan[i][0]=b[i];

	plan[m][0]=0;
	plan[m+1][0]=0;

	if(simplex(plan, index, flags, m, n, 1, demo)!=0) return NULL; // ���������� ������������� ����������
	if(simplex(plan, index, flags, m, n, 0, demo)!=0) return NULL; // ���������� �������

	double * result;
	result = new double[n]; //���������
	for(int i = 0; i < n; i++) result[i]=0;
	for(int i = 0; i < m; i++) if(index[i]<n) result[index[i]]=plan[i][0];
	
	for(int i = 0; i < m+2; i++) delete plan[i];
	delete plan;
	delete index;
	delete flags;

	return result;
}

/********************************************************
���������� �������-������ �� ������� �����

**plan - ������� �����
*index - ������� ���������� � ������ 
*flags - ����� ���������� � ������ 
m - ���������� �������� ����������
n - ���������� ����������
extended = 0,1 - ���� ������������� ����������� �������
*********************************************************/
int simplex(double **plan, int *index, int *flags, int m, int n, int extended, int demo) {
	while(1){
		if(demo!=0) {
			cout << "\t������� ���� plan["<<1+m+extended<<","<<1+m+n<<"]:" << endl;
			for(int i = 0; i < 1+m+extended; i++) {
				for(int j = 0; j < 1+m+n; j++) 
					cout << plan[i][j] << "\t";
				cout << endl;
			}

			cout << "\t���������� � ������ index["<<m<<"]:" << endl;
			for(int i = 0; i < m; i++)
				cout << index[i] << "\t";
			cout << endl;
		}

		// ��������� ������� ���� �� �������������
		// ���� ��� ������ � ��������� ������ ����� ���������������, �� ���� ���������
		double maxByRow=0;
		for(int j = 0; j < m+n; j++) 
			if(flags[j]==0 && maxByRow < plan[m+extended][j+1])
				maxByRow = plan[m+extended][j+1];
		
		if(maxByRow<=0) return 0; // ������ ����������� ����

		// ������� �������� ������� ������� �����

		double maxByMod = 0;
		int r=0; 
		int c=0;
		
		for(int j = 0; j < m+n; j++) if(flags[j]==0 && plan[m+extended][j+1]>0) {
			double minByCol=-1;
			for(int i = 0; i < m; i++) if(plan[i][j+1]>0) {
				minByCol = plan[i][0]/plan[i][j+1];
				for(int i1 = i+1; i < m; i++) 
					if(plan[i1][j+1]>0 && minByCol > plan[i1][0]/plan[i1][j+1])
						minByCol = plan[i1][0]/plan[i1][j+1];
				break;
			}

			if(minByCol < 0) return -1; // ������� �� �������

			if(maxByMod<minByCol*plan[m+extended][j+1]) {
				maxByMod=minByCol*plan[m+extended][j+1];
				for(int i = 0; i < m; i++) 
					if(plan[i][j+1]>0 && minByCol==plan[i][0]/plan[i][j+1]) {
						r = i;
						c = j+1;
					}
			}
		}

		if(demo!=0) cout << "\t�������� �������: (" << r << "," << c << ")" << endl;

		// ��������� �������� ������-������� ��� ��������� ��������� �������� �������
		gauss_jordan(plan, r, c, 1+m+extended, 1+m+n);

		// ���������� c-1 �������� ��� ���������� � ����� ������ ����������
		if(index[r]<m+n) flags[index[r]]=0;
		index[r] = c-1;
		flags[index[r]]=1;
	}
	return 0;
}

/********************************************************
�������� ������-������� ��� ��������� ��������� �������� �������

**data - ������� 
r - ����� ������ ��������� ��������
� - ����� ������� ��������� ��������
m - ���������� ����� �������
n - ���������� �������� �������
*********************************************************/
void gauss_jordan(double **data, int r, int c, int m, int n) {
	double d = data[r][c];
	double epsilon=1e-7; // �������� ���������� � ��������� ������

#pragma omp parallel for
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(i!=r && j!=c) {
				data[i][j] -= data[r][j]*data[i][c]/d;
				if(abs(data[i][j])<epsilon) data[i][j]=0;
			}

#pragma omp parallel for
	for(int j=0;j<n;j++)
		if(j!=c)
			data[r][j] /= d;

#pragma omp parallel for
	for(int i=0;i<m;i++)
		if(i!=r)
			data[i][c] = 0;

	 data[r][c] = 1;
}