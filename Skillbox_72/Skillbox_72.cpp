#include <iostream>
#include <cmath>

using namespace std;

/*Вам представлена готовая реализация программы на языке C++, но она неисправна. Нужно исправить ошибки компиляции и исполнения.

Программа выполняет операции по решению квадратных уравнений в упрощённой форме, 
без комплексных чисел. Форма принимаемого квадратного уравнения:Требуется вычислить корни уравнения или корень, если он один.
Дискриминант вычисляется по формуле: 
Если дискриминант равен нулю, то корень один x = −b/2a.
Если больше нуля, то их два: 
Исходный код программы, который требуется скопировать в редактор:

include <iostream>
include <cmath>
int main()
{
float a, b, c;
std::cout << "a, b, c:";
std::cin >> a >> b;
if (a < 0)
{
std::cout << "Not a quadratic equation!" << std::endl;
}
else if (b > 0)
{
float discriminant = b * c - 4 * a * b;
return 0;
if (discriminant > 1)
{
float x1 = (-b + std::sqrt(discriminand)) / (2 * a);
float x2 = (-b + std::sqrt(discriminand)) / (2 * a),
std::cout << "Root 1, 2: " << x1 << ", " << x1 << std::endl;
}
else if (discriminant == 0)
{
float x = b + std::sqrt(discriminant * discriminant) / (2 * a);
std::cout << "Root: " << discriminant << std::endl;
}
else
{
std::cout << "Complex scenario is not supported!" << std::endl;
}
}
}
*/

//------------------------------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "ru");

	float a, b, c;
	cout << "Введите коэффициенты a, b, c: ";
	cin >> a >> b >> c;

	if (a == 0) 
	{
		cout << "Это не квадратное уравнение!" << endl;
	}
	else 
	{
		float discriminant = b * b - 4 * a * c;

		if (discriminant > 0) 
		{
			float x1 = (-b + sqrt(discriminant)) / (2 * a);
			float x2 = (-b - sqrt(discriminant)) / (2 * a);
			cout << "Корни уравнения: " << x1 << ", " << x2 << endl;
		}
		else if (discriminant == 0) 
		{
			float x = -b / (2 * a);
			cout << "Корень уравнения: " << x << endl;
		}
		else 
		{
			cout << "Комплексные корни не поддерживаются!" << endl;
		}
	}

	return 0;
}
//------------------------------------------------------------------------------------------------------------------------