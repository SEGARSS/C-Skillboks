﻿#include<iostream>
#include<string>

using namespace std;

/*Задание 2. Майские!
Что нужно сделать
Напишите программу-календарь для мая. 
Она должна проверять введённый номер дня и сообщать, 
выходной этот день или рабочий. 

Условие:
Выходными считаются все субботы и воскресенья, 
а также даты с 1 по 5 и с 8 по 10 мая включительно. 
Месяц всегда начинается с понедельника.
Советы и рекомендации
Постарайтесь не проверять каждое число отдельно. 
Некоторые условия можно объединить.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int day;
	cout << "Введите номер дня: ";
	cin >> day;

	if (day < 1 || day > 31) 
	{
		cout << "Ошибка: неверный номер дня!" << endl;
		return 0;
	}

	int weekday = (day + 4) % 7;

	if (weekday == 5 || weekday == 6 || day <= 5 || (day >= 8 && day <= 10) ) 
	{
		cout << "Это выходной день" << endl;
	}
	else 
	{
		cout << "Это рабочий день" << endl;
	}

	return 0;
}