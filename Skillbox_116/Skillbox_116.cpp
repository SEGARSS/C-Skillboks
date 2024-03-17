#include <iostream>
#include <cmath>

using namespace std;

/*Задание 2. Иерархия геометрических фигур
Что нужно сделать
Спроектируйте иерархию классов различных фигур: круг, квадрат, равносторонний треугольник, прямоугольник.
Для всех этих фигур есть общие поля-данные — это координаты их центра и условный цвет фигуры: красный, синий или зелёный.
Для отдельных фигур есть и уникальные параметры:
радиус для круга, длина ребра для квадрата и равностороннего треугольника, ширина и высота для прямоугольника.
Все данные — это вещественные числа с удвоенной точностью.
Для каждой из фигур требуется определить метод нахождения площади фигуры,
а также метод нахождения прямоугольника, описывающего фигуру полностью (он может быть больше зоны фигуры, но не меньше).*/

//---------------------------------------------------------------------------------------------------------
enum Color { Red, Green, Blue, None }; // Перечисление для цвета фигур
//---------------------------------------------------------------------------------------------------------
class Shape // Базовый класс Фигура
{
public:
	// Конструктор
	Shape(double x, double y, Color color) : x(x), y(y), color(color) {}

	// Виртуальный метод для нахождения площади фигуры
	virtual double area() const = 0;

	// Виртуальный метод для нахождения описывающего прямоугольника
	virtual void boundingBox() const = 0;

	// Метод для вывода цвета фигуры
	void printColor() const 
	{
		switch (color) 
		{
		case Red: cout << "Красный"; break;
		case Green: cout << "Зеленый"; break;
		case Blue: cout << "Синий"; break;
		default: cout << "Нет цвета"; break;
		}
	}

protected:
	double x; // Координата X центра фигуры
	double y; // Координата Y центра фигуры
	Color color; // Цвет фигуры
};
//---------------------------------------------------------------------------------------------------------
class Circle : public Shape // Класс Круг, производный от Фигуры
{
public:
	// Конструктор
	Circle(double x, double y, double radius, Color color) : Shape(x, y, color), radius(radius) {}

	// Метод для нахождения площади круга
	double area() const override 
	{
		return atan(1) * 4 * radius * radius;
	}

	// Метод для нахождения описывающего прямоугольника
	void boundingBox() const override 
	{
		cout << "Описывающий прямоугольник для круга: (" << x - radius << ", " << y - radius << "), (" << x + radius << ", " << y + radius << ")" << endl;
	}

private:
	double radius; // Радиус круга
};
//---------------------------------------------------------------------------------------------------------
class Square : public Shape // Класс Квадрат, производный от Фигуры
{
private:
	double side; // Длина стороны квадрата

public:
	// Конструктор
	Square(double x, double y, double side, Color color) 
	: Shape(x, y, color), side(side) 
	{
	}

	// Метод для нахождения площади квадрата
	double area() const override 
	{
		return side * side;
	}

	// Метод для нахождения описывающего прямоугольника
	void boundingBox() const override 
	{
		cout << "Описывающий прямоугольник для квадрата: (" << x - side / 2 << ", " << y - side / 2 << "), (" << x + side / 2 << ", " << y + side / 2 << ")" << endl;
	}
};
//---------------------------------------------------------------------------------------------------------
class Triangle : public Shape // Класс Равносторонний треугольник, производный от Фигуры
{
public:
	// Конструктор
	Triangle(double x, double y, double side, Color color) 
	: Shape(x, y, color), side(side) 
	{
	}

	// Метод для нахождения площади треугольника
	double area() const override 
	{
		return side * side * sqrt(3) / 4;
	}

	// Метод для нахождения описывающего прямоугольника
	void boundingBox() const override 
	{
		cout << "Описывающий прямоугольник для треугольника: (" << x - side / 2 << ", " << y - side / (2 * sqrt(3)) << "), (" << x + side / 2 << ", " << y + side / (2 * sqrt(3)) << ")" << endl;
	}

private:
	double side; // Длина стороны треугольника
};
//---------------------------------------------------------------------------------------------------------
class Rectangle : public Shape // Класс Прямоугольник, производный от Фигуры
{
public:
	// Конструктор
	Rectangle(double x, double y, double width, double height, Color color) 
	: Shape(x, y, color), width(width), height(height) 
	{
	}

	// Метод для нахождения площади прямоугольника
	double area() const override 
	{
		return width * height;
	}

	// Метод для нахождения описывающего прямоугольника
	void boundingBox() const override 
	{
		cout << "Описывающий прямоугольник для прямоугольника: (" << x - width / 2 << ", " << y - height / 2 << "), (" << x + width / 2 << ", " << y + height / 2 << ")" << endl;
	}

private:
	double width; // Ширина прямоугольника
	double height; // Высота прямоугольника
};
//---------------------------------------------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL, "ru");

	// Ввод пользовательских команд
	string command;
	cout << "Введите команду (circle, square, triangle, rectangle): ";
	cin >> command;

	if (command == "circle") 
	{
		double x, y, radius;
		cout << "Введите координаты центра и радиус круга: ";
		cin >> x >> y >> radius;
		Circle circle(x, y, radius, Red);
		cout << "Площадь круга: " << circle.area() << endl;
		cout << "Цвет круга: "; circle.printColor(); cout << endl;
		circle.boundingBox();
	}
	else if (command == "square") 
	{
		double x, y, side;
		cout << "Введите координаты центра и длину стороны квадрата: ";
		cin >> x >> y >> side;
		Square square(x, y, side, Green);
		cout << "Площадь квадрата: " << square.area() << endl;
		cout << "Цвет квадрата: "; square.printColor(); cout << endl;
		square.boundingBox();
	}
	else if (command == "triangle") 
	{
		double x, y, side;
		cout << "Введите координаты центра и длину стороны треугольника: ";
		cin >> x >> y >> side;
		Triangle triangle(x, y, side, Blue);
		cout << "Площадь треугольника: " << triangle.area() << endl;
		cout << "Цвет треугольника: "; triangle.printColor(); cout << endl;
		triangle.boundingBox();
	}
	else if (command == "rectangle") 
	{
		double x, y, width, height;
		cout << "Введите координаты центра, ширину и высоту прямоугольника: ";
		cin >> x >> y >> width >> height;
		Rectangle rectangle(x, y, width, height, None);
		cout << "Площадь прямоугольника: " << rectangle.area() << endl;
		cout << "Цвет прямоугольника: "; rectangle.printColor(); cout << endl;
		rectangle.boundingBox();
	}
	else 
	{
		cout << "Некорректная команда!" << endl;
	}

	return 0;
}
//---------------------------------------------------------------------------------------------------------