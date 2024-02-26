#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/*Задание 3. Реализация симуляции игры «Рыбалка»
Что нужно сделать
Реализуйте простую симуляцию игры в рыбалку. В исходном текстовом файле реки (river.txt) задаётся список из видов рыб, 
которые можно в ней поймать. Рыбок может быть сколько угодно, разных видов. Виды при этом могут повторяться.
В начале программы пользователь указывает, какую именно рыбу он сейчас будет ловить — вид этой рыбы. 
После этого из первого файла друг за другом осуществляется чтение его содержимого, вид за видом. 
Если на отдельных шагах вид совпал с указанным пользователем, в выходной файл basket.txt (корзинка) записывается этот вид.
В конце программы показывается, сколько было поймано рыб за текущую ловлю. Программу можно запускать несколько раз, 
при этом уже пойманные рыбы должны сохраняться в файле-корзинке.*/

//-----------------------------------------------------------------------------------
vector<string> readRiverFish(const string& filename)// Функция для чтения списка рыб из файла 
{
	vector<string> fishList;
	ifstream inFile(filename);
	if (!inFile) 
	{
		cerr << "Ошибка открытия файла." << endl;
		exit(1);
	}
	string fish;
	while (inFile >> fish) 
	{
		fishList.push_back(fish);
	}
	inFile.close();
	return fishList;
}
//-----------------------------------------------------------------------------------
void writeBasketFish(const string& filename, const vector<string>& fishBasket)// Функция для записи пойманных рыб в файл-корзинку 
{
	ofstream outFile(filename, ios::app);
	if (!outFile) 
	{
		cerr << "Ошибка открытия файла." << endl;
		exit(1);
	}
	for (const auto& fish : fishBasket) 
	{
		outFile << fish << endl;
	}
	outFile.close();
}
//-----------------------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL, "ru");

	string targetFish;
	int totalCaughtFish = 0;
	while (true) 
	{
		// Чтение списка рыб из файла реки
		vector<string> riverFish = readRiverFish("river.txt");

		// Запрос пользователя о виде рыбы, которую он сейчас будет ловить
		cout << "Какую рыбу вы будете ловить? (Введите 'stop' для завершения) ";
		cin >> targetFish;

		// Проверка на завершение программы
		if (targetFish == "stop") 
		{
			break;
		}

		// Создание вектора для записи пойманных рыб
		vector<string> fishBasket;

		// Ловля рыбы
		for (const auto& fish : riverFish) 
		{
			// Если поймана целевая рыба, добавляем ее в корзинку
			if (fish == targetFish) 
			{
				fishBasket.push_back(fish);
				totalCaughtFish++;
			}
		}

		// Запись пойманных рыб в файл-корзинку
		writeBasketFish("basket.txt", fishBasket);

		// Вывод количества пойманных рыб
		cout << "Было поймано " << fishBasket.size() << " рыб." << endl;
	}

	// Вывод общего количества пойманных рыб
	cout << "Всего было поймано " << totalCaughtFish << " рыб." << endl;

	return 0;
}
//-----------------------------------------------------------------------------------