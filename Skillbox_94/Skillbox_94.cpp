﻿#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*Задание 1. Реализация записи в ведомость учёта
Что нужно сделать
В одном из прошлых заданий мы уже создавали программу чтения и анализа ведомости выплат. 
Теперь требуется создать простую программу записи в эту ведомость.
Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, 
далее располагается дата выдачи в формате ДД.ММ.ГГГГ. Завершает запись сумма выплаты в рублях. 
Данные разделяются между собой пробелами. В конце каждой записи должен быть расположен перевод строки.
При старте программы пользователь последовательно вводит данные для новой записи, 
которые записываются затем в файл в текстовом режиме. Программа должна добавлять новые записи в конец файла, 
не удаляя его текущее содержимое.
Советы и рекомендации
Введённые данные рекомендуется хотя бы минимально валидировать перед их записью.
Для валидации даты в указанном формате можно использовать функции std::stoi и std::subtr 
с корректно указанным диапазоном символов в дате. 
К примеру, вызов std::stoi(date.substr(3, 2)) вычленит из строковой даты целочисленный месяц для последующего анализа.
Что оценивается
Корректность работы программы. Программа должна дозаписывать данные в конец существующего списка.*/

//-----------------------------------------------------------------------------------
void addRecordToFile(const string& filename, const string& record)
{
	ofstream file(filename, ios::app); // Открываем файл для добавления в конец
	if (file.is_open())
	{
		file << record << endl; // Добавляем запись в файл
		cout << "Запись успешно добавлена в ведомость." << endl;
	}
	else
	{
		cout << "Ошибка открытия файла." << endl;
	}
}
//-----------------------------------------------------------------------------------
void showRecords(const string& filename)
{
	ifstream file(filename);
	if (file.is_open())
	{
		string line;
		cout << "Содержимое ведомости:" << endl;
		while (getline(file, line))
		{
			cout << line << endl; // Выводим каждую строку ведомости
		}
		file.close();
	}
	else
	{
		cout << "Ошибка открытия файла." << endl;
	}
}
//-----------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "ru");
	string filename = "vedomost.txt"; // Имя файла ведомости
	string name, date;
	double amount;

	// Ввод данных для новой записи
	cout << "Введите имя и фамилию получателя денежных средств: ";
	getline(cin, name);
	cout << "Введите дату выдачи в формате ДД.ММ.ГГГГ: ";
	getline(cin, date);
	cout << "Введите сумму выплаты в рублях: ";
	cin >> amount;

	// Проверка введенных данных (в данном примере не выполняется)
	// Можно добавить дополнительную валидацию

	// Формирование строки записи
	string record = name + " " + date + " " + to_string(amount);

	// Добавление записи в файл ведомости
	addRecordToFile(filename, record);

	// Показать содержимое ведомости
	showRecords(filename);

	return 0;
}
//-----------------------------------------------------------------------------------