#include <iostream>
#include <string>

using namespace std;

/*Задание 2. Проверка корректности email-адреса
Что нужно сделать
Напишите программу, которая проверяет корректность email-адреса, введённого пользователем.
Согласно международным требованиям, корректный email-адрес должен состоять из двух частей, разделённых знаком @. 
Первая часть должна иметь длину не менее одного и не более 64 символов, вторая часть — не менее одного и не более 63 символов. 
Из символов допускаются только английские буквы, цифры и знак «-» (дефис), а также точка. 
Точка не может быть первым или последним символом, а кроме того, две точки не могут идти подряд. 
В первой части (которая предшествует символу @), кроме вышеперечисленных, разрешены ещё следующие символы:
!#$%&'*+-/=?^_{|}~`
Пользователь вводит строку, задающую email-адрес. 
Программа должна вывести слово Yes, если адрес корректен, а в противном случае — слово No.*/

//-------------------------------------------------------------------------------------------------------------
bool isValidCharacter(char c) 
{
	return isalnum(c) || c == '-' || c == '.' || c == '!' || c == '#' || c == '$' ||
		c == '%' || c == '&' || c == '\'' || c == '*' || c == '+' || c == '-' ||
		c == '/' || c == '=' || c == '?' || c == '^' || c == '_' || c == '`' ||
		c == '{' || c == '|' || c == '}' || c == '~';
}
//-------------------------------------------------------------------------------------------------------------
bool isValidLocalPart(const string& localPart) 
{
	if (localPart.empty() || localPart.size() > 64 || localPart.front() == '.' || localPart.back() == '.') 
	{
		return false;
	}

	for (size_t i = 0; i < localPart.size(); ++i) 
	{
		if (!isValidCharacter(localPart[i])) 
		{
			return false;
		}
		if (localPart[i] == '.' && (i == 0 || i == localPart.size() - 1 || localPart[i - 1] == '.')) 
		{
			return false;
		}
	}

	return true;
}
//-------------------------------------------------------------------------------------------------------------
bool isValidDomainPart(const string& domainPart) 
{
	if (domainPart.empty() || domainPart.size() > 63 || domainPart.front() == '.' || domainPart.back() == '.') 
	{
		return false;
	}

	for (size_t i = 0; i < domainPart.size(); ++i) 
	{
		if (!isValidCharacter(domainPart[i])) 
		{
			return false;
		}
		if (domainPart[i] == '.' && (i == 0 || i == domainPart.size() - 1 || domainPart[i - 1] == '.')) 
		{
			return false;
		}
	}

	return true;
}
//-------------------------------------------------------------------------------------------------------------
bool isValidEmail(const string& email) 
{
	size_t atIndex = email.find('@');
	if (atIndex == string::npos || atIndex == 0 || atIndex == email.size() - 1) 
	{
		return false;
	}

	string localPart = email.substr(0, atIndex);
	string domainPart = email.substr(atIndex + 1);

	return isValidLocalPart(localPart) && isValidDomainPart(domainPart);
}
//-------------------------------------------------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL,"ru");

	string email;
	cout << "Введите адрес электронной почты: ";
	cin >> email;

	if (isValidEmail(email)) 
	{
		cout << "Yes" << endl;
	}
	else 
	{
		cout << "No" << endl;
	}

	return 0;
}
//-------------------------------------------------------------------------------------------------------------