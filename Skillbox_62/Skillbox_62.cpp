#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "ru");

	cout << "Привет, Сергей! Сколько километров ты сегодня пробежал? ";
	int totalKilometers;
	cin >> totalKilometers;

	int totalSeconds = 0;

	for (int i = 1; i <= totalKilometers; ++i) 
	{
		cout << "Какой у тебя был темп на километре " << i << "? ";
		int pace;
		cin >> pace;

		totalSeconds += pace;
	}

	int averageSeconds = totalSeconds / totalKilometers;

	int minutes = averageSeconds / 60;
	int seconds = averageSeconds % 60;

	cout << "Твой средний темп за тренировку: " << minutes << " минуты " << seconds << " секунд." << endl;

	return 0;
}