#include <iostream>
#include "medical_tools.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	Point startPoint, endPoint;

	cout << "�������� ��������." << endl;

	startPoint = inputPoint();
	endPoint = inputPoint();

	scalpel(startPoint, endPoint);

	hemostat(inputPoint());

	tweezers(inputPoint());

	startPoint = inputPoint();
	endPoint = inputPoint();

	suture(startPoint, endPoint);

	cout << "�������� ���������." << endl;

	return 0;
}
