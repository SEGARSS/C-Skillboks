#include <iostream>
#include <string>

using namespace std;

/*2. Реализация умного указателя
Что нужно сделать
1. Реализуйте умный указатель shared_ptr_toy с распределённым доступом и механикой подсчёта ссылок для класса Toy, 
реализованного в задании.
Указатель должен:
— иметь все стандартные методы класса,
— быть функциональной заменой использованию shared_ptr<Toy>.
2. Реализуйте свободную функцию make_shared_toy, 
которая принимает набор аргументов и конструирует игрушку от названия или при помощи копии другой игрушки.*/

//----------------------------------------------------------------------------------------------------
class Toy 
{
public:
	~Toy() 
	{
		cout << "Игрушка " << name_ << " была брошена" << endl;
	}

	Toy(const string& name) 
	: name_(name) 
	{
	}

	string getName() const 
	{
		return name_;
	}	

private:
	string name_;
};
//----------------------------------------------------------------------------------------------------
class shared_ptr_toy 
{
public:
	~shared_ptr_toy() 
	{
		if (count_ && --(*count_) == 0) {
			delete ptr_;
			delete count_;
		}
	}

	shared_ptr_toy() 
	: ptr_(nullptr), count_(nullptr) 
	{
	}

	shared_ptr_toy(Toy* toy) 
	: ptr_(toy), count_(new int(1)) 
	{
	}

	shared_ptr_toy(const shared_ptr_toy& other) 
	: ptr_(other.ptr_), count_(other.count_) 
	{
		if (count_) (*count_)++;
	}

	shared_ptr_toy& operator=(const shared_ptr_toy& other) 
	{
		if (this != &other) 
		{
			if (count_) (*count_)--;
			ptr_ = other.ptr_;
			count_ = other.count_;
			if (count_) (*count_)++;
		}
		return *this;
	}	

	Toy* get() const 
	{
		return ptr_;
	}

	Toy* operator->() const 
	{
		return ptr_;
	}

	Toy& operator*() const 
	{
		return *ptr_;
	}

	operator bool() const 
	{
		return ptr_ != nullptr;
	}

	friend shared_ptr_toy make_shared_toy(const string& name);

private:
	Toy* ptr_;
	int* count_;
};
//----------------------------------------------------------------------------------------------------
shared_ptr_toy make_shared_toy(const string& name) 
{
	Toy* toy = new Toy(name);
	return shared_ptr_toy(toy);
}
//----------------------------------------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL,"ru");

	shared_ptr_toy toy1 = make_shared_toy("Мяч");
	shared_ptr_toy toy2 = make_shared_toy("Кость");

	cout << "название игрушки 1: " << toy1->getName() << endl;
	cout << "название игрушки 2: " << (*toy2).getName() << endl;

	shared_ptr_toy toy3 = toy2;
	cout << "название игрушки 3: " << toy3->getName() << endl;

	return 0;
}
//----------------------------------------------------------------------------------------------------