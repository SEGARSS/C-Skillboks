#include<iostream>
#include<cstring>
using namespace std;

/**/

//--------------------------------------------------------------------------------------------------------
bool substr(const char *str, const char *sub)
{
	return strstr(str, sub) != nullptr;
}
//--------------------------------------------------------------------------------------------------------
int main()
{
	const char *a = "Hello world";
	const char *b = "wor";
	const char *c = "banana";

	cout << boolalpha << substr(a, b) << " " << substr(a, c) << endl;

	return 0;
}
//--------------------------------------------------------------------------------------------------------