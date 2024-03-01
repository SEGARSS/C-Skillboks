#include<iostream>
#include<string>
#include<map>


using namespace std;

/**/

int main()
{
	setlocale(LC_ALL,"ru");

	map<string, int> patients;
	string input;

	cout << "Добро пожаловать в регистратуру!" << endl;

	while (true)
	{
		cout << "Введите фамилию пациента или 'Next' для вызова следующего: ";
		cin >> input;

		if (input == "Next")
		{
			if (patients.empty() )
			{
				cout << "Очередь пустая." << endl;
			}
			else
			{
				auto it = patients.begin();
				cout << "" << it->first << " приглашен." << endl;
				it->second--;
				if (it->second == 0)
				{
					patients.erase(it);
				}
			}
		}
		else
		{
			patients[input]++;
			cout << "Пациент " << input << " добавлен в очередь." << endl;
		}
	}

	return 0;
}