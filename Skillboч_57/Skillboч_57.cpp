#include<iostream>
#include <cassert>
using namespace std;

/**/

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