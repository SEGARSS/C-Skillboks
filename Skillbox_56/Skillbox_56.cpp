#include<iostream>
using namespace std;

/*Задание 2. Сортировка

Что нужно сделать:
Пользователь вводит в консоль 15 дробных чисел. 
Необходимо прочитать их и вывести в консоль в порядке от большего к меньшему. 
По возможности используйте минимум дополнительной памяти и проходов по массиву.*/

int main()
{
	setlocale(LC_ALL,"ru");

	float vod;
	float numbers[15] {};

	cout << "Введите 15 дробных чисел через пробел: " << endl;

	for (int i = 0; i < 15; i++) //Проинацилизируем массив числами которые ввели.
	{
		cout << "Введите дробное число: ";

		while (!(cin >> vod) )
		{
			cout << "Ошибка ввода. Введите дробное число: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		numbers[i] = vod;
	}

	cout << endl;
	cout << "Массив введённых данных. " << endl;

	for (int i = 0; i < 15; i++) // Выведем массив в терминал
	{
		cout << numbers[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14 - i; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				// Обмен значениями
				float temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}

	cout << endl;
	cout << "Массив отсартированных данных данных. " << endl;

	// Вывод отсортированного массива
	for (int i = 0; i < 15; i++)
	{
		cout << numbers[i] << " ";
	}

	cout << endl;
	cout << endl;

	cout << "Повторяющееся число(а) в массиве: " << endl;

	 // Задание 4. Ряд чисел* (дополнительное задание)
	// Проверка на повторения 
	bool foundRepeat = false;

	for (int i = 0; i < 14; i++)
	{
		for (int j = i + 1; j < 15; j++)
		{
			if (numbers[i] == numbers[j])
			{
				cout << numbers[i] << " ";
				foundRepeat = true;
				break;
			}
		}
	}

	if (!foundRepeat)
	{
		cout << "Нет повторяющихся чисел." << endl;
	}

	cout << endl;

	return 0;
}