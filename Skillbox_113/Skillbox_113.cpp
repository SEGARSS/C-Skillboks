#include <iostream>
#include <map>
#include <string>

using namespace std;

/*Задание 2. Реализация программы симуляции мобильного телефона
Что нужно сделать
Реализуйте программу простой симуляции работы мобильного телефона.
По мобильному телефону можно звонить и отправлять СМС. Также мобильный телефон содержит адресную книгу. 
Телефон и отдельные записи адресной книги должны быть реализованы с помощью классов. 
Все номера телефонов задаются в формате +7 <10 цифр>.

Пользователь взаимодействует с программой с помощью команд:

• Команда add добавляет в адресную книгу новый номер телефона и ассоциирует его с именем контакта. 
Оба эти параметра команда получает от пользователя через стандартный ввод.
• Команда call запрашивает у пользователя имя контакта или номер телефона, на который требуется позвонить. 
Сам по себе звонок симулируется с помощью вывода в консоль сообщения CALL с номером телефона, на который осуществляется вызов.
• Команда sms. Запрашивает у пользователя номер телефона (или имя контакта), на который требуется послать сообщение. 
Само сообщение также вводится через стандартный ввод.
• Команда exit — выход из программы.*/

//---------------------------------------------------------------------------------------------
class PhoneNumber // Класс для представления номера телефона
{
public:
	// Конструктор
	PhoneNumber(const string& number)
	: number(number) 
	{
	}

	// Метод для получения номера телефона
	string getNumber() const 
	{
		return number;
	}

private:
	string number;
};
//---------------------------------------------------------------------------------------------
class Contact // Класс для представления контакта в адресной книге
{
public:
	// Конструктор
	Contact(const string& name, const string& number) 
	: name(name), phoneNumber(number) 
	{
	}

	// Метод для получения имени контакта
	string getName() const 
	{
		return name;
	}

	// Метод для получения номера телефона контакта
	string getPhoneNumber() const 
	{
		return phoneNumber.getNumber();
	}

private:
	string name;
	PhoneNumber phoneNumber;
};
//---------------------------------------------------------------------------------------------
class MobilePhone // Класс для представления мобильного телефона
{
public:
	// Деструктор для освобождения памяти
	~MobilePhone()
	{
		for (auto it = addressBook.begin(); it != addressBook.end(); ++it)
		{
			delete it->second;
		}
	}

	// Метод для добавления контакта в адресную книгу
	void addContact(const string& name, const string& number) 
	{
		addressBook[name] = new Contact(name, number);
	}

	// Метод для симуляции звонка
	void call(const string& contactOrNumber) 
	{
		if (addressBook.count(contactOrNumber)) 
		{
			cout << "Вызов " << addressBook[contactOrNumber]->getPhoneNumber() << endl;
		}
		else 
		{
			cout << "Вызов " << contactOrNumber << endl;
		}
	}

	// Метод для симуляции отправки SMS
	void sendSMS(const string& contactOrNumber, const string& message) 
	{
		if (addressBook.count(contactOrNumber)) 
		{
			cout << "SMS, отправленное на " << addressBook[contactOrNumber]->getName() << " (" << addressBook[contactOrNumber]->getPhoneNumber() << "): " << message << endl;
		}
		else 
		{
			cout << "SMS, отправленное на " << contactOrNumber << ": " << message << endl;
		}
	}

private:
	map<string, Contact*> addressBook;
};
//---------------------------------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL, "ru");

	MobilePhone mobilePhone;

	while (true) 
	{
		cout << "Введите команду (add, call, sms, exit): ";
		string command;
		cin >> command;

		if (command == "add") 
		{
			string name, number;
			cout << "Введите имя контакта: ";
			cin >> name;
			cout << "Введите номер телефона: ";
			cin >> number;
			mobilePhone.addContact(name, number);
		}
		else if (command == "call") 
		{
			string contactOrNumber;
			cout << "Введите имя контакта или номер телефона: ";
			cin >> contactOrNumber;
			mobilePhone.call(contactOrNumber);
		}
		else if (command == "sms") 
		{
			string contactOrNumber, message;
			cout << "Введите имя контакта или номер телефона: ";
			cin >> contactOrNumber;
			cout << "Введите сообщение: ";
			cin.ignore();
			getline(cin, message);
			mobilePhone.sendSMS(contactOrNumber, message);
		}
		else if (command == "exit") 
		{
			cout << "Выход из программы." << endl;
			break;
		}
		else 
		{
			cout << "Недопустимая команда. Пожалуйста, попробуйте снова." << endl;
		}
	}

	return 0;
}
//---------------------------------------------------------------------------------------------