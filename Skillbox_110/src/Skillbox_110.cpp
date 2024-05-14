#include <iostream>
#include "medical_tools.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	Point startPoint, endPoint;

	cout << "Операция началась." << endl;

	startPoint = inputPoint();
	endPoint = inputPoint();

	scalpel(startPoint, endPoint);

	hemostat(inputPoint());

	tweezers(inputPoint());

	startPoint = inputPoint();
	endPoint = inputPoint();

	suture(startPoint, endPoint);

	cout << "Операция завершена." << endl;

	return 0;
}
