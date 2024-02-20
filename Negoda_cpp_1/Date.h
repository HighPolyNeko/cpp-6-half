#pragma once


class Date {
    int day;
    int month;
    int year;
    static long long int dayCounter1(int ad, int bd, int am, int bm, int ay, int by);

public:
    Date(int day, int month, int year);
    int* getDate();
    void setDate(int day, int month, int year);
    static long long int dayCounter(const Date& a, const Date& b);
    int compare(const Date& other);
    static int compare(const Date& a, const Date& b);
};
