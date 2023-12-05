#include<iostream>
using namespace std;

int main()
{
	/*Задание 2*/
	setlocale(LC_ALL,"ru");

	int a = 42;
	int b = 153;
	int temp;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl << endl;

	temp = a;
	a = b;
	b = temp;
			
	cout << "a: " << a << endl;
	cout << "b: " << b << endl << endl;

	/*Задание 4*/

	int x = 42;
	int y = 153;

	cout << "x: " << x << endl;
	cout << "y: " << y << endl << endl;

	x = x + y;
	y = x - y;
	x = x - y;

	cout << "x: " << x << endl;
	cout << "y: " << y << endl << endl;
}