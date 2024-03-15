#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

/*Задание 3. Реализация программы таймера
Что нужно сделать
Реализуйте работу точного таймера с визуальной отдачей.
В начале программы пользователь вводит количество минут и секунд, которые требуется засечь на таймере, и нажимает «Ввод».
После этого начинается обратный отсчёт времени, о чём незамедлительно и последовательно сообщается пользователю. 
Формат вывода такой же, как и при вводе интервала: минуты и секунды.
Как только отсчёт на таймере иссяк, программа сообщает об этом с помощью вывода в консоль специального сообщения. 
Сообщение вместо аудиосигнала может выглядеть так: DING! DING! DING!*/

int main()
{
	setlocale(LC_ALL, "ru");
	int minutes, seconds;

	cout << "Введите количество минут: ";
	cin >> minutes;
	cout << "Введите количество секунд: ";
	cin >> seconds;

	// Вычисляем время окончания таймера
	time_t endTime = time(nullptr) + minutes * 60 + seconds;

	// Выводим сообщение о начале отсчета
	cout << "Таймер запущен!" << endl;

	// Основной цикл отсчета времени
	while (time(nullptr) < endTime) 
	{
		// Вычисляем оставшееся время
		int remainingSeconds = endTime - time(nullptr);

		// Переводим оставшееся время в минуты и секунды
		int remainingMinutes = remainingSeconds / 60;
		remainingSeconds %= 60;

		// Выводим оставшееся время
		cout << setw(2) << setfill('0') << remainingMinutes << ":"
			<< setw(2) << setfill('0') << remainingSeconds << endl;

		// Ждем 1 секунду перед следующим обновлением
		this_thread::sleep_for(chrono::seconds(1));
	}

	// Выводим сообщение о завершении отсчета
	cout << "DING! DING! DING! Таймер завершен!" << endl;

	return 0;
}
