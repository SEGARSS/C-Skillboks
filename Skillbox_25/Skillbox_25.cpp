#include<iostream>
#include<string>

using namespace std;

/*Задание 1. Полёт нормальный!
Что нужно сделать
Напишите программу для аэропорта, проверяющую, правильным ли эшелоном летит самолёт. 

Условие:
скорость самолёта должна быть в диапазоне от 750 до 850 км/ч;
высота — в диапазоне от 9 000 до 9 500 метров.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int speed;
	int height;
	string boing = "Боинг 747";

	cout << "Какая на данный момент скорость " << boing << ": ";
	cin>>speed;

	cout << "Какая на данный момент высота " << boing << ": ";
	cin>>height;

	if (speed >= 750 && speed <= 850 && height >= 9000 && height <= 9500)
	{
		cout << boing << " летит правильным эшелоном." << endl;
	}
	else
	{
		cout << boing << " сбился с курса." << endl;
	}
	return 0;
}