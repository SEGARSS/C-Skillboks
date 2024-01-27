#include<iostream>
#include <cassert>
using namespace std;

/*Задание 3. Использование assert

Что нужно сделать:
Создайте в своей программе функцию float travelTime(float distance, float speed). 
Она будет находить время в пути и при этом использовать assert, чтобы отбросить нулевую и отрицательную скорость. 
Вызовите эту функцию в main. Убедитесь, что падение происходит за счёт assert. 
Не забудьте подключить заголовочный файл cassert.*/

float travelTime(float distance, float speed) 
{
	// Используем assert для проверки условия перед вычислением времени в пути
	assert(speed > 0); // Скорость должна быть положительной

	return distance / speed;
}

int main() 
{
	setlocale(LC_ALL,"ru");

	float distance, speed;

	cout << "Введите расстояние (в км): ";
	cin >> distance;

	cout << "Введите скорость (в км/ч): ";
	cin >> speed;

	// Вызываем функцию с использованием assert
	float time = travelTime(distance, speed);

	cout << "Время в пути: " << time << " часов" << endl;

	return 0;
}