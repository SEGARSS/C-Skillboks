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

	if (year % 100 == 0)
	{
		if (year % 400 == 0)
			std::cout << "Yes" << std::endl;
		else
			std::cout << "No" << std::endl;
	}
	else if (year % 4 == 0)
	{
		std::cout << "Yes" << std::endl;
	}

	return 0;
}

