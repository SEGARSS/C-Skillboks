#include<iostream>
using namespace std;

/*������� 3. �������� �� ������ �����
��� ����� �������
�������� ���������, ������� ���������, ������ �� ����� ���� ������������.

������: int remainder = x % 2 (��������� ������� �� ������� `x` �� 2).

������

������� �����: 28 
-----���������----- 
����� 28 � ������

������ � ������������
��� �������� �������� ����������� �������� %. 
�� ��������� ������� �� ������� ���� �����.
�� �������� ��� ������������� �����.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int number;
	cout << "������� ������ ���� ����� ��� ���." << endl;
	cout << "����� (0) ������� ������!" << endl;

	cout << "������� �����: ";
	cin>>number;

	if (number % 2 == 0)
	{
		cout << "�����: " << number << " ������" <<endl;
	}
	else if (number < 0)
	{
		cout << "������� ������������� �����:" <<endl;
	}
	else
	{
		cout << "�����: " << number << " �� ������" <<endl;
	}
	
}