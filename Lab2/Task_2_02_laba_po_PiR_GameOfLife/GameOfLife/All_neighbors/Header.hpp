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
#define WIDTH 	4
#define HEIGHT 	4

//�������� ����� ����������� ����
#define DELAY	1000

//����� ��������� ������
bool newState(const bool oldState, const int neighborCnt);

//���������� ����
bool newField(bool field[WIDTH][HEIGHT]);

//������ ����
void printField(const bool field[WIDTH][HEIGHT]);
