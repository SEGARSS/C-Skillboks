﻿#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <cstdlib>

using namespace std;

/*Задание 3. Симуляция работы кухни онлайн-ресторана
Что нужно сделать
Требуется реализовать упрощённую модель работы кухни ресторана, работающего в режиме онлайн-доставки.
Онлайн-заказ поступает каждые 5–10 секунд. Это случайное блюдо из пяти: пицца, суп, стейк, салат, суши. 
Официант, принявший заказ онлайн, оставляет его у кухни. 
Если кухня свободна, она принимает заказ и спустя 5–15 секунд возвращает уже готовое блюдо на выдачу. 
Время определяется случайным образом с помощью функции std::rand() в указанных диапазонах.
Курьер приезжает каждые 30 секунд, забирает готовые блюда на выдаче и развозит их по заказчикам.
Программа завершается после 10 успешных доставок. На каждом из этапов, будь то заказ, или готовка, 
или доставка заказа, выводятся соответствующие сообщения в консоль.*/

//------------------------------------------------------------------------------------------------------------
mutex mtx;
condition_variable cv;
bool kitchenReady = true;
int deliveriesCount = 0;
//------------------------------------------------------------------------------------------------------------
void cookDish(const string& dishName) // Функция, представляющая приготовление блюда на кухне
{
	// Генерируем случайное время приготовления блюда
	int cookTime = rand() % 11 + 5; // От 5 до 15 секунд
	// Ожидаем время приготовления
	this_thread::sleep_for(chrono::seconds(cookTime));

	// Выводим сообщение о готовности блюда
	cout << "Готово блюдо: " << dishName << endl;
}
//------------------------------------------------------------------------------------------------------------
void deliverDish(int deliveryNumber) // Функция, представляющая доставку блюда клиенту
{
	// Генерируем случайное время доставки
	int deliveryTime = 30; // Доставка происходит каждые 30 секунд
	// Ожидаем время доставки
	this_thread::sleep_for(chrono::seconds(deliveryTime));

	// Выводим сообщение о доставке блюда клиенту
	cout << "Блюдо " << deliveryNumber << " доставлено клиенту" << endl;

	// Увеличиваем счетчик доставок
	deliveriesCount++;
}
//------------------------------------------------------------------------------------------------------------
void kitchen() // Функция, представляющая работу кухни
{
	while (deliveriesCount < 10) 
	{
		// Проверяем, есть ли заказы на кухне
		if (kitchenReady) 
		{
			// Генерируем случайное блюдо
			string dish;
			switch (rand() % 5) 
			{
			case 0:
				dish = "пицца";
				break;
			case 1:
				dish = "суп";
				break;
			case 2:
				dish = "стейк";
				break;
			case 3:
				dish = "салат";
				break;
			case 4:
				dish = "суши";
				break;
			}

			// Заказ принят, кухня занята
			kitchenReady = false;
			cout << "Заказ принят: " << dish << endl;

			// Запускаем процесс приготовления блюда в отдельной нити
			thread(cookDish, dish).detach();
		}

		// Ждем некоторое время перед следующим заказом
		this_thread::sleep_for(chrono::seconds(rand() % 6 + 5)); // От 5 до 10 секунд

		// Переводим кухню в режим ожидания
		kitchenReady = true;
	}
}
//------------------------------------------------------------------------------------------------------------
void courier() // Функция, представляющая работу курьера
{
	while (deliveriesCount < 10) 
	{
		// Доставляем готовые блюда клиентам
		deliverDish(deliveriesCount + 1);
	}
}
//------------------------------------------------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL, "ru");
	srand(time(nullptr));

	// Запускаем нити кухни и курьера
	thread kitchenThread(kitchen);
	thread courierThread(courier);

	// Ждем завершения работы нитей
	kitchenThread.join();
	courierThread.join();

	return 0;
}
//------------------------------------------------------------------------------------------------------------