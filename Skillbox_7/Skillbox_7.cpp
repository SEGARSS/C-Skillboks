﻿#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL,"ru");

	/*Автомобиль выехал из Москвы в Рязань. 
	Напишите программу, 
	которая вычисляет сумеет ли добраться автомобиль 
	до Рязани за два часа с заданной пользователем средней скоростью движения. 
	Программа должна выводить вычисленное расстояние, 
	а если автомобиль сумеет добраться до Рязани, - сообщение “Вы приехали”. 
	Расстояние между городами - 200 км.*/

	int distance = 200;
	int speed;
	int time = 2;
	int passedDistance;

	cout << "Вы начали поездку на машине Москва - Рязань" << endl;
	cout << "Мы поможем вам определить время, которое вы потратите на дорогу." << endl;
	cout << "Скакой средней скорость машины вы предпочитаете ехать? Введите данные: ";
	cin >> speed;

	passedDistance = speed * time;

	if (passedDistance >= distance)
	{
		cout << "Вы приедете за меннее чем два часа или ровно за два часа." << endl;
	}
	else
	{
		cout << "Вы проедите данный маршрут за " << distance / speed << " час." << endl;
	}
}
/*Внёс свои изминения в задачу, тоесть добавил условие, что если за два часа не приедит,
то покажет сколько в итоге потратит время на маршрут в 200км.*/