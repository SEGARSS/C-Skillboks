#include<iostream>
#include<string>

using namespace std;

/*Задание 1. Шифр Цезаря
Что нужно сделать
В древности для шифрования сообщений использовался такой способ: 
все буквы в сообщении сдвигались на одно и то же число позиций в алфавите. 
Число позиций могло быть как положительным, так и отрицательным и являлось параметром шифра — его ключом. 
Если для сдвига на данное число позиций алфавита не хватает, 
то он зацикливается (то есть буква с номером 27 — это снова буква a, буква с номером 28 — это буква b и так далее).
Например, слово abracadabra при сдвиге на десять позиций превратится в klbkmknklbk. 
Этот простейший шифр называется шифром Цезаря. Регистр букв (заглавные и строчные) менять не нужно. 
Напишите функцию encrypt_caesar от строки и числа, которая возвращает исходную строку, 
зашифрованную шифром Цезаря с параметром, равным данному числу. Также напишите функцию decrypt_caesar, 
выполняющую обратное преобразование. Считаем, что входные строки состоят лишь из английских букв. 
Если там содержатся и другие символы, то их надо игнорировать.*/

//------------------------------------------------------------------------------------------------
string encrypt_caesar(const string & message, int shift)
{
	string encrypted_message = "";
	for (char symbol : message)
	{
		if (isalpha(symbol))
		{
			char base = islower(symbol) ? 'a' : 'A';
			int position = (symbol - base + shift) % 26;
			if (position < 0)
			{
				position += 26;
			}
			encrypted_message += base + position;
		}
		else
		{
			encrypted_message += symbol;
		}
	}
	return encrypted_message;
}
//------------------------------------------------------------------------------------------------
string dercypt_caesar(const string & encrypted_massage, int shift)
{
	return dercypt_caesar(encrypted_massage, -shift);
}
//------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	int shift;
	cout << "Введите значение сдвига:";
	cin>> shift;
	cin.ignore();

	string message;
	cout << "Введите сообщение:";
	getline(cin, message);

	string encrypted_message = encrypt_caesar(message, shift);
	cout << "Зашифрованное сообщение:" << encrypted_message << endl;

	string decrypted_message = dercypt_caesar(encrypted_message, shift);
   cout << "Расшифрованное сообщение: " << decrypted_message << endl;

	return 0;
}
//------------------------------------------------------------------------------------------------