#include "Header.hpp"
using namespace std;

/********************************************************
��������� ��������� �������
vector - ��������� �� ������
count - ���������� ���������
*********************************************************/
void clear(int *vector, int count)
{
#pragma omp parallel for
	for(int i=0;i<count;i++)
		vector[i]=0;
}
/********************************************************
����� ��������� ��������� ��������� �������
vector - ��������� �� ������
count - ���������� ���������
*********************************************************/
int sum(int *vector, int count)
{
	int s=0;
	for(int i=0;i<count;i++)
		s+=vector[i];
	return s;
}
/********************************************************
������ �������� AND ��������� �������� ��������
vector1 - ��������� �� ������
vector2 - ��������� �� ������
result - ��������� �� ������
count - ���������� ���������
*********************************************************/
void and(int *vector1, int *vector2,int *result,  int count)
{
#pragma omp parallel for
	for(int i=0;i<count;i++)
		result[i]=vector1[i]&vector2[i];
}
/********************************************************
������ �������� OR ��������� �������� ��������
vector1 - ��������� �� ������
vector2 - ��������� �� ������
result - ��������� �� ������
count - ���������� ���������
*********************************************************/
void or(int *vector1, int *vector2,int *result,  int count)
{
#pragma omp parallel for
	for(int i=0;i<count;i++)
		result[i]=vector1[i]|vector2[i];
}
/********************************************************
������ �������� XOR ��������� �������� ��������
vector1 - ��������� �� ������
vector2 - ��������� �� ������
result - ��������� �� ������
count - ���������� ���������
*********************************************************/
void xor(int *vector1, int *vector2,int *result,  int count)
{
#pragma omp parallel for
	for(int i=0;i<count;i++)
		result[i]=vector1[i]^vector2[i];
}
/********************************************************
������ �������� SUB ��������� �������� ��������
vector1 - ��������� �� ������
vector2 - ��������� �� ������
result - ��������� �� ������
count - ���������� ���������
*********************************************************/
void sub(int *vector1, int *vector2,int *result,  int count)
{
#pragma omp parallel for
	for(int i=0;i<count;i++)
		result[i]=vector1[i]&(vector1[i]^vector2[i]);
}

