#include<iostream>
#include<string>
using namespace std;

/*������ 2. ���� �����.

�������� ���������-��������� ����� ������. 
��� ���������� � ������������, ��� ��� �����, ����� �������� �%username%, ���� �����!�. 
������, ��� �� �� �� �������, ��� ��������������: ��� ������� �...�, � �� ���� �����!
��� ����������� ����������.

������
- ������, ����� �����.
- ��� ������� �������, ����� �����.�, � �� ���� �����!*/

int main()
{
	setlocale(LC_ALL,"ru");

	string username;

	cout << "��� ��� �����? ";
	getline(cin, username);

	cout << username << ", ���� �����!" << endl;

	while (true) 
	{
		string message;
		getline(cin, message);

		if (message == "exit") //���� �� ��������� ������ �������, ���� ����� �����������.
		{
        break; // ����� �� �����
		}

		cout << "��� ������� \"" << message << "\", � �� ���� �����!" << endl;
	}

	cout << "�� �������, ������ �� ���� ������!" << endl;

	return 0;
}