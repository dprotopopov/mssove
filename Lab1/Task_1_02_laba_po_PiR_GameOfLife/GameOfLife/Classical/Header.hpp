#include <iostream>
#include <windows.h>

using namespace std;

//��������� ������ (��� ������)
#define LIFE	219
#define DIE		'.'

//��������� ����
#define WIDTH 	6
#define HEIGHT 	14

//�������� ����� ����������� ����
#define DELAY	1000

//����� ��������� ������
bool newState(const bool oldState, const int neighborCnt);

//���������� ����
bool newField(bool field[WIDTH][HEIGHT]);

//������ ����
void printField(const bool field[WIDTH][HEIGHT]);
