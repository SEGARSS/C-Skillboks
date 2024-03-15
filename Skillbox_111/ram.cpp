#include "ram.h"
#include <iostream>

using namespace std;

//---------------------------------------------------------
void RAM::write(int* memory, const int* data)
{
	for (int i = 0; i < 8; ++i)
	{
		memory[i] = data[i];
	}
}
//---------------------------------------------------------
void RAM::read(const int* memory)
{
	cout << "RAM: ";
	for (int i = 0; i < 8; ++i)
	{
		cout << memory[i] << " ";
	}
	cout << endl;
}
//---------------------------------------------------------
