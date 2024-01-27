﻿#include <iostream>
#include <cmath>

using namespace std;

/*Задание 3. Игрушечная история

Что нужно сделать
Вы решили открыть бизнес по производству игровых деревянных кубиков для детей. 
Вы узнали, что лучше всего продаются кубики со стороной 5 см в наборах по несколько штук, 
причём кубиков в наборе должно быть достаточно, чтобы сложить из них один большой куб. 
Для изготовления кубиков к вам в мастерскую поступают деревянные бруски в форме прямоугольных параллелепипедов любых размеров.

Для оптимизации бизнес-процессов напишите программу, которая по заданным размерам исходного бруска определяет, 
сколько кубиков из него можно изготовить, можно ли из них составить набор для продажи и если можно, 
то максимальное число кубиков в этом наборе. Все кубики должны быть из цельного дерева без использования клея. 
Размеры бруска — вещественные числа. Обеспечьте контроль ввода.*/

int main() 
{
	setlocale(LC_ALL, "ru");

	const double min_cube_size = 5.0; // Минимальный размер кубика
	const int min_set_size = 8; // Минимальное количество кубиков в наборе

	cout << "Введите размеры бруска:" << endl;

	double x, y, z;
	cout << "X: ";
	cin >> x;

	cout << "Y: ";
	cin >> y;

	cout << "Z: ";
	cin >> z;

	// Проверка на минимальный размер бруска
	if (x < min_cube_size || y < min_cube_size || z < min_cube_size) 
	{
		cout << "Размеры бруска слишком маленькие для изготовления кубиков." << endl;
		return 1;
	}

	// Рассчитываем количество кубиков в каждом измерении
	int cubes_x = static_cast<int>(x / min_cube_size);
	int cubes_y = static_cast<int>(y / min_cube_size);
	int cubes_z = static_cast<int>(z / min_cube_size);

	// Рассчитываем общее количество кубиков
	int total_cubes = cubes_x * cubes_y * cubes_z;

	cout << "Из этого бруска можно изготовить " << total_cubes << " кубиков." << endl;

	// Рассчитываем максимальное количество кубиков в наборе
	int max_set_cubes = min(total_cubes, min_set_size);

	// Проверка на возможность составить набор
	if (max_set_cubes < min_set_size) 
	{
		cout << "Из этого бруска нельзя составить набор." << endl;
	}
	else 
	{
		cout << "Из них можно составить набор из " << max_set_cubes << " кубиков." << endl;
	}

	return 0;
}