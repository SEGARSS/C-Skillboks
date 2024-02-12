#include<iostream>
#include<string>
#include<sstream>
#include <tuple>
using namespace std;

/*1. Время в пути
Что нужно сделать
Поезд отправляется в AA часов BB минут и прибывает в пункт назначения в CC часов DD минут. 
Сколько часов и минут он находится в пути?
Напишите программу, которая принимает от пользователя две строки — время отправления и время прибытия поезда. 
Время задаётся строкой из пяти символов в формате HH:MM. Обеспечьте контроль ввода, убедитесь также, что время корректно.
Программа должна ответить, сколько часов и минут поезд находится в пути. Если время отправления больше времени прибытия, 
считайте, что поезд прибывает в пункт назначения на следующий день.*/

//----------------------------------------------------------------------------------
//функция для разборов времени из строки в формат "HH:MM"
pair<int, int> parseTime(const string &timeStr)
{
	int hours, minutes;
	char colon;
	istringstream ss(timeStr);
	ss >> hours >> colon >> minutes;
	return {hours, minutes};
}
//----------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"Ru");

	string departureTimeStr, arrivalTimeStr;

	//Ввод времени отправления
	cout << "Введите время отправления в формате - (НН:ММ): ";
	getline(cin, departureTimeStr);

	//Проверка длинны строки
	if (departureTimeStr.length() != 5)
	{
		cout << "Некоректный формат времени" << endl;
		return 0;
	}

	//Проверка валидности времени
	int departureHours, departureMinutes;
	tie(departureHours, departureMinutes) = parseTime(departureTimeStr);
	if (departureHours < 0 || departureHours >= 24 || departureMinutes < 0 || departureMinutes >= 60)
	{
		cout << "Некоретное время отправления." << endl;
		return 1;
	}

	//Ввод времени прибытия
	cout << "Введите время прибытия в формате - (НН:ММ): ";
	getline(cin, arrivalTimeStr);

	//Проверка длинный строки.
	if (arrivalTimeStr.length() != 5)
	{
		cout << "Некоректный формат времени" << endl;
		return 1;
	}

	//Проверка валидности времени прибытия
	int arrivalHours, arrivaMinutes;
	tie(arrivalHours, arrivaMinutes) = parseTime(arrivalTimeStr);// Используем tie для распаковки пары
	if (arrivalHours < 0 || arrivalHours >= 24 || arrivaMinutes < 0 || arrivaMinutes > 60)
	{
		cout << "Некоретное время прибытия." << endl;
		return 1;
	}

	//Подсчет времени в пути
	int travelHours = arrivalHours - departureHours;
	int travelMinutes = arrivaMinutes - departureMinutes;
	if (travelMinutes < 0)
	{
		travelHours--;
		travelMinutes += 60;
	}
	if (travelHours < 0)
	{
		travelHours += 24;
	}

	//Вывод результата
	cout << "Поездка составила " << travelHours << " ч. " << travelMinutes << " м. " << endl; 

	return 0;
}
//----------------------------------------------------------------------------------