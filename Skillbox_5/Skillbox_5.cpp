#include<iostream>
#include<string>
using namespace std;

int main()
{
	setlocale(LC_ALL,"ru");

	string plant = "Бамбука";
	int dailyGrowth = 50;   //Ежедневный рост бамбука.
	int nightFade = 20;    //Размер съедаемого гусеницами бамбука за одну ночь.
	int beginHeight = 100;//Начальная высота бамбука.
	int fullDay = 2;     //(Полный день) Количество дней (можно ставить столько, сколько потребуеться)
	int notFDay = dailyGrowth / fullDay; //Не полный день (середина)

	cout << "Прирост " << plant << " в середине третьего дня = " << beginHeight + (dailyGrowth - nightFade) * fullDay + notFDay << endl;

	/*Программа модернизированна так, чтобы небыло мефических чисел, они заменены переменными,
	поэтому программу можно сразу легко поменять для подсчёта полных дней (любова количества),
	так и добавить если требуеться высчитать не полные дни.*/
}