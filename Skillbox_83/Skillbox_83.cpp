﻿#include<iostream>
#include<string>
using namespace std;

/*3. Подсчёт количества слов
Что нужно сделать
Напишите программу, которая считает количество слов в тексте, введённом пользователем. 
Словом считается любая последовательность символов (не обязательно букв) без пробелов.

Пользователь вводит строку, состоящую из произвольных символов и пробелов. 
Программа должна вывести одно число — количество слов во введённой строке.*/

//-----------------------------------------------------------------------------------------------
int countWords(const string &text)
{
	int count = 0;
	bool inWord = false;

	for (char c : text)
	{
		if (isspace(c))
		{//Если встретился пробел, переключаем флаг внутри слова

			if (inWord)
			{
				inWord = false;
			}
		}
		else
		{//Если встретился символ, увеличиваем счетчик слов, если мы не внутри слова

			if (!inWord)
			{
				inWord = true;
				++count;
			}
		}
	}

	return count;
}
//-----------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	string input;
	cout << "Введи строку: ";
	getline(cin, input);

	int wordCount = countWords(input);
	cout << "Ответ: " << wordCount << endl;

	return 0;
}
//-----------------------------------------------------------------------------------------------