#include <iostream>
#include <ctime>
#include <string>
#include <map>

using namespace std;

// ��������� ��� �������� ���������� � ������
struct Task {
    string name;        // �������� ������
    time_t startTime;   // ����� ������ ������
    time_t endTime;     // ����� ��������� ������
};

// ������� ��� ������ ������� � ������� �����:�����
string formatTime(time_t time) {
    char buffer[9]; // 8 �������� ��� ������� � ������� "HH:MM\0"
    struct tm* result = localtime(&time);
    strftime(buffer, sizeof(buffer), "%H:%M", result);
    return string(buffer);
}

int main() {
    string command;
    map<string, Task> tasks; // ��������� ��� ���� �����

    while (true) {
        cout << "������� ������� (begin, end, status, exit): ";
        cin >> command;

        if (command == "exit") {
            break;
        }
        else if (command == "begin") {
            string taskName;
            cin >> taskName;

            // ���� ���� ������� ������, ��������� �
            if (!tasks.empty()) {
                Task& currentTask = tasks.begin()->second;
                currentTask.endTime = time(nullptr);
                cout << "������ \"" << currentTask.name << "\" ��������� � " << formatTime(currentTask.endTime) << endl;
            }

            // �������� ����� ������
            Task newTask;
            newTask.name = taskName;
            time_t currentTime = time(nullptr);
            newTask.startTime = currentTime;
            tasks[taskName] = newTask;
            cout << "������ ������ \"" << taskName << "\" � " << formatTime(newTask.startTime) << endl;
        }
        else if (command == "end") {
            if (!tasks.empty()) {
                Task& currentTask = tasks.begin()->second;
                currentTask.endTime = time(nullptr);
                cout << "������ \"" << currentTask.name << "\" ��������� � " << formatTime(currentTask.endTime) << endl;
                tasks.erase(tasks.begin());
            }
        }
        else if (command == "status") {
            if (!tasks.empty()) {
                Task& currentTask = tasks.begin()->second;
                cout << "������� ������: \"" << currentTask.name << "\"" << endl;
            }
            else {
                cout << "������� ������: ���" << endl;
            }

            cout << "����������� ������:" << endl;
            for (const auto& pair : tasks) {
                const Task& task = pair.second;
                cout << "- \"" << task.name << "\": " << (task.endTime - task.startTime) / 3600 << " �����" << endl;
            }
        }
        else {
            cout << "�������� �������. ��������� ����." << endl;
        }
    }

    return 0;
}
