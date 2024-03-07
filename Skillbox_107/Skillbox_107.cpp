#include <iostream>
#include <ctime>
#include <string>
#include <map>

using namespace std;

// Структура для хранения информации о задаче
struct Task {
    string name;        // Название задачи
    time_t startTime;   // Время начала задачи
    time_t endTime;     // Время окончания задачи
};

// Функция для вывода времени в формате часов:минут
string formatTime(time_t time) {
    char buffer[9]; // 8 символов для времени в формате "HH:MM\0"
    struct tm* result = localtime(&time);
    strftime(buffer, sizeof(buffer), "%H:%M", result);
    return string(buffer);
}

int main() {
    string command;
    map<string, Task> tasks; // Хранилище для всех задач

    while (true) {
        cout << "Введите команду (begin, end, status, exit): ";
        cin >> command;

        if (command == "exit") {
            break;
        }
        else if (command == "begin") {
            string taskName;
            cin >> taskName;

            // Если есть текущая задача, завершаем её
            if (!tasks.empty()) {
                Task& currentTask = tasks.begin()->second;
                currentTask.endTime = time(nullptr);
                cout << "Задача \"" << currentTask.name << "\" завершена в " << formatTime(currentTask.endTime) << endl;
            }

            // Начинаем новую задачу
            Task newTask;
            newTask.name = taskName;
            time_t currentTime = time(nullptr);
            newTask.startTime = currentTime;
            tasks[taskName] = newTask;
            cout << "Начата задача \"" << taskName << "\" в " << formatTime(newTask.startTime) << endl;
        }
        else if (command == "end") {
            if (!tasks.empty()) {
                Task& currentTask = tasks.begin()->second;
                currentTask.endTime = time(nullptr);
                cout << "Задача \"" << currentTask.name << "\" завершена в " << formatTime(currentTask.endTime) << endl;
                tasks.erase(tasks.begin());
            }
        }
        else if (command == "status") {
            if (!tasks.empty()) {
                Task& currentTask = tasks.begin()->second;
                cout << "Текущая задача: \"" << currentTask.name << "\"" << endl;
            }
            else {
                cout << "Текущая задача: нет" << endl;
            }

            cout << "Завершенные задачи:" << endl;
            for (const auto& pair : tasks) {
                const Task& task = pair.second;
                cout << "- \"" << task.name << "\": " << (task.endTime - task.startTime) / 3600 << " часов" << endl;
            }
        }
        else {
            cout << "Неверная команда. Повторите ввод." << endl;
        }
    }

    return 0;
}
