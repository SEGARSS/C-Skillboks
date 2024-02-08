#include <iostream>
#include <string>

using namespace std;

/*Задание 3. Валидация IP-адреса
Что нужно сделать
Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4). 
IP-адрес должен представлять из себя четыре числа, разделённые точками без пробелов, 
причём каждое число должно быть в диапазоне от 0 до 255 включительно. Числа не должны содержать ведущих нулей. 
Других символов в строке, кроме вышеописанных, быть не должно.
Пользователь вводит строку, задающую IP-адрес через стандартный ввод. 
В результате программа должна вывести слово Valid, если адрес корректен, и слово Invalid, если это не так.*/

//-------------------------------------------------------------------------------------------------
bool isValidOctet(const string& octet) 
{
	if (octet.empty() || octet.size() > 3 || (octet.size() > 1 && octet[0] == '0')) 
	{
		return false;
	}

	for (char c : octet) 
	{
		if (c < '0' || c > '9') 
		{
			return false;
		}
	}

	int num = stoi(octet);
	return num >= 0 && num <= 255;
}
//-------------------------------------------------------------------------------------------------
bool isValidIPAddress(const string& ipAddress) 
{
	int countDots = 0;
	string octet = "";

	for (char c : ipAddress) 
	{
		if (c == '.') 
		{
			if (!isValidOctet(octet)) 
			{
				return false;
			}
			octet = "";
			countDots++;
		}
		else 
		{
			octet += c;
		}
	}

	if (countDots != 3 || !isValidOctet(octet)) 
	{
		return false;
	}

	return true;
}
//-------------------------------------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL,"ru");

	string ipAddress;
	cout << "Введите ip адрес: ";
	cin >> ipAddress;

	if (isValidIPAddress(ipAddress)) 
	{
		cout << "Valid" << endl;
	}
	else 
	{
		cout << "Invalid" << endl;
	}

	return 0;
}
//-------------------------------------------------------------------------------------------------