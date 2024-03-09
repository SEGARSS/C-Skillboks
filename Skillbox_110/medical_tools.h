#ifndef MEDICAL_TOOLS_H
#define MEDICAL_TOOLS_H

#include <iostream>

// ��������� ��� ��������� �����
//-----------------------------------------------------------------------------------
struct Point 
{
    double x;
    double y;
};
//-----------------------------------------------------------------------------------

Point inputPoint();// ������� ��� ����� ����� �� �������

bool pointsEqual(const Point& p1, const Point& p2);// ������� ��� ��������� ���� ����� �� ������� ���������

void printPoint(const Point& point);// ������� ��� ������ ����� � �������
void scalpel(const Point& startPoint, const Point& endPoint);// ������� ��� ���������� ������� ����� ����� �������
void hemostat(const Point& point);// ������� ��� ���������� ������ � �����
void tweezers(const Point& point);// ������� ��� ���������� ������� � �����
void suture(const Point& startPoint, const Point& endPoint);// ������� ��� ���������� ��� ����� ����� �������

#endif // MEDICAL_TOOLS_H
//-----------------------------------------------------------------------------------