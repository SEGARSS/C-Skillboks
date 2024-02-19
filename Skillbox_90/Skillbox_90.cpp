#include<iostream>
#include<string>
#include<fstream>
#include <unordered_map>
using namespace std;

/*Задание 1. Разработка программы поиска слов в файле
Что нужно сделать
Составьте небольшой текстовый файл «words.txt», в котором последовательно, 
через пробелы и переносы строк расположены различные слова. Можете использовать любые англоязычные слова. 
Разработайте программу, которая искала бы среди этих слов нужное пользователю и выводила бы общее количество повторений этого слова. 
0 — если слово вообще не присутствует в файле.*/

int main()
{
	setlocale(LC_ALL,"ru");

	string path = "words.txt"; 

	ofstream fout; 

	fout.open(path, ofstream::app); 

	fout.close();

	ifstream fin; // Команда считывания файла 
	fin.open(path); // Вывод на консоль

	if ( !fin.is_open() ) // Вывод на консоль
	{
		cout << "Ошибка открытия файла! " << endl;
	}
	else
	{
		cout << "Файл открыт! " << endl;
	}

	unordered_map<string, int> wordCount;

	string word;
	while (fin >> word) 
	{
		wordCount[word]++;
	}

	fin.close();

	cout << "Введите слово для поиска: ";
   string searchWord;
   cin >> searchWord;
    
	// Поиск и вывод количества повторений слова
	if (wordCount.find(searchWord) != wordCount.end())
	{
		cout << "Количество повторений слова \"" << searchWord << "\": " << wordCount[searchWord] << endl;
	}
	else
	{
		cout << "Слово \"" << searchWord << "\" не найдено в файле." << endl;
	}
	
	return 0;
}