#include<iostream>
#include<string>
using namespace std;

/*Задание 1. Многоквартирный дом

Что нужно сделать:
На вход программе поступают десять фамилий в формате строк. 
Это фамилии жильцов квартир с первой по десятую. 
Необходимо прочитать эти фамилии и записать в одномерный массив.
Далее пользователь вводит три номера квартир. 
Необходимо вывести в консоль фамилию жильца, проживающего в этой квартире. 
Если пользователь введёт некорректный номер квартиры, необходимо сообщить ему об этом.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int flat;

	string people [] = 
	{"SidorovA", 
	 "IvanovA", 
	 "PetrovA", 
	 "SidorovB", 
	 "IvanovB", 
	 "PetrovB", 
	 "SidorovC", 
	 "IvanovC", 
	 "PetrovC", 
	 "SidorovD"};

	for (int i = 0; i < 10; i++)
	{
		cout << people[i] << endl;
	}
		
	for (int i = 0; i < 3; i++)
	{
		cout << "Введите номер квартиры и вы узнаете кто там живёт: ";
		cin>>flat;
		if (flat >=0 && flat < 10)
		{
			cout << people[flat] << endl;
		}
		else
		{
			cout << "Квартиры с таким номер нет." << endl;
		}
	}

	return 0;
}