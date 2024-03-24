#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL,"ru");

	string buffer;
	cout << "Введите выражение в формате <число1><действие><число2>: ";
	getline(cin, buffer);

	double a, b;
	char operation;

	stringstream buffer_stream(buffer);
	buffer_stream >> a >> operation >> b;

	double result;

	switch (operation) 
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		if (b == 0) {
			cout << "Ошибка: деление на ноль!" << endl;
			return 1;
		}
		result = a / b;
		break;
	default:
		cout << "Ошибка: неверный оператор!" << endl;
		return 1;
	}

	cout << "Результат: " << result << endl;

	return 0;
}
