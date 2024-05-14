#ifndef RAM_H
#define RAM_H

class RAM
{
public:
	static void write(int* memory, const int* data);
	static void read(const int* memory);
};

#endif // RAM_H
