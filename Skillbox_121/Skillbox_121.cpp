#include<iostream>
#include<vector>
#include<string>

using namespace std;

//------------------------------------------------------------------------------------------------------------
class Talent // Абстрактный класс талантов
{
public:
	virtual void show() const = 0; // Число виртуальныйх функций для показания способностей
};
//------------------------------------------------------------------------------------------------------------
class Swiming : public Talent // Класс для уменя плавать
{
public:
	void show() const override
	{
		cout << "Он умеет плавать" << endl;
	}
};
//------------------------------------------------------------------------------------------------------------
class Dancing : public Talent // Класс для умения танцевать
{
public:
	void show() const override
	{
		cout << "Он умеет танцевать" << endl;
	}
};
//------------------------------------------------------------------------------------------------------------
class Couting : public Talent // Класс для умения считать
{
public:
	void show() const override
	{
		cout << "Он умеет считать" << endl;
	}
};
//------------------------------------------------------------------------------------------------------------
class Dog // Класс Dog (Собака)
{
public:
	Dog (const string & _name)
	: name(_name)
	{
	}

	// Метод для добавления новой способности
	void addTalent(const Talent *talent)
	{
		talents.push_back(talent);
	}

	// Метод для показа всех способностей
	void show_talents() const
	{
		cout << "Это " << name << " и у него есть следующие таланты:" << endl;
		for (const auto &talent : talents)
		{
			talent->show();
		}
	}

private:
	string name;
	vector<const Talent*> talents; // Вектор для хранения указателей на способности
};
//------------------------------------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL,"ru");

	// Создаём собаку
	Dog dog1("Стив");

	// Добавляем умения
	Swiming swiming;
	Dancing dancing;
	Couting couting;

	dog1.addTalent(&swiming);
	dog1.addTalent(&dancing);
	dog1.addTalent(&couting);

	// Показываем все уменя
	dog1.show_talents();

	return 0;
}
//------------------------------------------------------------------------------------------------------------