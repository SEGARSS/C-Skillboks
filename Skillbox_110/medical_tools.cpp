#include "medical_tools.h"

using namespace std;

//-----------------------------------------------------------------------------------
Point inputPoint() 
{
    Point p;
    cout << "Введите координаты (X Y): ";
    cin >> p.x >> p.y;
    return p;
}
//-----------------------------------------------------------------------------------
bool pointsEqual(const Point& p1, const Point& p2) 
{
    return p1.x == p2.x && p1.y == p2.y;
}
//-----------------------------------------------------------------------------------
void printPoint(const Point& point) 
{
    cout << "(" << point.x << ", " << point.y << ")";
}
//-----------------------------------------------------------------------------------
void scalpel(const Point& startPoint, const Point& endPoint) 
{
    cout << "Сделан разрез между точками ";
    printPoint(startPoint);
    cout << " и ";
    printPoint(endPoint);
    cout << endl;
}
//-----------------------------------------------------------------------------------
void hemostat(const Point& point) 
{
    cout << "Применен зажим в точке ";
    printPoint(point);
    cout << endl;
}
//-----------------------------------------------------------------------------------
void tweezers(const Point& point) 
{
    cout << "Применен пинцет к точке ";
    printPoint(point);
    cout << endl;
}
//-----------------------------------------------------------------------------------
void suture(const Point& startPoint, const Point& endPoint) 
{
    cout << "Выполнен шов между точками ";
    printPoint(startPoint);
    cout << " и ";
    printPoint(endPoint);
    cout << endl;
}
//-----------------------------------------------------------------------------------