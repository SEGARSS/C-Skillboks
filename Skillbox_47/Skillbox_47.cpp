#include<iostream>
#include<string>
using namespace std;

/*Перепишите программу из прошлого модуля, только теперь вместо цикла while используйте цикл for. 
Программа просит пользователя ввести пароль. Если пароль неверный, программа просит сделать это снова, 
и так до тех пор, пока пользователь не введёт правильный пароль.*/

int main()
{
	setlocale(LC_ALL,"ru");

	int password;
	

	int error = 0;

	for (;;)
	{
		cout << "Введите пароль - ";
		cin>>password;
		
		error++;

		if (password == 2325)
		{
			cout << "Вы ввели верный пароль" << password << endl;
			cout << "Количество неправильных вводов пароля - " << error << endl;
			break;
		}
		else if (error >= 3)
		{
			cout << "Система заблокировала доступ на вход из за 3х использованных попыток! " << endl;
			break;
		}
		else
		{
			cout << "Вы ввели не верный пароль " << endl;
		}
	}

	return 0;
}