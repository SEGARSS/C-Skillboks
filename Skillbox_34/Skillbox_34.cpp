#include<iostream>
using namespace std;

/*Напишите программу, 
которая выводила бы N первых степеней числа К. 
Посмотрите, что случится, если N или K будут достаточно большими.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int a,b;

	cout << "Какой число вы хоте возвести в степень?: ";
	cin >> a;

	cout << "Введите показатель степени для числа: " << a << " ";
	cin >> b;

	int interset = 0;
	int result = 1;

	while (interset < b)
	{
		result *= a;
		interset++;
	}

	cout << "Результат равен: " << result << endl;

	return 0;
}