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

Date::Date() {
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    month = tPtr->tm_mon;
    day = tPtr->tm_mday;
    year = tPtr->tm_year + 1900;
}

Date::Date(int mm, int dd, int yyyy) {
    setMonth(mm);
    setYear(yyyy);
    setDay(dd);
}

Date::Date(int mm, int yyyy) {
    setMonth(mm);
    setYear(yyyy);
    setDay(1);
}

Date::Date (int yyyy) {
    setMonth(JANUARY);
    setYear (yyyy);
    setDay(1);
}


