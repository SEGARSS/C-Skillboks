#include<iostream>
#include<string>
using namespace std;

/*������� 5. ������������ ���
��� ����� �������
������������� ������ � ������������� ����� ���, 
����� � ����� �� ����������� ��������� ���� �+�, 
�� ������� ����� ������������ ��� ���� ������� ����� �^�, 
� �� ������ ����� �������������� ��� � ������� ������ �>�. 
��� ������� ������� ����� �������� � ������.*/

int main()
{
	setlocale(LC_ALL, "ru");

	int size;
	cout << "������� ������ �������: ";
	cin >> size;

	// ������ ������� �����
	cout << "+";
	for (int i = 0; i < size; i++)
	{
		cout << "-";
	}
	cout << ">" << endl;

	// ������ ������������ ��� � �����
	for (int y = size; y >= -size; y--)
	{
		cout << "|";
		for (int x = -size; x <= size; x++)
		{
			if (x == 0 && y == 0)
			{
				cout << "+";
			}
			else if (x == 0 && y > 0)
			{
				cout << "^";
			}
			else if (x > 0 && y == 0)
			{
				cout << ">";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "|" << endl;
	}

	// ������ ������ �����
	cout << "+";
	for (int i = 0; i < size; i++)
	{
		cout << "-";
	}
	cout << ">" << endl;

	return 0;
}