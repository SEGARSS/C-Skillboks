﻿#include<iostream>
#include<string>

using namespace std;

/*Задание 3. Майские — усложнение
Что нужно сделать
В предыдущем задании вы написали программу-календарь для мая. 
Теперь добавьте возможность начать месяц с любого дня недели. 

Для этого нужно ввести число — номер дня недели, с которого начинается месяц. 
Убедитесь, что введённое число корректно.

Советы и рекомендации
Для начала выполните задание 2.
Постарайтесь не проверять каждый вариант месяца отдельно. 
Некоторые условия можно объединить.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int start_day;
	cout << "Введите номер дня недели, с которого начинается месяц (0 - пн, 1 - вт, ..., 6 - вс): ";
	cin >> start_day;

	if (start_day < 0 || start_day > 6) 
	{
		cout << "Ошибка: неверный номер дня недели!" << endl;
		return 0;
	}
	
	for (int day = 1; day <= 31; day++) 
	{
		int weekday = (day + start_day) % 7; // вычисляем день недели

		if (weekday == 5 || weekday == 6 || day <= 5 || (day >= 8 && day <= 10) ) 
		{
			cout << day << " - выходной день" << endl;
		}
		else 
		{
			cout << day << " - рабочий день" << endl;
		}
	}

	return 0;
}
/*Дорешай*/