﻿#include<iostream>
using namespace std;

/*Напишите программу, которая по трем введенным числам a, b, c определяет, 
сколько среди них совпадающих чисел.

Подсказка: Совпадающих может быть 0, 2 или 3. 
Например, если введены числа 5 1 5, то ответ должен быть “2 совпадающих”, 
если -1 -2 -3, то ответ должен быть “0 совпадающих”.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int a, b, c;
	cout << "Введи 3 числа через пробел для и сравнения: ";
	cin>>a>>b>>c;

	if (a == b && b == c)
	{
		cout << "Совпадающих чисел 3." << endl;
	}
	else if (a == b || b == c || c == a)
	{
		cout << "Совпадающих чисел 2." << endl;
	}
	else
	{
		cout << "Совпадающих чисел 0." << endl;
	}

	return 0;
}