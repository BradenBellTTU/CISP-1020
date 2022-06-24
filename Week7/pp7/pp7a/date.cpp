#include <iostream>
#include <iomanip>
#include "date.h"
using namespace std;

const int Date::MIN_MONTH = JANUARY;
const int Date::MAX_MONTH = DECEMBER;
const int Date::MIN_YEAR = 1;
const int Date::MIN_DAY = 1;



void Date::setYear (int y) {
    if (y < MIN_YEAR) year = MIN_YEAR;
    else year = y;
}

void Date::setMonth (int m) {
    if (m < MIN_MONTH) month = MIN_MONTH;
    else month = m;
}

void Date::setDay (int d) {
    if (d < MIN_DAY) d = MIN_DAY;
    else day = d;
}

void Date::setDate(int m, int d, int y) {
    setMonth(m);
    setDay(d);
    setYear(y);
}

void Date::printDate() const {
    cout << setfill('0') << setw(2) << (month+1) << '/' << day << '/' << setw(4) << year;
}


