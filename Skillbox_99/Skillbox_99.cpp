#include <iostream>
#include <vector>

using namespace std;

/*2. Модель данных для посёлка
Что нужно сделать
Используя структуры данных, создайте подробную модель посёлка.
Что известно
• Посёлок состоит из участков, и у каждого участка есть свой номер.
• На любом участке может стоять жилой дом, а также могут быть и другие сооружения:
— гараж,
— сарай (бытовка),
— баня.
• У каждого здания есть информация о площади, которую оно занимает на участке.
• В доме может быть 1–3 этажа, на этаже — 2–4 комнаты:
— спальня,
— кухня,
— ванная,
— детская,
— гостиная.
• У каждого этажа есть информация о количестве комнат и высоте потолка на этаже.
• У каждой комнаты есть информация о занимаемой площади.
• В доме и бане может быть печь с трубой.
Для всех упомянутых сущностей нужно объявить структуры данных.

Обязательно для выполнения задания
Опишите структуры данных для создания модели посёлка. Структуры должны быть:
• связными и легко расширяемыми,
• без дублирующих конструкций.*/

//-----------------------------------------------------------------------------------
enum BuildingType // Перечисление для типов построек
{
	ResidentialHouse,
	Garage,
	Shed,
	Bathhouse
};
//-----------------------------------------------------------------------------------
struct Building // Структура для информации о площади и этажности постройки
{
	BuildingType type;
	double area;
	int floors;
};
//-----------------------------------------------------------------------------------
enum RoomType // Перечисление для типов комнат
{
	Bedroom,
	Kitchen,
	Bathroom,
	ChildrenRoom,
	LivingRoom
};
//-----------------------------------------------------------------------------------
struct Room // Структура для информации о комнате
{
	RoomType type;
	double area;
};
//-----------------------------------------------------------------------------------
struct House // Структура для информации о доме
{
	vector<vector<Room>> floors; // Каждый этаж содержит список комнат
	double landArea; // Площадь участка
};
//-----------------------------------------------------------------------------------
struct Village // Структура для информации о поселке
{
	vector<Building> buildings; // Список построек
	vector<House> houses; // Список домов
	double totalLandArea; // Общая площадь поселка
};
//-----------------------------------------------------------------------------------
int main() 
{
	setlocale(LC_ALL, "RU");

	Village village;

	// Заполнение данных о поселке (демонстрационный пример)
	Building house1 = { ResidentialHouse, 150, 2 };
	Building garage1 = { Garage, 30, 1 };
	Building shed1 = { Shed, 20, 1 };
	Building bathhouse1 = { Bathhouse, 50, 1 };

	village.buildings.push_back(house1);
	village.buildings.push_back(garage1);
	village.buildings.push_back(shed1);
	village.buildings.push_back(bathhouse1);

	House houseData1;
	vector<Room> floor1 = { {Bedroom, 20}, {Bedroom, 18}, {Bathroom, 10} };
	vector<Room> floor2 = { {LivingRoom, 30}, {Kitchen, 15} };
	houseData1.floors.push_back(floor1);
	houseData1.floors.push_back(floor2);
	houseData1.landArea = 500;

	village.houses.push_back(houseData1);

	// Вычисление общей площади поселка
	village.totalLandArea = 0;
	for (const Building& building : village.buildings) 
	{
		village.totalLandArea += building.area;
	}
	for (const House& house : village.houses) 
	{
		village.totalLandArea += house.landArea;
	}

	cout << "Общая площадь поселка: " << village.totalLandArea << " кв. м." << endl;

	return 0;
}
//-----------------------------------------------------------------------------------