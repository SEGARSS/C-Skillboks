﻿#include<iostream>
using namespace std;

/*Задача 3
Что нужно сделать
Напишите рекурсивную функцию, которая принимает большое число n типа long long и переменную ans, 
а возвращает void. После завершения работы функции в переменной ans должно оказаться количество чётных цифр в записи числа n.*/

//--------------------------------------------------------------------------------------
void evendigits(long long n, int &ans) // Рекурсивная функция для подсчета количества четных цифр в числе
{
	// Базовый случай: если n равно 0, завершаем рекурсию
	if (n == 0)
	{
		return;
	}

	// Рекурсивный случай: проверяем последнюю цифру числа на четность
	// Если чётная, увеличиваем счетчик чётных цифр
	if ((n % 10) % 2 == 0)
	{
		ans++;
	}

	// Вызываем рекурсивно функцию для оставшейся части числа без последней цифры
	evendigits(n / 10, ans);
}
//--------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	long long n;

	cout << "Введите число: ";
	cin >> n;

	int ans = 0;
	evendigits(n, ans);

	cout << "Количество чётных цифр в числе: " << ans << endl;

	return 0;
}
//--------------------------------------------------------------------------------------