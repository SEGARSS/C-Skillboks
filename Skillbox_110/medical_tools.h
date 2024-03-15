#ifndef MEDICAL_TOOLS_H
#define MEDICAL_TOOLS_H

#include <iostream>

// Структура для двумерной точки
//-----------------------------------------------------------------------------------
struct Point 
{
    double x;
    double y;
};
//-----------------------------------------------------------------------------------

Point inputPoint();// Функция для ввода точки из консоли

bool pointsEqual(const Point& p1, const Point& p2);// Функция для сравнения двух точек на предмет равенства

void printPoint(const Point& point);// Функция для вывода точки в консоль
void scalpel(const Point& startPoint, const Point& endPoint);// Функция для выполнения разреза между двумя точками
void hemostat(const Point& point);// Функция для применения зажима к точке
void tweezers(const Point& point);// Функция для применения пинцета к точке
void suture(const Point& startPoint, const Point& endPoint);// Функция для выполнения шва между двумя точками

#endif // MEDICAL_TOOLS_H
//-----------------------------------------------------------------------------------