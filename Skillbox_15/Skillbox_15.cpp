#include<iostream>
using namespace std;

/*������� 7. ���� ���������
��� ����� �������
�������� ���������, ������� ������� ���� ������-����� ��������� � ����������� �� ��� ������. 
� ���� ���� ����� �����, � ���� ����������, ������� ������� �� ��� ������. 
������������ ������ ������ ����� ��� ������ � �� 1 (�����������) �� 7 (�����������), 
� ��������� ������ ������� �� ����� ���� ������ � ���� ����� ���.

������ 1

������� ���� ������ (�� 1 �� 7): 4 
���� ������� (�������): 
��������� ��� 
����� �������� � ���������� 
������� ����� � ���� 
����

������ 2

������� ���� ������ (�� 1 �� 7): 2
���� ������� (�������):
�����
����� �������
��������� �������� � ��������
����

��� �����������
����������� ������������� �������� ����������.
�������������� ��������� ����������������� �����.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int day;
	cout << "������� ���� ������ (�� 1 �� 7): ";
	cin >> day;
	if (day == 1)
	{
		cout << "���� ������� (�����������):\n";
		cout << "��� �������\n";
		cout << "����� �� ������ ������\n";
		cout << "������ ��-����������\n";
		cout << "������ �� ����\n";
	}
	else if (day == 2)
	{
		cout << "���� ������� (�������):\n";
		cout << "�����\n";
		cout << "����� �������\n";
		cout << "��������� �������� � ��������\n";
		cout << "����\n";
	}
	else if (day == 3)
	{
		cout << "���� ������� (�����):\n";
		cout << "����\n";
		cout << "����� �� ������ ������\n";
		cout << "������� ��-�������\n";
		cout << "������ �� ����\n";
	}
	else if (day == 4)
	{
		cout << "���� ������� (�������):\n";
		cout << "��������� ���\n";
		cout << "����� �������� � ����������\n";
		cout << "������� ����� � ����\n";
		cout << "����";
	}
	else if (day == 5)
	{
		cout << "���� ������� (�������):\n";
		cout << "��� � �������������\n";
		cout << "����� �� ������ ������\n";
		cout << "����� �� �������� � �������� �������\n";
		cout << "������ �� ����\n";
	}
	else if (day == 6)
	{
		cout << "���� ������� (�������):\n";
		cout << "�������\n";
		cout << "����� �������\n";
		cout << "������ �����\n";
		cout << "����\n";
	}
	else if (day == 7)
	{
		cout << "���� ������� (�����������):\n";
		cout << "��\n";
		cout << "����� �� ������ ������\n";
		cout << "������ �� �������\n";
		cout << "������ �� ����\n";
	}
	else

	{
		cout << "������: �������� ����� ��� ������!\n";
	}
}