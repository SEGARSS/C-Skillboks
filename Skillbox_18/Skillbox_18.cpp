#include <iostream>
using namespace std;

/*������ 2. ��������.
������������ ��������� ����� ������� ������. 
�� �������� ����� �������� ������ ������ �� 100 ������, 
� ������������ ����� ������ � 100 000 ������.

�������� ���������, 
������� ��������� ������������ ����� �������, 
��������� �������������.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int amount;
	cout << "������� �����:"; cin >> amount;

	if (amount <= 0)
		return 0;

	if (amount % 100 == 0 && amount <= 100000) // ���� 100 ��������� �������� ��� �����
	{
		std::cout << "������" << std::endl;
	}
	else
	{
		std::cout << "������: ������ ���� ������ 100 � �� ��������� ����� � 100 ���.�" << std::endl;
	}
	return 0;
}

