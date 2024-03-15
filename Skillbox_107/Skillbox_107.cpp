#include <iostream>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

/*Задание 1. Реализация программы учёта времени
Что нужно сделать
Используя функцию получения текущего времени std::time, реализуйте простейший менеджер учёта времени.
Пользователь взаимодействует с программой с помощью команд:
• Команда begin начинает отслеживание новой задачи. После ввода этой команды пользователь должен ввести название задачи, 
над которой он планирует сейчас работать. Если уже была начата какая-то другая задача, 
предыдущая должна быть автоматически завершена и начата новая.
• Команда end заканчивает отслеживание текущей задачи. Если текущей начатой задачи нет, то команда ничего не делает.
• Команда status выводит на экран информацию о всех законченных задачах и времени, которое было на них потрачено. 
Также выводится название текущей выполняемой задачи, если таковая имеется.
• Команда exit выходит из программы.*/

//-----------------------------------------------------------------------------------
struct Task // Структура для хранения информации о задаче
{
	string name;        // Название задачи
	time_t startTime;   // Время начала задачи
	time_t endTime;     // Время окончания задачи
};
//-----------------------------------------------------------------------------------
string formatTime(time_t time) // Функция для вывода времени в формате часов:минут
{
	char buffer[9]; // 8 символов для времени в формате "HH:MM\0"
	struct tm result;
	localtime_s(&result, &time);
	strftime(buffer, sizeof(buffer), "%H:%M", &result);
	return string(buffer);
}
//-----------------------------------------------------------------------------------
double calculateTime(const Task& task) // Функция для расчета времени работы над задачей в секундах
{
	if (task.endTime == 0) 
	{
		return difftime(time(nullptr), task.startTime);
	}
	else 
	{
		return difftime(task.endTime, task.startTime);
	}
}
//-----------------------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL, "ru");

	string command;
	vector<Task> tasks; // Хранилище для всех задач

	while (true) 
	{
		cout << "Введите команду (begin, end, status, exit): ";
		cin >> command;

		if (command == "exit") 
		{
			break;
		}
		else if (command == "begin") 
		{
			string taskName;
			cin >> taskName;

			// Если есть текущая задача, завершаем её
			if (!tasks.empty() && tasks.back().endTime == 0) 
			{
				tasks.back().endTime = time(nullptr);
				cout << "Задача \"" << tasks.back().name << "\" завершена в " << formatTime(tasks.back().endTime) << endl;
			}

			// Начинаем новую задачу
			Task newTask;
			newTask.name = taskName;
			newTask.startTime = time(nullptr);
			newTask.endTime = 0;
			tasks.push_back(newTask);
			cout << "Начата задача \"" << taskName << "\" в " << formatTime(newTask.startTime) << endl;
		}
		else if (command == "end") 
		{
			if (!tasks.empty() && tasks.back().endTime == 0) 
			{
				tasks.back().endTime = time(nullptr);
				cout << "Задача \"" << tasks.back().name << "\" завершена в " << formatTime(tasks.back().endTime) << endl;
			}
		}
		else if (command == "status") 
		{
			if (!tasks.empty() && tasks.back().endTime == 0) 
			{
				cout << "Текущая задача: \"" << tasks.back().name << "\"" << endl;
			}
			else 
			{
				cout << "Текущая задача: нет" << endl;
			}

			cout << "Завершенные задачи:" << endl;
			for (const auto& task : tasks) 
			{
				cout << "- \"" << task.name << "\": " << calculateTime(task) << " секунд" << endl;
			}
		}
		else 
		{
			cout << "Неверная команда. Повторите ввод." << endl;
		}
	}

	return 0;
}
//-----------------------------------------------------------------------------------