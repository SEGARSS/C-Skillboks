#include <iostream>
#include <cpr/cpr.h>

using namespace std;

int main() {
    string command;

    while (true) {
        cout << "������� ������� (get, post, put, delete, patch) ��� 'exit' ��� ����������: ";
        cin >> command;

        if (command == "exit") {
            cout << "��������� ���������." << endl;
            break;
        } else if (command != "get" && command != "post" && command != "put" && command != "delete" && command != "patch") {
            cout << "�������� �������. ���������� �����." << endl;
            continue;
        }

        // ���������� HTTP-������� � ����������� �� �������
        if (command == "get") {
            auto response = cpr::Get(cpr::Url{"https://httpbin.org/get"});
            cout << response.text << endl;
        } else if (command == "post") {
            auto response = cpr::Post(cpr::Url{"https://httpbin.org/post"});
            cout << response.text << endl;
        } else if (command == "put") {
            auto response = cpr::Put(cpr::Url{"https://httpbin.org/put"});
            cout << response.text << endl;
        } else if (command == "delete") {
            auto response = cpr::Delete(cpr::Url{"https://httpbin.org/delete"});
            cout << response.text << endl;
        } else if (command == "patch") {
            auto response = cpr::Patch(cpr::Url{"https://httpbin.org/patch"});
            cout << response.text << endl;
        }
    }

    return 0;
}
