#include<iostream>
#include<string>
using namespace std;

/*���������� ��������� �� �������� ������, ��������� ���� for. 
� ���������� ��������� �����. �������� ���������, ������� ������� �� ����� �������� �����. 
� ������ � ���������� ����������, ������� ����� ��� ����� �������, 
����� ������ ���������� ��� ������ ������ ����� � � ����� ������� ������������ �����.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int che;
	cout << "������� ����� �� ������ �������? ";
	cin>>che;

	int sum = 0;
	int itog = 0;

	for (int i = 0; i < che; i++)
	{
		cin>>sum;
		itog +=sum;
	}

	cout << "����� �������� ����� ����� ����� - " << itog << endl;

	return 0;
}