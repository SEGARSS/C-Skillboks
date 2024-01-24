#include<iostream>
#include<string>
using namespace std;

/*Задание 5. Координатные оси
Что нужно сделать
Модифицируйте пример с координатными осями так, 
чтобы в точке их пересечения рисовался знак «+», 
на верхнем конце вертикальной оси была стрелка вверх «^», 
а на правом конце горизонтальной оси — стрелка вправо «>». 
Это сделает рисунок более красивым и точным.*/

int main()
{
	setlocale(LC_ALL, "ru");

	int size;
	cout << "Введите размер рисунка: ";
	cin >> size;

	// Рисуем верхнюю линию
	cout << "+";
	for (int i = 0; i < size; i++)
	{
		cout << "-";
	}
	cout << ">" << endl;

	// Рисуем координатные оси и метки
	for (int y = size; y >= -size; y--)
	{
		cout << "|";
		for (int x = -size; x <= size; x++)
		{
			if (x == 0 && y == 0)
			{
				cout << "+";
			}
			else if (x == 0 && y > 0)
			{
				cout << "^";
			}
			else if (x > 0 && y == 0)
			{
				cout << ">";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "|" << endl;
	}

	// Рисуем нижнюю линию
	cout << "+";
	for (int i = 0; i < size; i++)
	{
		cout << "-";
	}
	cout << ">" << endl;

	return 0;
}