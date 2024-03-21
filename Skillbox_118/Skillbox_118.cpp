#include<iostream>
#include<thread>
#include<vector>
#include<string>
#include<iomanip>
#include<algorithm>

using namespace std;

/*Задание 1. Заплыв на 100 метров
Что нужно сделать
Реализуйте симуляцию состязаний по заплыву на 100 метров.
Всего шесть дорожек и шесть пловцов. Имена пловцов указываются вначале из стандартного ввода. 
Каждый из них плывёт с разной скоростью, которая также задаётся пользователем при старте, 
через стандартный ввод в метрах в секунду.
Каждую секунду в стандартный вывод выдаётся информация о том, сколько проплыл тот или иной пловец.
Как только все пловцы коснулись 100-метровой отметки, заплыв заканчивается и выводится таблица с итоговыми результатами, 
отсортированная по возрастанию итогового времени заплыва.*/

//------------------------------------------------------------------------------------------------------------
class Swimmer // Класс для представления пловца
{
public:
	//Конструктор
	Swimmer(const string &name, double speed)	
	: name(name), speed(speed), distance(0)
	{
	}

	//Метод для получения имения пловца
	string getName() const
	{
		return name;
	}

	//Метод для получения скорости плавца
	double getSpeed() const
	{
		return speed;
	}

	//Метод для получения пройденного растояние плавцом
	double getDistance() const
	{
		return distance;
	}

	//Метод для запуска пловца в гонке
	void swim()
	{
		while (distance < 100)
		{
			distance += speed; // Увеличиваем пройденное растояние на скорость
			cout << name << ": " << fixed << setprecision(2) << distance << " метров" << endl;
			this_thread::sleep_for(chrono::seconds(1)); // Пауза на одну секунду
		}
	}

private:
	string name;
	double speed; // Скорость пловца в м/с
	double distance; // Пройденное расстояние пловцом
};
//------------------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	vector<Swimmer> swimmers;
	vector<thread> threads;

	// Вводим имена и скорость пловцов
	for (int i = 1; i <= 6; i++)
	{
		string name;
		double speed;

		cout << "Введите имя и скорость (m/c) пловца " << i << ": ";
		cin >> name >> speed;
		swimmers.emplace_back(name, speed);
	}

	//Запускаем пловца в гонке
	for (auto &swimmer : swimmers)
	{
		threads.emplace_back(&Swimmer::swim, &swimmer);
	}

	//Дожидаемся окончания гонки
	for (auto &thread : threads)
	{
		thread.join();
	}

	//Выводим итоговые результаты
	cout << "Итоговые результаты: " << endl;
	sort(swimmers.begin(), swimmers.end(), [](const Swimmer& a, const Swimmer& b)
		{
			return a.getDistance() < b.getDistance();
		});

	for (const auto &swimmer : swimmers)
	{
		cout << swimmer.getName() << ": " << fixed << setprecision(2) << swimmer.getDistance() << " метров" << endl;
	}

	return 0;
}
//------------------------------------------------------------------------------------------------------------