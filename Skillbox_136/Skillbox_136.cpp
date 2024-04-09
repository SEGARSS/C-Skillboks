#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

/*Задание 3. Реестр данных на шаблонах
Что нужно сделать
С помощью шаблонов реализуйте простой класс реестра, хранящий произвольные типы значений по ключам произвольного типа.
Ключи при этом могут повторяться.
Реестр должен поддерживать следующие операции: добавление элемента с ключом, удаление элементов с заданным ключом,
вывод всех значений с ключами в консоль, поиск элементов по ключу.
Для тестирования программы предусмотрите ввод данных и команд из стандартной консоли:
• add — добавить элемент с ключом;
• remove — удалить все элементы с заданным ключом;
• print — напечатать на экране все элементы с их ключами;
• find — найти все элементы по их ключу.
Данный словарь должен работать на значениях и ключах следующих типов: int, double, std::string.*/

//---------------------------------------------------------------------------------------------------------------------
// Обобщенный шаблон для пары ключ-значение
template<typename K, typename V>
class KeyValuePair
{
public:
	K key;
	V value;

	// Конструктор
	KeyValuePair(const K& k, const V& v)
		: key(k), value(v)
	{
	}
};
//---------------------------------------------------------------------------------------------------------------------
// Обобщенный шаблон класса реестра
template<typename K, typename V>
class Registry
{
public:

	// Добавление элемента с ключом
	void add(const K& key, const V& value)
	{
		entries.push_back(KeyValuePair<K, V>(key, value));
	}

	// Удаление элементов с заданным ключом
	void remove(const K& key)
	{
		entries.erase(remove_if(entries.begin(), entries.end(), [&](const KeyValuePair<K, V>& entry) {
			return entry.key == key;
			}), entries.end());
	}

	// Вывод всех значений с ключами в консоль
	void print() const
	{
		for (const auto& entry : entries)
		{
			cout << "Key: " << entry.key << ", Value: " << entry.value << endl;
		}
	}

	// Поиск элементов по ключу
	vector<V> find(const K& key) const
	{
		vector<V> results;
		for (const auto& entry : entries)
		{
			if (entry.key == key)
			{
				results.push_back(entry.value);
			}
		}
		return results;
	}

private:
	vector<KeyValuePair<K, V>> entries;
};
//---------------------------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "ru");

	Registry<int, string> registry;

	try
	{
		while (true)
		{
			cout << "add - добавить элемент с ключом:" << endl;
			cout << "remove - удалить все элементы с заданным ключом:" << endl;
			cout << "print - напечатать на экране все элементы с их ключами:" << endl;
			cout << "find - найти все элементы по их ключу:" << endl;
			cout << "Введите команду: ";

			string command;
			cin >> command;

			if (command == "add")
			{
				int key;
				string value;
				cout << "Введите ключ и значение: ";
				cin >> key >> value;
				registry.add(key, value);
			}
			else if (command == "remove")
			{
				int key;
				cout << "Введите ключ для удаления: ";
				cin >> key;
				registry.remove(key);
			}
			else if (command == "print")
			{
				registry.print();
			}
			else if (command == "find")
			{
				int key;
				cout << "Введите ключ, чтобы найти: ";
				cin >> key;
				vector<string> results = registry.find(key);
				if (results.empty())
				{
					cout << "Не найдено записей для ключа " << key << endl;
				}
				else
				{
					cout << "Записи, найденные для ключа " << key << ": ";
					for (const auto& result : results)
					{
						cout << result << " ";
					}
					cout << endl;
				}
			}
			else
			{
				cout << "Неверная команда!" << endl;
			}
		}
	}
	catch (const exception& e)
	{
		cerr << "Ошибка: " << e.what() << endl;
		return 1;
	}

	return 0;
}
//---------------------------------------------------------------------------------------------------------------------