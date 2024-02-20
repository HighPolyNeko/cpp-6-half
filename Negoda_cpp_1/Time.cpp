#include "Time.h"

#include <iomanip>
#include <iostream>

using namespace std;

Time::Time(int hours, int minutes, int seconds) {
    this->seconds = seconds%60;
    this->minutes = (minutes+seconds/60)%60;
    this->hours = hours+(minutes+seconds/60)%60;
}

int* Time::getTime() const {
    
    cout << "Время: " << hours << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds << '\n';
    return new int[3]{hours, minutes, seconds};
}

int Time::getTimeBySeconds() const {
    return seconds + minutes * 60 + hours * 60 * 60;
}

void Time::setTime(int hours, int minutes, int seconds) {
    this->seconds = seconds%60;
    this->minutes = (minutes+seconds/60)%60;
    this->hours = hours+(minutes+seconds/60)%60;
}

int Time::compare(const Time& other) const {
    if (this->getTimeBySeconds() > other.getTimeBySeconds()) return 1;
    if (this->getTimeBySeconds() < other.getTimeBySeconds()) return -1;
    return 0;
}
