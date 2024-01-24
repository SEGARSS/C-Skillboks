﻿#include<iostream>
#include<string>
using namespace std;

/*Перепишите программу из прошлого модуля, используя цикл for. 
Напишите программу для робота-начальника. 
Он спрашивает у пользователя, выполнил ли он задание, которое тот выдавал вчера, 
и продолжает это делать до тех пор, пока пользователь не ответит ему “Да, конечно, сделал”. 
Для большей реалистичности в конце пусть робот-начальник пожалуется: 
“Ну почему тебя нужно спрашивать N раз?”, где N — это число попыток, 
которые были потрачены пользователем, прежде чем он ввёл правильный ответ.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int attempts = 0;
	string answer;

	for (;;) // бесконечный цикл
	{ 
		cout << "Выполнили ли вы задание, которое я вам дал вчера? ";
		cin >> answer;

		attempts++;

		if (answer == "Yes") 
		{
			break; // выход из цикла
		}
	}

	cout << "Ну почему тебя нужно спрашивать " << attempts << " раз?" << endl;

	return 0;
}