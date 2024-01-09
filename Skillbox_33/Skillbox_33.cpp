#include<iostream>
using namespace std;

/*Необходимо чтобы программа суммирова все ведённые числа.
Числа не ограниченны количеством ввода.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int figure;
	cout << "Сколько чисел вы хотите просумировать?" << endl;
	cin >> figure;

	int interset = 0;
	int sum = 0;

	cout << "Введите все числа через пробел: ";

	while (interset < figure)
	{
		int nambers;
		cin >> nambers;
		sum += nambers;
		interset++;
	}

	cout << "Сумма всех чисел равна: " << sum << endl;

	return 0;
}