﻿#include <iostream>
#include <memory>
#include <string>

using namespace std;

/*. Использование умного указателя
Что нужно сделать
1. Реализуйте класс Dog, который использует стандартный умный указатель shared_ptr для класса Toy.
2. Реализуйте у класса Dog метод getToy, с помощью которого собака подбирает игрушку.
— Если у собаки уже есть эта игрушка, необходимо вывести в консоль фразу: I already have this toy.
— Если в данный момент игрушка находится у другой собаки, нужно вывести в консоль: Another dog is playing with this toy.
— Если игрушка свободна, собака подбирает её.
3. Реализуйте у класса Dog метод dropToy, с помощью которого собака бросает игрушку на пол, 
после чего другая может подобрать её.
— Если у собаки в этот момент нет игрушки, в консоль необходимо вывести: Nothing to drop..;*/

//----------------------------------------------------------------------------------------------------
class Toy 
{
public:
	~Toy() 
	{
		cout << "Игрушка " << name_ << " была брошена" << endl;
	}

	Toy(const string& name) 
	{
		name_ = name;
	}

	string getName() 
	{
		return name_;
	}	

private:
	string name_;
};
//----------------------------------------------------------------------------------------------------
class Dog 
{
public:
	void getToy(shared_ptr<Toy> toy) 
	{
		if (toy_ == toy) 
		{
			cout << "У меня уже есть эта игрушка." << endl;
		}
		else if (toy_) 
		{
			cout << "Другая собака играет с этой игрушкой." << endl;
		}
		else 
		{
			toy_ = toy;
			cout << "У меня появилась новая игрушка: " << toy_->getName() << endl;
		}
	}

	void dropToy() 
	{
		if (toy_) 
		{
			cout << "Я уронил игрушку: " << toy_->getName() << endl;
			toy_.reset();
		}
		else 
		{
			cout << "Нечего бросать." << endl;
		}
	}

private:
	shared_ptr<Toy> toy_;
};
//----------------------------------------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL,"ru");

	Dog dog1, dog2;
	shared_ptr<Toy> toy1 = make_shared<Toy>("Мяч");
	shared_ptr<Toy> toy2 = make_shared<Toy>("Кость");

	dog1.getToy(toy1);  // собака 1 получает игрушечный "мячик"
	dog1.getToy(toy2);  // собака 1 пытается достать игрушечную "Кость", но она уже есть у
	dog2.getToy(toy2);  // собака 2 снова пытается достать игрушечную "кость"

	dog1.dropToy();     // собака 1 роняет игрушечный "мячик"
	dog1.getToy(toy1);  // собака 1 снова получает игрушечный "мячик"

	return 0;
}
//----------------------------------------------------------------------------------------------------