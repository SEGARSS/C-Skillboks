﻿#include<iostream>
using namespace std;

/*Задача 1
Что нужно сделать:
Написать функцию, принимающую два указателя на int и меняет местами содержимое данных указателей.*/

//--------------------------------------------------------------------------------------------------------
void swap(int *ptr1, int *ptr2)
{
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
//--------------------------------------------------------------------------------------------------------
int main()
{
	int a = 10;
	int b = 20;

	cout << a << " " << b << endl;

	swap(&a, &b);

	cout << a << " " << b << endl; 

	return 0;
}
//--------------------------------------------------------------------------------------------------------