#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

/*Задание 2. Реализация программы напоминания о днях рождения
Что нужно сделать
Реализуйте простую программу по вычислению ближайшего дня рождения.
В начале программы пользователь последовательно вводит данные о днях рождения своих друзей: 
вводит имя друга и саму дату рождения полностью, включая месяц и год, в формате год/месяц/день. 
Сигналом окончания ввода дней рождения является “end” введённое в качестве имени.
После этого программа вычисляет ближайший день рождения по отношению к текущему времени 
и выводит его на экран вместе с именем в удобном, локальном формате - месяц/день. 
Если день рождения уже был в этом году, данные о пользователе пропускаются. 
Если у кого-то из друзей день рождения сегодня, то в консоль выводится специальное сообщение об этом. 
Учтите, что таких сообщений может быть несколько, ведь сразу несколько людей могут иметь дни рождения в один день.*/

//-----------------------------------------------------------------------------------
struct Birthday // Структура для хранения информации о дне рождения
{
	string name;
	int year;
	int month;
	int day;
};
//-----------------------------------------------------------------------------------
tm getCurrentDate() // Функция для получения текущей даты
{
	time_t now = time(nullptr);
	tm localTime;
	localtime_s(&localTime, &now);
	return localTime;
}
//-----------------------------------------------------------------------------------
bool compareBirthdays(const Birthday& b1, const Birthday& b2) // Функция для сравнения дней рождения
{
	// Сначала сравниваем месяцы
	if (b1.month != b2.month)
	{
		return b1.month < b2.month;
	}

	// Если месяцы равны, сравниваем дни
	if (b1.day != b2.day)
	{
		return b1.day < b2.day;
	}

	// Если месяцы и дни равны, сравниваем годы
	return b1.year < b2.year;
}
//-----------------------------------------------------------------------------------
Birthday findNearestBirthday(const vector<Birthday>& birthdays) // Функция для вычисления ближайшего дня рождения
{
	tm currentDate = getCurrentDate();
	Birthday nearestBirthday;
	nearestBirthday.month = 13; // Месяц должен быть больше 12, чтобы гарантированно выбрать ближайший месяц

	for (const auto& birthday : birthdays)
	{
		// Если день рождения уже прошел в этом году, пропускаем его
		if (birthday.month < currentDate.tm_mon + 1 || (birthday.month == currentDate.tm_mon + 1 && birthday.day < currentDate.tm_mday))
		{
			continue;
		}

		if (compareBirthdays(birthday, nearestBirthday))
		{
			nearestBirthday = birthday;
		}
	}

	return nearestBirthday;
}
//-----------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "ru");

	vector<Birthday> birthdays;

	// Ввод данных о днях рождения
	cout << "Введите дни рождения своих друзей в формате: имя_друга год_рождения месяц_рождения день_рождения" << endl;

	while (true) 
	{
		string name;
		cin >> name;
		if (name == "end") 
		{
			break;
		}
		int year, month, day;
		cin >> year >> month >> day;
		birthdays.push_back({ name, year, month, day });
	}

	// Находим ближайший день рождения
	Birthday nearestBirthday = findNearestBirthday(birthdays);

	// Выводим результат
	if (nearestBirthday.month < 13) 
	{
		cout << "Ближайший день рождения: " << nearestBirthday.month << "/" << nearestBirthday.day << " - " << nearestBirthday.name << endl;
	}
	else 
	{
		cout << "Ближайший день рождения не найден." << endl;
	}

	return 0;
}
//-----------------------------------------------------------------------------------