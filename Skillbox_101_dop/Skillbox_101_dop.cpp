#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    map<string, string> phonebook;
    multimap<string, string> lastNameToPhone;

    cout << "����� ���������� � ���������� ����������!" << endl;

    while (true) 
    {
        cout << "\n�������� ��������:" << endl;
        cout << "1. �������� ����� � ��������" << endl;
        cout << "2. ������ ������� �������� �� ������ ��������" << endl;
        cout << "3. ������ ������ ��������� �� ������� ��������" << endl;
        cout << "4. ����� �� ���������" << endl;

        int choice;
        cout << "��� �����: ";
        cin >> choice;

        if (choice == 1) 
        {
            string lastName, phoneNumber;
            cout << "������� ������� ��������: ";
            cin >> lastName;
            cout << "������� ����� ��������: ";
            cin >> phoneNumber;
            phonebook[phoneNumber] = lastName;
            lastNameToPhone.insert({lastName, phoneNumber}); // ��������� � �������������� multimap
            cout << "����� � ������� ������� ��������� � ����������." << endl;
        }
        else if (choice == 2) 
        {
            string phoneNumber;
            cout << "������� ����� ��������: ";
            cin >> phoneNumber;

            if (phonebook.find(phoneNumber) != phonebook.end()) 
            {
                cout << "������� ��������: " << phonebook[phoneNumber] << endl;
            }
            else 
            {
                cout << "����� �������� �� ������ � �����������." << endl;
            }
        }
        else if (choice == 3) 
        {
            string lastName;
            cout << "������� ������� ��������: ";
            cin >> lastName;

            auto range = lastNameToPhone.equal_range(lastName);
            if (range.first != lastNameToPhone.end()) 
            {
                cout << "������ ��������� ��� �������� " << lastName << ":" << endl;
                for (auto it = range.first; it != range.second; ++it) 
                {
                    cout << it->second << endl;
                }
            }
            else 
            {
                cout << "������� � ��������� �������� �� ������ � �����������." << endl;
            }
        }
        else if (choice == 4) 
        {
            cout << "������� �� ������������� ����������� �����������. �� ��������!" << endl;
            break;
        }
        else 
        {
            cout << "�������� �����. ����������, ���������� �����." << endl;
        }
    }

    return 0;
}