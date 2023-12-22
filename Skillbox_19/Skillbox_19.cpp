#include <iostream>
using namespace std;

/*Задача 3. Високосный год (необязательная). 

Напишите программу, которая определяет количество дней в году.
Подсказка: номер года должен делиться на 4, 
однако если он делится на 100, но не делится на 400, то год не високосный!*/

int main()
{
	setlocale(LC_ALL,"ru");

	int year;
	cout << "Впишите год:"; cin >> year;

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

