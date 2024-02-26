#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*Задание 4. Реализация симуляции банкомата
Что нужно сделать
Требуется реализовать упрощённую симуляцию работы банкомата. 
В банкомате могут храниться только бумажные купюры номиналом от 100 до 5000 рублей. 
Максимально в банкомате может храниться только 1000 купюр. Все они записываются в отдельный файл. 
У банкомата, как у устройства, две основных операции — снятие денег пользователем и наполнение деньгами инкассаторами банка.

Наполнение банкомата происходит, если при старте программы в консоль вводится символ плюс “+”. 
Количество купюр рассчитывается так, чтобы банкомат был заполнен полностью. Все купюры при этом выбираются случайным образом.
Если на старте программы в консоль вводится минус (“-”), то симулируется снятие пользователем денег. 
Пользователь указывает сумму с точностью до 100 рублей. Мы будем считать, 
что каждый клиент обладает неограниченным балансом в системе и теоретически может снять любую сумму. 
На практике, если данная сумма не может быть снята из-за отсутствия подходящих денег в машине, показывается сообщение, 
что эта операция невозможна.
После выполнения любой из операций программа завершает выполнение. 
Состояние банкомата должно храниться в отдельном бинарном файле, автономно.*/

// Максимальное количество купюр в банкомате
const int MAX_NOTES = 1000;
// Допустимые номиналы купюр
const int VALID_DENOMINATIONS[] = { 100, 200, 500, 1000, 2000, 5000 };
const int NUM_DENOMINATIONS = sizeof(VALID_DENOMINATIONS) / sizeof(VALID_DENOMINATIONS[0]);

//-----------------------------------------------------------------------------------
struct Note// Структура, представляющая купюру
{
	int denomination;
};
//-----------------------------------------------------------------------------------
void fillATM()// Функция для наполнения банкомата случайными купюрами
{
	ofstream atmFile("atm.bin", ios::binary);
	if (!atmFile)
	{
		cerr << "Ошибка открытия файла." << endl;
		exit(1);
	}

	srand(time(nullptr));

	int totalNotes = 0;
	while (totalNotes < MAX_NOTES)
	{
		int denomination = VALID_DENOMINATIONS[rand() % NUM_DENOMINATIONS];
		Note note = { denomination };
		atmFile.write(reinterpret_cast<const char*>(&note), sizeof(Note));
		totalNotes++;
	}

	atmFile.close();
}
//-----------------------------------------------------------------------------------
void withdrawMoney(int amount)// Функция для снятия денег из банкомата
{
	ifstream atmFile("atm.bin", ios::binary);
	if (!atmFile)
	{
		cerr << "Ошибка открытия файла." << endl;
		exit(1);
	}

	ofstream tempFile("temp.bin", ios::binary);
	if (!tempFile)
	{
		cerr << "Ошибка открытия файла." << endl;
		exit(1);
	}

	Note note;
	int remainingAmount = amount;
	bool success = true;

	while (remainingAmount > 0 && atmFile.read(reinterpret_cast<char*>(&note), sizeof(Note)))
	{
		if (note.denomination <= remainingAmount)
		{
			remainingAmount -= note.denomination;
		}
		else
		{
			tempFile.write(reinterpret_cast<const char*>(&note), sizeof(Note));
		}
	}

	if (remainingAmount > 0)
	{
		cout << "Невозможно выполнить операцию. Недостаточно средств в банкомате." << endl;
		success = false;
	}

	atmFile.close();
	tempFile.close();

	if (success)
	{
		remove("atm.bin");
		rename("temp.bin", "atm.bin");
		cout << "Операция выполнена успешно. Сумма " << amount << " руб. была снята." << endl;
	}
	else
	{
		remove("temp.bin");
	}
}
//-----------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "Ru");

	char operation;
	cout << "Введите операцию (+ для наполнения, - для снятия): ";
	cin >> operation;

	if (operation == '+')
	{
		fillATM();
		cout << "Банкомат успешно наполнен." << endl;
	}
	else if (operation == '-')
	{
		int amount;
		cout << "Введите сумму для снятия (кратно 100): ";
		cin >> amount;

		if (amount % 100 == 0)
		{
			withdrawMoney(amount);
		}
		else
		{
			cout << "Неверная сумма. Сумма должна быть кратна 100 рублям." << endl;
		}
	}
	else
	{
		cout << "Неверная операция." << endl;
	}

	return 0;
}
//-----------------------------------------------------------------------------------