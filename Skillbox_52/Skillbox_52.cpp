#include<iostream>
#include<string>
using namespace std;

/*Задание 4. Рамка
Что нужно сделать
Напишите программу, которая рисует с помощью символьной графики прямоугольную рамку. 
Для вертикальных линий используйте символ вертикального штриха «|», а для горизонтальных — дефис «-». 
Пусть пользователь вводит ширину и высоту рамки.*/

int main()
{
	setlocale(LC_ALL, "ru");

	int width, height;
	cout << "Введите ширину и высоту рамки: ";
	cin >> width >> height;

	// Верхняя горизонтальная линия
	for (int i = 0; i < width; i++) {
		cout << "-";
	}
	cout << endl;

	// Боковые вертикальные линии и пробелы
	for (int i = 0; i < height - 2; i++) {
		cout << "|";
		for (int j = 0; j < width - 2; j++) {
			cout << " ";
		}
		cout << "|" << endl;
	}

	// Нижняя горизонтальная линия
	for (int i = 0; i < width; i++) {
		cout << "-";
	}
	cout << endl;

	return 0;
}