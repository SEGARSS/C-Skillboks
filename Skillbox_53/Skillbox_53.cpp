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

	int axisLength;

	std::cout << "Введите размер координатных осей: ";
	std::cin >> axisLength;

	for (int y = axisLength; y >= -axisLength; --y) {
		for (int x = -axisLength; x <= axisLength; ++x) {
			if (x == 0 && y == 0) {
				cout << "+";
			}
			else if (x == 0) {
				cout << "|";
			}
			else if (y == 0) {
				cout << ">";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}