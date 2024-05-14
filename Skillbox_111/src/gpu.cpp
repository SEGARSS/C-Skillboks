#include "gpu.h"
#include <iostream>

using namespace std;

void GPU::display(const int* memory)
{
	cout << "GPU: ";
	for (int i = 0; i < 8; ++i)
	{
		cout << memory[i] << " ";
	}
	cout << endl;
}
