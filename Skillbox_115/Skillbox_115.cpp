#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

/*Задание 1. Реализация деревни эльфов
Что нужно сделать
Лесные эльфы расположили свою деревню в лесу, прямо на деревьях. 
Нужно расселить эльфов по веткам деревьев, а затем подсчитать общее количество соседей определённого эльфа.
Всего в лесу пять деревьев, каждое из которых генерируется с помощью случайных чисел, заданных в указанных далее диапазонах. 
На каждом дереве есть 3–5 основных больших ветвей. На каждой большой ветке расположены ещё 2-3 средние ветки. 
Дома эльфов построены на больших и на средних ветках. Более мелкие ветви не рассматриваются в этой задаче.
В начале программы пользователь размещает в каждом доме по одному эльфу. 
Делается это с помощью последовательного перебора всех имеющихся домов и запроса имени заселяемого эльфа через стандартный ввод. 
Если было введено None в качестве имени, то дом пропускается и не заселяется никем.
После этого требуется найти определённого эльфа по имени. Имя искомого эльфа вводится через стандартный ввод. 
Для найденного эльфа нужно вывести общее количество эльфов, живущих вместе с ним на одной большой ветви. 
Это и будет искомое количество соседей.*/

//---------------------------------------------------------------------------------------------------------
class Elf // Класс для представления эльфа
{
public:
	// Конструктор
	Elf(const string& name) : name(name) {}

	// Метод для получения имени эльфа
	string getName() const {
		return name;
	}

private:
	string name;
};
//---------------------------------------------------------------------------------------------------------
class Branch // Класс для представления ветки дерева
{
public:
	// Конструктор
	Branch() {}

	// Добавление эльфа на ветку
	void addElf(Elf* elf) 
	{
		elves.push_back(elf);
	}

	// Добавление дочерней ветки
	void addChildBranch(Branch* branch) 
	{
		children.push_back(branch);
	}

	// Рекурсивный метод для поиска эльфа по имени на текущей и дочерних ветках
	int findElf(const string& name) 
	{
		int count = 0;
		for (Elf* elf : elves) 
		{
			if (elf->getName() == name) 
			{
				count++;
			}
		}
		for (Branch* child : children) 
		{
			count += child->findElf(name);
		}
		return count;
	}

private:
	vector<Elf*> elves; // Вектор для хранения эльфов
	vector<Branch*> children; // Вектор для хранения дочерних веток
};
//---------------------------------------------------------------------------------------------------------
class Tree // Класс для представления дерева
{
public:
	// Конструктор
	Tree() : root(nullptr) {}

	// Добавление корневой ветки
	void setRootBranch(Branch* branch) {
		root = branch;
	}

	// Метод для поиска эльфа по имени
	int findElf(const string& name) {
		if (root == nullptr) {
			return 0;
		}
		return root->findElf(name);
	}

private:
	Branch* root; // Корневая ветка дерева
};
//---------------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, "ru");

	srand(time(nullptr)); // Инициализация генератора случайных чисел

	// Создаем дерево
	Tree tree;

	// Создаем корневые ветки для каждого дерева
	Branch* tree1 = new Branch();
	Branch* tree2 = new Branch();
	Branch* tree3 = new Branch();
	Branch* tree4 = new Branch();
	Branch* tree5 = new Branch();

	// Добавляем корневые ветки в дерево
	tree.setRootBranch(tree1);
	tree.setRootBranch(tree2);
	tree.setRootBranch(tree3);
	tree.setRootBranch(tree4);
	tree.setRootBranch(tree5);

	// Распределяем эльфов по веткам
	for (int i = 1; i <= 5; ++i) 
	{
		string elfName;
		cout << "Введите имя эльфа для дерева " << i << ": ";
		cin >> elfName;

		if (elfName != "None") 
		{
			Elf* elf = new Elf(elfName);
			switch (i) {
			case 1: tree1->addElf(elf); break;
			case 2: tree2->addElf(elf); break;
			case 3: tree3->addElf(elf); break;
			case 4: tree4->addElf(elf); break;
			case 5: tree5->addElf(elf); break;
			}
		}
	}

	// Поиск эльфа по имени
	string elfName;
	cout << "Введите имя эльфа для поиска: ";
	cin >> elfName;
	int neighbors = tree.findElf(elfName);

	// Выводим количество соседей
	cout << "Количество соседей для эльфа " << elfName << ": " << neighbors << endl;

	// Освобождаем память
	delete tree1;
	delete tree2;
	delete tree3;
	delete tree4;
	delete tree5;

	return 0;
}
//---------------------------------------------------------------------------------------------------------