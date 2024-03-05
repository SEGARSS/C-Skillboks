#include <iostream>
using namespace std;

/*Задание 2. Вывод времени года
Что нужно сделать
Используя макросы вместе с условными директивами прекомпиляции (#if / #endif), 
реализуйте простую программу по выводу названия времени года в консоль.
Пользователь программы, который будет иметь дело с вашим кодом, в этом случае тоже программист. 
С помощью определения одного из макросов (в самом коде): SPRING, SUMMER, AUTUMN или WINTER он задаёт сезон, название, 
которое хочет увидеть на экране. 
При компиляции и запуске программы на экране должно появиться название именно этого сезона и только его.*/

#define SPRING
#define SUMMER
#define AUTUMN
#define WINTER

int main() 
{
#if defined(SPRING)
    cout << "Spring" << endl;
#elif defined(SUMMER)
    cout << "Summer" << endl;
#elif defined(AUTUMN)
    cout << "Autumn" << endl;
#elif defined(WINTER)
    cout << "Winter" << endl;
#else
    cout << "Invalid season" << endl;
#endif

    return 0;
}