#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

/*Задание 4. Убийца Steam
Что нужно сделать
Вы пишете программу-инсталлятор для компьютерной игры. 
Пока обновление скачивается, пользователю нужно показать прогресс загрузки, чтобы он мог решить, 
подождать ему у экрана компьютера или заварить чай.
Напишите программу, 
принимающую на вход размер файла обновления в мегабайтах и скорость интернет-соединения в мегабайтах в секунду. 
В каждую секунду программа показывает, сколько процентов от общего объёма обновления уже скачано, 
до тех пор, пока файл не загрузится. После установки обновления программа выводит время в секундах, 
которое заняло скачивание. Обеспечьте контроль ввода.*/

int main() 
{
	setlocale(LC_ALL, "ru");

	double fileSize, downloadSpeed;

	cout << "Укажите размер файла для скачивания (в МБ): ";
	while (!(cin >> fileSize) || fileSize <= 0) 
	{
		cout << "Ошибка ввода. Введите положительное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "Какова скорость вашего соединения (в МБ/с)? ";
	while (!(cin >> downloadSpeed) || downloadSpeed <= 0) 
	{
		cout << "Ошибка ввода. Введите положительное число: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	int seconds = static_cast<int>(ceil(fileSize / downloadSpeed));

	for (int i = 1; i <= seconds; ++i) 
	{
		int downloaded = static_cast<int>(downloadSpeed * i);
		int percent = static_cast<int>((downloaded / fileSize) * 100);

		cout << "Прошло " << i << " сек. Скачано " << downloaded << " из " << static_cast<int>(fileSize) << " МБ (" << percent << "%)." << endl;
	}

	cout << "Прошло " << seconds << " сек. Скачивание завершено." << endl;

	return 0;
}