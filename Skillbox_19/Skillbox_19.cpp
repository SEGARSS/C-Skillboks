#include <iostream>
using namespace std;

/*������ 3. ���������� ��� (��������������). 

�������� ���������, ������� ���������� ���������� ���� � ����.
���������: ����� ���� ������ �������� �� 4, 
������ ���� �� ������� �� 100, �� �� ������� �� 400, �� ��� �� ����������!*/

int main()
{
	setlocale(LC_ALL,"ru");

	int year;
	cout << "������� ���:"; cin >> year;

	if (year <= 0)
		return 0;

	if (year % 100 == 0 && year % 400 == 0 && year % 4 == 0)
	{
		cout << "Yes" << std::endl;
	}
	else
	{
		cout << "No" << std::endl;
	}

	return 0;
}

