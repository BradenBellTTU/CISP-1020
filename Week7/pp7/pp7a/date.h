#ifndef DATE_H
#define DATE_H
#include <iostream>

using namespace std;

enum month_t { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE,
JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };





class Date
{
public:
    static const int MIN_MONTH;
    static const int MAX_MONTH;
    static const int MIN_YEAR;
    static const int MIN_DAY;
    void setYear(int);
    int getYear() const;
private:
    int month; // 0 = January
    int day;
    int year;
};
#endif