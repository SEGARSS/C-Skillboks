#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*1. Ведомость учёта
Что нужно сделать
Вы уже создавали программу чтения и записи ведомости. Теперь её нужно обобщить и дополнить использованием структур.
Формат ведомости прежний:
• сначала — имя и фамилия получателя денег,
• далее — дата выдачи в формате ДД.ММ.ГГГГ,
• затем — сумма выплаты в рублях.
Данные разделяются пробелами. 
В конце каждой записи должен быть перевод строки. Структура данных должна соответствовать этому формату.

При старте программы пользователь отправляет команду: list или add. Команда list осуществляет чтение из файла ведомости, 
как и прежде, только уже в структуры данных, и отображает их на экране.
Команда add добавляет новую запись в конец ведомости.*/

//-----------------------------------------------------------------------------------
struct Payment // Структура для хранения информации о выплате
{
	string fullName;
	string sorrName;
	double amount;
	string date;
};
//-----------------------------------------------------------------------------------
void printPayment(const Payment& payment) // Функция для вывода информации о выплате
{
	cout << "Имя: " << payment.fullName << endl;
	cout << "Фамилия: " << payment.sorrName << endl;
	cout << "Дата: " << payment.date << endl;
	cout << "Сумма: " << payment.amount << " руб." << endl;
}
//-----------------------------------------------------------------------------------
vector<Payment> readPayments(const string& filename) // Функция для чтения ведомости из файла
{
	vector<Payment> payments;
	ifstream file(filename);

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла." << endl;
		return payments;
	}

	Payment payment;
	while (file >> payment.fullName >> payment.sorrName >> payment.date >> payment.amount)
	{
		payments.push_back(payment);
	}

	file.close();
	return payments;
}
//-----------------------------------------------------------------------------------
void addPayment(const string& filename, const Payment& payment) // Функция для записи новой выплаты в файл ведомости
{
	ofstream file(filename, ios::app); // Открываем файл для дозаписи в конец

	if (!file.is_open())
	{
		cout << "Ошибка открытия файла." << endl;
		return;
	}

	file << payment.fullName << " " << payment.sorrName << " " << payment.date << " " << payment.amount << endl;

	file.close();
}
//-----------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "RU");

	string command;
	cout << "Введите команду (list или add): ";
	cin >> command;

	if (command == "list")
	{
		vector<Payment> payments = readPayments("payments.txt");
		cout << "Список выплат:" << endl;
		for (const Payment& payment : payments)
		{
			printPayment(payment);
			cout << endl;
		}
	}
	else if (command == "add")
	{
		Payment newPayment;
		cout << "Введите имя и фамилию: ";
		cin >> newPayment.fullName >> newPayment.sorrName;
		cout << "Введите дату (ДД.ММ.ГГГГ): ";
		cin >> newPayment.date;
		cout << "Введите сумму: ";
		cin >> newPayment.amount;

		addPayment("payments.txt", newPayment);
		cout << "Новая выплата успешно добавлена в ведомость." << endl;
	}
	else
	{
		cout << "Неверная команда." << endl;
	}

	return 0;
}
//-----------------------------------------------------------------------------------