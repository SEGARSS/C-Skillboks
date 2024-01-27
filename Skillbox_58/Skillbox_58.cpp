﻿#include <iostream>
#include <cmath>
using namespace std;

/*Задание 1. Космический симулятор
Что нужно сделать
Вы пишете симулятор космических полётов. 
Ваш звездолёт массой m килограмм включает двигатель с силой тяги F ньютонов на t секунд. 
Напишите программу, которая по заданным F, m и t покажет, 
на каком расстоянии от первоначального положения окажется космический корабль через t секунд. 
Обеспечьте контроль ввода.
Примечание: космический корабль находится в открытом космосе.*/

int main()
{
	setlocale(LC_ALL, "ru");

	float F, m, t;

	// Ввод данных с обработкой ошибок
	cout << "Введите силу тяги F (ньютон): ";
	while (!(std::cin >> F) || F < 0)
	{
		cout << "Ошибка ввода. Введите положительное значение F: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	cout << "Введите массу звездолета m (килограмм): ";
	while (!(std::cin >> m) || m <= 0)
	{
		cout << "Ошибка ввода. Введите положительное значение m: ";
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}

	cout << "Введите время работы двигателя t (секунд): ";
	while (!(std::cin >> t) || t < 0)
	{
		cout << "Ошибка ввода. Введите положительное значение t: ";
		cin.clear();
		cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	}

	// Расчет расстояния
	const float g = 9.8; // ускорение свободного падения на Земле
	float distance = 0.5 * F / m * pow(t, 2);

	// Вывод результата
	cout << "Космический корабль окажется на расстоянии " << distance << " метров от начального положения." << endl;

	return 0;
}