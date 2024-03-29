﻿#include<iostream>
using namespace std;

/*Задача 2
Что нужно сделать:
Написать функцию, которая принимает указатель на тип int, по которому размещены 10 переменных типа int. 
Функция ничего не возвращает, но по тому же указателю элементы должны лежать в обратном порядке.*/

//--------------------------------------------------------------------------------------------------------
void reverseaArray(int *ptr)
{
	int temp;

	for (int i = 0; i < 5; i++)
	{
		temp = ptr[i];
		ptr[i] = ptr[9 - i];
		ptr[9 - i] = temp;
	}
}
//--------------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	cout << "Оригинальный массив: ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	reverseaArray(arr);

	cout << "Обратный массив: ";
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}
//--------------------------------------------------------------------------------------------------------