#include<iostream>
using namespace std;

/*Необходимо введённое число, все цифры в нём сложить.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int number;
	cout << "Введите число, числа которые в нём необходимо все сложить: ";
	cin >> number;

	int n = number; // сохраняем исходное введённое число для вывода красивого ответа в конце.

	int sum = 0;

	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}

	cout << "Сумма всех цифр в чесле - " << n << " равна " << sum << endl;

	return 0;
}