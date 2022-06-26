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
}

Date::Date (int yyyy) {
    setYear (yyyy);
}

Date::~Date() {
    //printDate();
   //cout << "destroyed\n";
}

Date operator+ (const Date& d1, const Date& d2) {
    int month = d1.month, day = d1.day, year = d1.year;
    day += d2.day;
    return Date(month, day, year);
}

bool operator== (const Date& d1, const Date& d2) {
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
        return true;
    else
        return false;
}

//This would not work. I kept getting the error 

Date Date::operator-( ) const {
    return Date(abs(this->month-6), this->day, this->year);
}

ostream& operator<< (ostream& outStream, const Date& d) {
    outStream << setfill('0') << setw(2) << (d.month+1) << '/' << d.day << '/' << setw(4) << d.year;
    return outStream;
}

istream& operator>> (istream& inStream, Date& d) {
    inStream >> d.month >> d.day >> d.year;
    d.setMonth (d.month-1);
    return inStream;
}

Date& Date::operator=(const Date& d1) {
    this->day = d1.day;
    this->month = d1.month;
    this->year = d1.year;
    return *this;
}