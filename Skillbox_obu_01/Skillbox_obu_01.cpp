#include<iostream>
using namespace std;


//--------------------------------------------------------------------
struct Color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};
//--------------------------------------------------------------------
Color frameBuffer[1920 * 1080];
//--------------------------------------------------------------------
int main()
{
	Color red {255, 0, 0};

	cout << "Red color values:" << endl;
    cout << "R: " << static_cast<int>(red.r) << endl;
    cout << "G: " << static_cast<int>(red.g) << endl;
    cout << "B: " << static_cast<int>(red.b) << endl;
    cout << "A: " << static_cast<int>(red.a) << endl;

    cout << "Color: #" << hex << static_cast<int>(red.r) << static_cast<int>(red.g) << static_cast<int>(red.b) << dec << endl;

	return 0;
}
//--------------------------------------------------------------------