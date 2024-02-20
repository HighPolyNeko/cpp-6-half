#pragma once

class Time {
    int hours;
    int minutes;
    int seconds;
public:
    Time(int hours, int minutes, int seconds);
    int* getTime() const;
    int getTimeBySeconds() const;
    void setTime(int hours, int minutes, int seconds);
    int compare(const Time &other) const;
};
