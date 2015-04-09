#include <iostream>
#include <windows.h>

using namespace std;

//��������� ������ (��� ������)
#define LIFE	219
#define DIE		'.'

//��������� ����
#define WIDTH 	4
#define HEIGHT 	3
#define DEPTH	3

//�������� ����� ����������� ����
#define DELAY	1000

//����� ��������� ������
bool newState(const bool oldState, const int neighborCnt);

//���������� ����
bool newField(bool field[WIDTH][HEIGHT][DEPTH]);

//������ ����
void printField(const bool field[WIDTH][HEIGHT][DEPTH]);
