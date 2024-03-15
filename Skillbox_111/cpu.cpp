#include "cpu.h"

int CPU::compute(int* memory)
{
	int sum = 0;
	for (int i = 0; i < 8; ++i)
	{
		sum += memory[i];
	}
	return sum;
}
