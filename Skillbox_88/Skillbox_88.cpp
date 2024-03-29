﻿#include<iostream>
using namespace std;

/*Задача 2
Что нужно сделать:
Кролик сидит на нулевой ступеньке большой лестницы. Он может прыгать на одну или более ступенек вверх, но не далее чем на k. 
Кролик хочет допрыгать до n-й ступеньки, но может сделать это большим количеством способов.
Напишите рекурсивную функцию, которая принимает число n типа int и число k — максимальную длину прыжка, 
а возвращает количество способов, которым кролик может доскакать до n-й ступеньки. 
В функции для аргумента “максимальная длина прыжка” задать значение, по умолчанию равное 3.*/

//----------------------------------------------------------------
int coutWays(int n, int k = 3)
{
	if (n <= 1)
	{
		return 1;
	}

	int ways = 0;

	for (int i = 1; i <= k && n - i >= 0; i++)
	{
		ways += coutWays(n - i, k);
	}
	return ways;
}
//----------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	int n, k;

	cout << "Введите количество шагов (n): ";
	cin >> n;
	cout << "Введите максимальную длину прыжка (k): ";
	cin >> k;

	int ways = coutWays(n, k);
	cout << "Количество способов достижения шага " << n << " с максимальной длиной прыжка " << k << ": " << ways << endl;

	return 0;
}
//----------------------------------------------------------------