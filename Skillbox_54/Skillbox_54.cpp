#include<iostream>
#include<string>
using namespace std;

/*Задание 6. Важные объявления
Что нужно сделать
Напишите программу для печати важных объявлений. 
Сверху объявления должен располагаться вот такой колонтитул:

Восклицательные знаки всегда располагаются по центру строки, 
причём в зависимости от важности объявления количество восклицательных знаков может быть разным. 
Напишите программу, которая спрашивает у пользователя сначала общую длину колонтитула в символах, 
потом желаемое количество восклицательных знаков, после чего выводит на экран готовую строку. 
Обеспечьте контроль ввода.*/

int main()
{
	setlocale(LC_ALL, "ru");

	int totalLength;
	int exclamationCount;

	cout << "Введите общую длину колонтитула в символах: ";
	cin >> totalLength;

	cout << "Введите желаемое количество восклицательных знаков: ";
	cin >> exclamationCount;

	if (exclamationCount < 0) {
		cout << "Ошибка: количество восклицательных знаков не может быть отрицательным." << endl;
		return 0;
	}

	// Вычисляем количество пробелов до и после восклицательных знаков
	int spacesBefore = (totalLength - exclamationCount) / 2;
	int spacesAfter = totalLength - spacesBefore - exclamationCount;

	// Печатаем колонтитул
	cout << string(spacesBefore, '~') << string(exclamationCount, '!') << string(spacesAfter, '~') << endl;

	return 0;
}