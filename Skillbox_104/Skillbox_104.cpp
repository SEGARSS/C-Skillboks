#include<iostream>
#include<string>
using namespace std;

/*Задание 1. Реализация продвинутого ввода и вывода дней недели
Что нужно сделать
Используя макросы, реализуйте небольшую программу по вводу дня недели и выводу этого дня недели в текстовом виде в консоль.
В начале программы пользователь вводит день недели в виде его порядкового номера. 
В результате в консоли появляется буквенное отображение этого дня недели.
В этом упражнении запрещается использовать классические переменные, 
кроме как для хранения ввода пользователя. Использовать строковые литералы напрямую тоже нельзя. 
Всё должно быть реализовано исключительно на макросах.*/

#define DAY_OF_WEEK_1
#define DAY_OF_WEEK_2
#define DAY_OF_WEEK_3
#define DAY_OF_WEEK_4
#define DAY_OF_WEEK_5
#define DAY_OF_WEEK_6
#define DAY_OF_WEEK_7

#define STRINGIZE(x) #x

#define DAY_OF_WEEK_STRING(x) \
    if (x == 1) { cout << STRINGIZE(DAY_OF_WEEK_1) << " (" << STRINGIZE(Понедельник) << ")" << endl; } \
    else if (x == 2) { cout << STRINGIZE(DAY_OF_WEEK_2) << " (" << STRINGIZE(Вторник) << ")" << endl; } \
    else if (x == 3) { cout << STRINGIZE(DAY_OF_WEEK_3) << " (" << STRINGIZE(Среда) << ")" << endl; } \
    else if (x == 4) { cout << STRINGIZE(DAY_OF_WEEK_4) << " (" << STRINGIZE(Четверг) << ")" << endl; } \
    else if (x == 5) { cout << STRINGIZE(DAY_OF_WEEK_5) << " (" << STRINGIZE(Пятница) << ")" << endl; } \
    else if (x == 6) { cout << STRINGIZE(DAY_OF_WEEK_6) << " (" << STRINGIZE(Суббота) << ")" << endl; } \
    else if (x == 7) { cout << STRINGIZE(DAY_OF_WEEK_7) << " (" << STRINGIZE(Воскресенье) << ")" << endl; } \
    else { cout << "Недопустимый день недели." << endl; }

int main()
{
	setlocale(LC_ALL,"ru");

	int day;
	cout << "Введите день недели (1-7): ";
	cin >> day;

	DAY_OF_WEEK_STRING(day);

	return 0;
}