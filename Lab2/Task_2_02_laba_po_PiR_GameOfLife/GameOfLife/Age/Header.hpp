#include <iostream>
#include <windows.h>

// ������ ������ CRT ������� ����� �����, ����� ���������� ������. ���� ���������� ������� ����������, �� ������ ����� ���������� ������ �������� ��� ���������������, � ����� ������ ����� ������� _s ("secure" � "����������").
// � ���� ��������� "�� �������������" �������� ������ ��, ��� ������������� ���� ������� �� �������������; ��� �� ��������, ��� ������� ����������� ������� �� CRT.
// ���������� ������� �� ������������� ��� ���������� ������ ������������; ������ ����� ��� ������������� ������ ��� �� �������������. ��� ��������� �������������� �������� �� ���������� ������� ������������� ������, � � ������ ������ �������� ���������� ������ (��. �������� ����������).
// ���������� ��������� �������� �������� �������������� � ��������������� �������� ��� ������ ����� ���������� �������. ����� ������� � ������� _CRT_SECURE_NO_WARNINGS ��� ������������ ��������� pragma warning. �������������� � ��������������� �������� ����� ���������, ��, ����������, ���� �������� ������������, ������� ������� ��� ��������������, ���������. ������� ����� �������� �������������� � ��������������� �������� ����������� � ������������ ����� ���������� ������� CRT.
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

//��������� ������ (��� ������)
#define LIFE	219
#define DIE		'.'

//��������� ����
#define WIDTH 	6
#define HEIGHT  6

//�������� ����� ����������� ����
#define DELAY	1000

//������������ ������� ����� ������
#define MAX_AGE 5

//��������� ������
typedef struct cell
{
	bool currentState;
	int age;
}cell;

//����� ��������� ������
bool newState(const bool oldState, const int neighborCnt);

//���������� ����
bool newField(cell field[WIDTH][HEIGHT]);

//������ ����
void printField(const cell field[WIDTH][HEIGHT]);