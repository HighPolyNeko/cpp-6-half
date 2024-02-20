#include <iostream>

#include "Date.h"
#include "Funcs.h"
#include "Rectangle.h"
#include "Time.h"

using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "RU-UA.UTF-8");

    int n;
    do {
        cout << "Введите номер задания от 1 до 10: ";
        cin >> n;
    }
    while (n > 10 || n < 1);

    if (n == 1) funcs::N1();
    if (n == 2) funcs::N2();
    if (n == 3) funcs::N3();
    if (n == 4) funcs::N4();
    if (n == 5) funcs::N5();
    if (n == 6) funcs::N6();
    if (n == 7) funcs::N7();
    if (n == 8) {
        Date date(01, 03, 2003);
        date.getDate();
        Date date2(21, 02, 2024);
        cout << "Разници дней: " << Date::dayCounter(date, date2) << '\n';
    }
    if (n == 9) {
        Rectangle rectangle(new int[]{1, 3}, new int[]{5, 9});

        cout << "Площадь: " << rectangle.area() << '\n';
        cout << "Периметр: " << rectangle.perimeter() << '\n';

        cout << "Левый верхний угол: x = " << rectangle.getCorner(LeftUp)[0] << ", y = " << rectangle.getCorner(LeftUp)[
            1] << '\n';
    }
    if (n == 10) {
        Time clock(5, 61, 7);
        clock.getTime();
    }

    return 0;
}
