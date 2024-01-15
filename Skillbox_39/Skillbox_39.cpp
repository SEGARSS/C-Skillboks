﻿#include<iostream>
#include<string>
using namespace std;

/*Задание 3. Коллекторы
Что нужно сделать
Напишите робота для коллекторов.
В самом начале он спрашивает имя должника и сумму долга, 
а затем начинает требовать у него погашения долга до тех пор, пока тот не будет погашен полностью. 
Сумма долга должна уменьшаться, если пользователь ввёл сумму, меньшую чем сумма долга. 
Если пользователь внёс большую сумму, чем требуется для погашения, выведите сообщение о том, 
какой у него остаток на счету после такой операции. Обеспечьте контроль ввода.

Рекомендации по выполнению
При полной выплате долга необходимо учитывать остаток на счету, если он имеется.

Что оценивается
Правильно считается остаток после полного погашения долга.
Программа прекращает выполнение после того, как долг полностью погашен.
При задании отрицательного долга программа выводит предупреждение и прекращает выполнение.*/

int main()
{
	setlocale(LC_ALL,"ru");

	string name;
	int debt;

	cout << "Введите имя должника: ";
	cin >> name;

	cout << "Введите сумму долга: ";
	cin >> debt;

	int payment = 0;
	int quenching = 0;

	while (debt > payment)
	{
		int sum = debt - payment;

		cout << "Уважаемый(ая) " << name << ", погасите задолженность в размере " << sum << "." << endl;
		cout << "Какую сумму внесете? ";
		cin >> quenching;

		if (quenching < 0)
		{ // проверка на отрицательное погашение
			cout << "Ошибка: погашение не может быть отрицательным." << endl;
			continue;
		}

		payment += quenching; // увеличиваем общую сумму погашения на введенную сумму

		if (payment > debt)
		{ // если общая сумма погашения больше долга
			cout << "Вы внесли слишком большую сумму. Ваш остаток: " << payment - debt << endl;
			break; // выходим из цикла
		}
		else
		{
			cout << "Ваша задолженность составляет: " << debt - payment << "." << endl;
		}
	}

	cout << "Долг полностью погашен! Ваш остаток на счету: " << payment - debt << "." << endl;

	return 0;
}

