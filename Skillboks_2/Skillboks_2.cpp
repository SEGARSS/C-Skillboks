#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	cout << "������� 1.\n��������� ��� ��������� ���, \n����� �������� �������� �������������� �������������.\n�������� � ��� ����� ����������� ���������, ���� � ���� ����� ���������� ����� � �����." << endl << endl;
	cout << "�������" << endl;
	int lap = 4;
	int engine = 254;
	int wheels = 93;
	int steerinWheel = 49;
	int wind = 21;
	int rain = 17;
	
	int speed = engine + wheels + steerinWheel - wind -  rain;

	cout << "-------------------\n";
	cout << "����� �����. ���� " << lap << "\n";
	cout << "-------------------\n";
	cout << "������� (" << speed << ")\n";
	cout << "-------------------\n";
	cout << "��������: �������\n";
	cout << "��������: " << speed << "\n";
	cout << "-------------------\n";
	cout << "���������\n";
	cout << "���������: +" << engine << "\n";
	cout << "������: +" << wheels << "\n";
	cout << "����: +" << steerinWheel << "\n";
	cout << "-------------------\n";
	cout << "�������� ������ ������\n";
	cout << "�����: -" << wind << "\n";
	cout << "�����: -" << rain << "\n";

	cout << "====================================================" << endl << endl;

	cout << "������� 2." << endl;
	cout << "����������� ��������� ������." << endl;
	cout << "�������� ����������� ��� ������� ������ ��������� ������." << endl;
	cout << "��� �������������� ���: ��������� ������  + ��������� �������� � ������." << endl;
	cout << "��� �������� ��������� � ���������� � �������� � ������ ������, �������� ���� ������ (���� ��� cout)." << endl << endl;
	cout << "�������" << endl;
	
	int product = 70;
	cout << "��������� ������ - " << product << endl;
	int delivery = 30;
	cout << "��������� �������� - " << delivery << endl;
	int discount = 5;
	cout << "������ �� ����� - " << discount << endl; 

	int priceProduct = product + delivery - discount;

	cout << "� ������ ��������� ������ - " << product << "," << " ��������� �������� - " 
		  << delivery << ",\n" << "� ����������� ������ � - " << discount << "%," 
		  << " �������� ����� � ������ �� ����� ������� - " << priceProduct << endl;

	cout << "====================================================" << endl << endl;

	cout << "������� 3." << endl;
	cout << "�����, �����!" << endl;
	cout << "�������� ��������� ��� ��������� �������� ������� ��������� � �����." << endl;
	cout << "�������� ����� �����, ����� ���������� �������� ������ ��������� ���� ������ �� ������� �����." << endl;
	cout << "����� �� ������������ ������������ �� �������," << endl;
	cout << "�� ������� ������ ������ �����, � �������, �� ������� ������ �������� ����� � ����� ��� �������." << endl;
	cout << "��� ������� ��������� � �������." << endl;
	cout << "��� �������� ��������� � ���������� � �������� � ������ ������, �������� ���� ������." << endl;
	cout << "�������" << endl << endl;

	cout << "��� ��������� ����������, ������� �������� ������ ��������� ������ �� �����." << endl;

	int workShift;
	cout << "������� ������������ ����� ������� � ������� - ";
	cin >> workShift;
	int client;
	cout << "������� � ������� ����� ������ ������ �����? - ";
	cin >> client;
	int cashier;
	cout << "������� ����� ������ �������� �����? - ";
	cin >> cashier;
	int result = workShift / (client + cashier);
	cout << "�� �������� �����������, �� ����� � - " << workShift << " ����� " <<endl;
	cout << "������ ������ ��������� " << result << " ��������" <<endl;

	cout << "====================================================" << endl << endl;

	cout << "������� 4." << endl;
	cout << "���������� ���������." << endl;
	cout << "����������� �������� ��������� �������� ���������:" << endl;
	cout << "� ��� ������� ������ ������ ��������� ������� ���������������� ����," << endl;
	cout << "� ������� ������ ������� ���������� �������� � ���������." << endl;
	cout << "�������� ���������, � ������� ������� ������ ������� ������ ���������, ����� ����� �� ���� ���������." << endl;
	cout << "����� ������� �� ��� �������� ��� ����������� �� �������," << endl;
	cout << "���������� ������� � ������." << endl;
	cout << "��� �������� ��������� � ���������� � �������� � ������ ������, �������� ���� ������." << endl;
	cout << "�������" << endl << endl;

	int fullRepair;
	cout << "������� ������, ������� ������� ������� ��������� �������? - ";
	cin >> fullRepair;
	int numEntrance;
	cout << "������� ���������� ��������� � ���� - ";
	cin >> numEntrance;
	int flat;
	cout << "������� ���������� ������� � ����� �������� - ";
	cin >> flat;
	int receipt = fullRepair / numEntrance / flat;
	cout << "������ �������� ������ ������� �� - " << receipt <<endl;
}

