﻿#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*Задание 4. Умножение матрицы на вектор
Реализуйте частный случай умножения матрицы на матрицу, а именно умножение вектора на матрицу. 
Эта операция распространена в компьютерной индустрии в целом и в компьютерной графике в частности, поэтому это будет хорошим упражнением.
Итак, у нас есть четырёхкомпонентный вектор b, представленный с помощью массива, и матрица a размером 4 × 4, 
представленная в виде двумерного массива. Их произведением будет новый четырёхэлементный вектор c. 
Его компоненты будут суммой произведений элемента вектора b на строку матрицы a. 
Индекс столбца при этом равен индексу соответствующей компоненты вектора b, который мы и рассчитываем.
Все входные данные, матрица a и вектор b вносятся из пользовательского ввода. Итоговый вектор c надо вывести в консоль (std::cout). 
Тип данных элементов — всегда float. Желательно реализовать этот алгоритм с помощью вложенного цикла на умножение колонки.*/

//------------------------------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "ru");

	const int size = 4;

	// Ввод матрицы a
	vector<vector<float>> matrixA(size, vector<float>(size));

	cout << "Введите матрицу a (" << size << "x" << size << "):" << endl;

	for (int i = 0; i < size; ++i) 
	{
		for (int j = 0; j < size; ++j) 
		{
			cin >> matrixA[i][j];
		}
	}

	// Ввод вектора b
	vector<float> vectorB(size);
	cout << "Введите вектор b (4-х компонентный):" << endl;
	for (int i = 0; i < size; ++i) 
	{
		cin >> vectorB[i];
	}

	// Вычисление результирующего вектора c
	vector<float> vectorC(size, 0.0);

	for (int i = 0; i < size; ++i) 
	{
		for (int j = 0; j < size; ++j) 
		{
			vectorC[i] += matrixA[i][j] * vectorB[j];
		}
	}

	// Вывод результата
	cout << "Результирующий вектор c:" << endl;
	for (int i = 0; i < size; ++i) 
	{
		cout << vectorC[i] << " ";
	}
	cout << endl;

	return 0;
}
//------------------------------------------------------------------------------------------------------------------------