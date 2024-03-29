﻿#include <iostream>
#include <cmath>

using namespace std;

/*Задание 6. Маятник
Что нужно сделать
Известно, что амплитуда качающегося маятника с каждым разом затухает на 8,4% от амплитуды прошлого колебания. 
Если качнуть маятник, он, строго говоря, никогда не остановится: его амплитуда будет уменьшаться до тех пор, 
пока мы не сочтём такой маятник остановившимся. Напишите программу, определяющую, сколько раз качнётся маятник, 
прежде чем он, по нашему мнению, остановится. 
Программа получает на вход начальную амплитуду колебания в сантиметрах и конечную амплитуду его колебаний, 
которая считается остановкой маятника. Обеспечьте контроль ввода.
Рекомендации по выполнению
Считаем, что затухание происходит на каждое качание.*/

int main() 
{
	setlocale(LC_ALL, "ru");

	double initialAmplitude, finalAmplitude;
	const double dampingFactor = 0.084;  // Коэффициент затухания

	// Ввод начальной и конечной амплитуды
	cout << "Введите начальную амплитуду (в см): ";
	cin >> initialAmplitude;

	cout << "Введите конечную амплитуду (в см), при которой маятник считается остановившимся: ";
	cin >> finalAmplitude;

	// Проверка валидности ввода
	if (initialAmplitude <= 0 || finalAmplitude <= 0 || finalAmplitude >= initialAmplitude) 
	{
		cerr << "Ошибка ввода. Пожалуйста, введите корректные значения." << endl;
		return 1;  // Возврат кода ошибки
	}

	// Определение количества затуханий
	int oscillations = 0;
	while (initialAmplitude > finalAmplitude) 
	{
		initialAmplitude *= (1 - dampingFactor);
		oscillations++;
	}

	// Вывод результата
	cout << "Маятник считается остановившимся после " << oscillations << " затуханий." << endl;

	return 0;
}