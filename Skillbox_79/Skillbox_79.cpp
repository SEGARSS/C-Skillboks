#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Задача 3
Что нужно сделать:
С клавиатуры вводятся числа. Когда пользователь вводит «-1», 
необходимо выводить на экран пятое по возрастанию число среди введённых. 
Когда пользователь вводит «-2», программа завершает работу.*/

int main() 
{
	setlocale(LC_ALL, "ru");

	vector<int> numbers;
	int input;

	while (true) 
	{
		cin >> input;

		if (input == -1) 
		{
			if (numbers.size() >= 5) 
			{
				sort(numbers.begin(), numbers.end());
				cout << "Пятое по возрастанию число: " << numbers[4] << endl;
			}
			else 
			{
				cout << "Введено недостаточно чисел." << endl;
			}
		}
		else if (input == -2) 
		{
			break;
		}
		else 
		{
			numbers.push_back(input);
			sort(numbers.begin(), numbers.end());
		}
	}

	cout << "Отсортированный массив: ";
	for (int num : numbers) 
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}