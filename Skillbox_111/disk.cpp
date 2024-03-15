#include "disk.h"
#include <iostream>
#include <fstream>

using namespace std;

//---------------------------------------------------------
void Disk::save(const int* memory) 
{
	ofstream file("data.txt");
	if (file.is_open()) 
	{
		for (int i = 0; i < 8; ++i) 
		{
			file << memory[i] << " ";
		}
		file.close();
		cout << "Data saved to disk." << endl;
	}
	else 
	{
		cout << "Unable to open file." << endl;
	}
}
//---------------------------------------------------------
void Disk::load(int* memory) 
{
	ifstream file("data.txt");
	if (file.is_open()) 
	{
		for (int i = 0; i < 8; ++i) 
		{
			file >> memory[i];
		}
		file.close();
		cout << "Data loaded from disk." << endl;
	}
	else 
	{
		cout << "Unable to open file." << endl;
	}
}
//---------------------------------------------------------