#include<iostream>
using namespace std;

int main()
{
	/*Задание 2*/
	setlocale(LC_ALL,"ru");

	int a = 42;
	int b = 153;
	int temp;

	cout << a << endl;
	cout << b << endl << endl;

	temp = a;
	a = b;
	b = temp;
			
	cout << a << endl;
	cout << b << endl;
}