#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	map<string, string> phonebook;

	cout << "Добро пожаловать в телефонный справочник!" << endl;

	while (true) 
	{
		cout << "\nВыберите действие:" << endl;
		cout << "1. Добавить номер и абонента" << endl;
		cout << "2. Узнать фамилию абонента по номеру телефона" << endl;
		cout << "3. Узнать номера телефонов по фамилии абонента" << endl;
		cout << "4. Выйти из программы" << endl;

		int choice;
		cout << "Ваш выбор: ";
		cin >> choice;

		if (choice == 1) 
		{
			string lastName, phoneNumber;
			cout << "Введите фамилию абонента: ";
			cin >> lastName;
			cout << "Введите номер телефона: ";
			cin >> phoneNumber;
			phonebook[phoneNumber] = lastName;
			cout << "Номер и абонент успешно добавлены в справочник." << endl;
		}
		else if (choice == 2) 
		{
			string phoneNumber;
			cout << "Введите номер телефона: ";
			cin >> phoneNumber;

			if (phonebook.find(phoneNumber) != phonebook.end() ) 
			{
				cout << "Фамилия абонента: " << phonebook[phoneNumber] << endl;
			}
			else 
			{
				cout << "Номер телефона не найден в справочнике." << endl;
			}
		}
		else if (choice == 3) 
		{
			string lastName;
			cout << "Введите фамилию абонента: ";
			cin >> lastName;

			bool found = false;

			for (const auto& entry : phonebook) 
			{
				if (entry.second == lastName) 
				{
					cout << "Номер телефона: " << entry.first << endl;
					found = true;
				}
			}
			if (!found) 
			{
				cout << "Абонент с указанной фамилией не найден в справочнике." << endl;
			}
		}
		else if (choice == 4) 
		{
			cout << "Спасибо за использование телефонного справочника. До свидания!" << endl;
			break;
		}
		else 
		{
			cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
		}
	}

	return 0;
}
