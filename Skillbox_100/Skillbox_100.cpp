#include <iostream>
#include <cmath>

using namespace std;

/*3. Математический вектор
Что нужно сделать
Реализуйте структуру двумерного математического вектора и основные операции над ним. 
Обе координаты вектора (x и y) должны быть вещественными числами.
Начиная работу с программой, пользователь вводит команду. Затем в зависимости от команды пользователь вводит аргументы. 
Это могут быть как векторы, так и обычные скалярные значения. Результат помещается в стандартный вывод. 
Это тоже может быть или вектор, или скаляр.

Реализуйте в виде отдельных функций операции:
• сложение двух векторов — команда add;
• вычитание двух векторов — команда subtract;
• умножение вектора на скаляр — команда scale;
• нахождение длины вектора — команда length;
• нормализация вектора — команда normalize.*/

//-----------------------------------------------------------------------------------
struct Vector2D // Структура для представления двумерного вектора
{
	double x;
	double y;

	// Конструктор для инициализации вектора
	Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

	// Оператор сложения двух векторов
	Vector2D operator+(const Vector2D& other) const 
	{
		return Vector2D(x + other.x, y + other.y);
	}

	// Оператор вычитания двух векторов
	Vector2D operator-(const Vector2D& other) const 
	{
		return Vector2D(x - other.x, y - other.y);
	}

	// Оператор умножения вектора на скаляр
	Vector2D operator*(double scalar) const 
	{
		return Vector2D(x * scalar, y * scalar);
	}

	// Метод для вычисления длины вектора
	double length() const 
	{
		return sqrt(x * x + y * y);
	}

	// Метод для нормализации вектора (приведения его к единичной длине)
	Vector2D normalize() const 
	{
		double len = length();
		if (len != 0.0) 
		{
			return *this * (1.0 / len);
		}
		else 
		{
			return *this;
		}
	}
};
//-----------------------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL,"ru");

	char command;
	cout << "Выбирите команду: " << endl;
	cout << "1 - add" << endl << "2 - subtract" << endl << "3 - scale" << endl << "4 - length" << endl << "5 - normalize" << endl;
	cout << "Введите номер команды: ";
	cin >> command;

	Vector2D vec1, vec2;
	double scalar;

	switch (command) 
	{
	case '1':
		cout << "Введите координаты первого вектора (x y): ";
		cin >> vec1.x >> vec1.y;
		cout << "Введите координаты второго вектора (x y): ";
		cin >> vec2.x >> vec2.y;
		cout << "Результат сложения векторов: " << (vec1 + vec2).x << " " << (vec1 + vec2).y << endl;
		break;
	case '2':
		cout << "Введите координаты первого вектора (x y): ";
		cin >> vec1.x >> vec1.y;
		cout << "Введите координаты второго вектора (x y): ";
		cin >> vec2.x >> vec2.y;
		cout << "Результат вычитания векторов: " << (vec1 - vec2).x << " " << (vec1 - vec2).y << endl;
		break;
	case '3':
		cout << "Введите координаты вектора (x y): ";
		cin >> vec1.x >> vec1.y;
		cout << "Введите скаляр: ";
		cin >> scalar;
		cout << "Результат умножения вектора на скаляр: " << (vec1 * scalar).x << " " << (vec1 * scalar).y << endl;
		break;
	case '4':
		cout << "Введите координаты вектора (x y): ";
		cin >> vec1.x >> vec1.y;
		cout << "Длина вектора: " << vec1.length() << endl;
		break;
	case '5':
		cout << "Введите координаты вектора (x y): ";
		cin >> vec1.x >> vec1.y;
		cout << "Нормализованный вектор: " << vec1.normalize().x << " " << vec1.normalize().y << endl;
		break;
	default:
		cout << "Неверная команда." << endl;
	}

	return 0;
}
//-----------------------------------------------------------------------------------