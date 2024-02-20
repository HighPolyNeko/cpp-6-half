#include "Date.h"

#include <iomanip>
#include <iostream>
#include <queue>

long long Date::dayCounter1(int ad, int bd, int am, int bm, int ay, int by) {
    int startYear = ay;
    int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long long int count = 0;
    count -= (am == 2 && ay % 4 == 0 && ay % 100 != 0 ? daysInMonths[am - 1] + 1 : daysInMonths[am - 1]) - ad;
    //считаем года
    for (; ay > by; --ay) {
        //месяцы
        for (am = ay == startYear ? am : 12; am > 0; --am) {
            //дни
            count += am == 2 && ay % 4 == 0 && ay % 100 != 0 ? daysInMonths[am - 1] + 1 : daysInMonths[am - 1];
        }
    }
    //год совпал считаем месяцы
    for (am = 12; am > bm - 1; --am) {
        if (am == bm) {
            count += am == 2 && ay % 4 == 0 && ay % 100 != 0 ? daysInMonths[am - 1] + 1 : daysInMonths[am - 1];
            count -= bd;
        }
        else {
            count += am == 2 && ay % 4 == 0 && ay % 100 != 0 ? daysInMonths[am - 1] + 1 : daysInMonths[am - 1];
        }
    }
    return count;
}

Date::Date(int day, int month, int year) {
    this->year = year;
    if (year == 0) this->year = 1;

    this->month = month;
    if (month < 1) this->month = 1;
    if (month > 12) this->month = 12;


    int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > daysInMonths[month]) {
        if (month != 2) this->day = daysInMonths[month];
        else if (year % 4 == 0 && year % 100 != 0) this->day = daysInMonths[month] + 1;
        else this->day = daysInMonths[month];
    }
    else this->day = day;
    if (day < 1) this->day = 1;
}

int* Date::getDate() {
    std::cout << '[' << std::setfill('0') << std::setw(2) << day << ',' << std::setfill('0') << std::setw(2) << month <<
        ',' << year << "]\n";
    return new int[3]{day, month, year};
}

void Date::setDate(int day, int month, int year) {
    this->year = year;
    if (year == 0) this->year = 1;

    this->month = month;
    if (month < 1) this->month = 1;
    if (month > 12) this->month = 12;


    if ((month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) && day > 31)
        this->day = 31;
    else if (month == 2 && year % 4 == 0 && year % 100 != 0 && day > 29) this->day = 29;
    else if (month == 2 && day > 28) this->day = 28;
    else if (day > 30) this->day = 30;
    else this->day = day;
    if (day < 1) this->day = 1;
}

long long int Date::dayCounter(const Date& a, const Date& b) {
    if (a.day == b.day && a.month == b.month && a.year == b.year) return 0;
    int ad = a.day, bd = b.day, am = a.month, bm = b.month, ay = a.year, by = b.year;

    if (compare(a, b) == 0) return 0;
    if (compare(a, b) > 0) {
        return dayCounter1(ad, bd, am, bm, ay, by);
    }
    return dayCounter1(bd, ad, bm, am, by, ay);
}

int Date::compare(const Date& other) {
    return compare(*this, other);
}

int Date::compare(const Date& a, const Date& b) {
    if (a.year > b.year) return 1;
    if (a.year < b.year) return -1;

    if (a.month > b.month) return 1;
    if (a.month < b.month) return -1;

    if (a.day > b.day) return 1;
    if (a.day < b.day) return -1;
    return 0;
}
