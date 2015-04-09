#include "Header.hpp"
using namespace std;

/********************************************************
����� ����� ��������������� 

����� ���������� �������������� ������� ����� ����������, 
������������� � ������ ��������������� ������� �� ��������� ������� �������, 
�� ���� ���������, �� ������ ������������ �������. 
���� ����������� ������ ��������������� �������, �� ����� ����� ����������� � ����������� ���������� 
������� ��� �������� ������������� �������� ��������� ����� ���������������, 
������ ������� ����� ������������ ����������� ����� ���������������� ��������� ������ 
��������������, � ������ � ��������� ��������������� ������� � ���� �����.

��� ������ ������ � ����� ��������������� ����������� ����������
E(f) = f'/2n * (b - a)^2.

������� ����� � ������� ������ ����������� ��������� �������, 
���� ���������� �. ����� � ������ 20 ����.[1]
�������� ���� (��� ������� �����-����� ������� ���) ������� � ���������� ����������� 
��������� ������� � ����� h, � ����� � ����� h/2, � ���������� ������������ ��������� 
������������ ��� ���� ���� ����������.

�������� ����������� �� ��������� ������� (���������������, ��������, ������� ��������) 
��� ����� �����, ������ n, � ����� ��� ����� �����, ������ 2n. 
����������� ���������� �������� ��������� ��� ����� �����, ������ 2n, 
������������ �� ������� �����:
Delta_{2n} = Theta * |I_{2n}-I_{n}|, ��� ������ ��������������� � �������� Theta = 1/3

*pf - ��������� �� ������� 
a,b - �������� ��������������
� - ��������
*********************************************************/
double integral(double (*pf)(double), double a, double b, double e, int demo){
	int nmin=10; // ����������� ����� ��������� ������� [a,b]
	double prev;
	double next;

	// ���������� ���������� �����������
	prev=0; 
	for(int i=0; i<nmin; i++) 
		prev+=(*pf)(a+i*(b-a)/nmin); 
	prev /= nmin;

	// ��������
	for(int n=nmin;;n++) {

		if(demo!=0) cout << "\t��� ��������:" << n << endl;

		if(demo!=0) cout << "\t���������� ��������:" << prev << endl;

		double *y=new double[n];

		// ������������ ������������ ��������� ��������� �������
		// ���������� �������������� ��������� ��� ����� (���), ��� �������, 
		// ��������� � ������  ���� (�������� ������������� ������) 
		// � ������������ ����� ���������� ��������� �� ���������� ������������ ��������� (��).
		// ������ ��, � ����������� �� ���� ���, ����� ��� �������� �������������� ������ ������� 
		// ��������, ��� � ������������� ���� ��� ��������, ������ �������� � ��������� ���������� 
		// �� ����� ��������������, � ����� ��������� �������� ������ ��� �������������� � ������� ��.
		// OpenMP ������������ ��������� parallel, for, parallel for, section, sections, single, master, critical, flush, ordered � atomic, 
		// ������� ���������� ��� ��������� ���������� ������ ��� ����������� �������������. 
		// ����� ���������� �������� ���� ������� �� ������, ������� ��������� ����� ���������� � ����� ������ ������ ������ ������� 
		// � ������������ �������. ��� �������� ������� ����������, �� ������ ����� �� ������ ����������� �� ���������� ������������, 
		// ������� ��������� ����� ���������� � ����� ������ ����� �� ����������� �� �� �����������, 
		// ������������� ������ �������.
		// �������� �������� ������� ������������ ������ for.

#pragma omp parallel for
		for(int i=0; i<n; i++) 
			y[i]=(*pf)(a+(2*i+1)*(b-a)/(2*n)); 

		// ������������ ��������� ������� �������������� ��������� ��� ������������ ����������
		// ������� ������������ �������������� ������
		next=0; 
		for(int i=0; i<n; i++) 
			next+=y[i]; 

		delete y;

		next = (next / (2*n)) + (prev/2);

		if(demo!=0) cout << "\t��������� ��������:" << next << endl;

		// ������� ����� � ������� ������ ����������� ��������� �������
		double delta=abs(next-prev)/3;

		if(demo!=0) cout << "\t��������� ��������:" << delta << endl;

		if(demo!=0) {
			cout << "\t������� ���� ��� �����������" << endl;
			getchar();
			getchar();
		}

		if(delta < e) break;

		prev=next;
	}
	return next;
}
