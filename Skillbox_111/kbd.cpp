#include "kbd.h"
#include <iostream>

using namespace std;

void KBD::input(int* memory)
{
	cout << "Enter 8 numbers: ";
	for (int i = 0; i < 8; ++i)
	{
		cin >> memory[i];
	}
}
