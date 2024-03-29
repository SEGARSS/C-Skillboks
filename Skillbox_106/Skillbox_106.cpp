﻿#include<iostream>
#include<string>
using namespace std;

/*Задание 3. Анализ заполненности вагонов в поезде* (дополнительное задание)
Что нужно сделать
В поезде всего 10 вагонов. В каждом из этих вагонов может находиться до 20 пассажиров — это их оптимальное количество. 
Проанализируйте количество людей в каждом вагоне и сначала сообщите об излишне заполненных вагонах, 
далее о вагонах с пустыми пассажирскими местами. В заключение выведите общее количество пассажиров во всех вагонах.
При старте программы пользователь вводит количество пассажиров в каждом вагоне. 
Замечания о вагонах должны выводиться в стандартную консоль.
При выполнении задания пользоваться нельзя напрямую пользоваться for-циклами, только опосредованно, через макросы.*/

//-----------------------------------------------------------------------------------
#define TRAIN_SIZE 10
#define MAX_PASSENGERS_PER_WAGON 20
//-----------------------------------------------------------------------------------
void analyzeWagon(int passengers)
{
	if (passengers > MAX_PASSENGERS_PER_WAGON)
	{
		cout << "Внимание: вагон переполнен! Количество пассажиров: " << passengers << endl;
	}
	else if (passengers < MAX_PASSENGERS_PER_WAGON)
	{
		cout << "Внимание: в вагоне есть свободные места! Количество пассажиров: " << passengers << endl;
	}
}
//-----------------------------------------------------------------------------------
#define ANALYZE_WAGON(passengers) { analyzeWagon(passengers); }
//-----------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "ru");

	int passengers[TRAIN_SIZE];

	cout << "Введите количество пассажиров в каждом вагоне: " << endl;

	for (int i = 0; i < TRAIN_SIZE; ++i) 
	{
		cin >> passengers[i];
	}

	cout << "Анализ количества пассажиров в каждом вагоне:" << endl;

	for (int i = 0; i < TRAIN_SIZE; ++i) 
	{
		ANALYZE_WAGON(passengers[i]);
	}

	int totalPassengers = 0;

	for (int i = 0; i < TRAIN_SIZE; ++i) 
	{
		totalPassengers += passengers[i];
	}

	cout << "Общее количество пассажиров во всех вагонах: " << totalPassengers << endl;

	return 0;
}
//-----------------------------------------------------------------------------------