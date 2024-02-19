#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

/*Задание 3. Реализация программы чтения ведомости
Что нужно сделать
Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет собой следующую таблицу:
• имя и фамилия человека;
• количество денег, которые были выплачены лицу;
• дата выплаты в формате ДД.ММ.ГГГГ.*/

//-----------------------------------------------------------------------------------
struct Payment
{
	string fullName;
	string sorrName;
	double amount;
	string date;
};
//-----------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "ru");

	ifstream file("payments.txt");

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла." << endl;
		return 1;
	}

	// Вывод содержимого файла
	cout << "Содержимое ведомости:" << endl;
	cout << "---------------------" << endl;
	string line;
	while (getline(file, line))
	{
		cout << line << endl;
	}
	cout << "---------------------" << endl;
	cout << endl;

	// Второй проход для анализа данных и вывода результата
	file.clear();           // Сброс флагов ошибок файла
	file.seekg(0, ios::beg); // Возврат к началу файла

	double totalPayments = 0.0;
	Payment maxPayment;
	bool isFirstPayment = true;

	while (getline(file, line))
	{
		istringstream iss(line);
		Payment payment;
		iss >> payment.fullName >> payment.sorrName >> payment.amount >> payment.date;

		totalPayments += payment.amount;

		if (isFirstPayment || payment.amount > maxPayment.amount)
		{
			maxPayment = payment;
			isFirstPayment = false;
		}
	}

	file.close();

	cout << "Общая сумма выплат: $" << fixed << setprecision(2) << totalPayments << endl;
	cout << "Человек с максимальной суммой выплат:" << endl;
	cout << "Имя и фамилия: " << maxPayment.fullName << " " << maxPayment.sorrName << endl;
	cout << "Сумма выплат: $" << fixed << setprecision(2) << maxPayment.amount << endl;
	cout << "Дата выплаты: " << maxPayment.date << endl;

	return 0;
}
//-----------------------------------------------------------------------------------