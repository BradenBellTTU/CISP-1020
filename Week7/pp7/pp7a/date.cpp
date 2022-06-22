#include "date.h"

const int Date::MIN_MONTH = JANUARY;
const int Date::MAX_MONTH = DECEMBER;
const int Date::MIN_YEAR = 1;
const int Date::MIN_DAY = 1;



void Date::setYear (int y) {
    if (y < MIN_YEAR) year = MIN_YEAR;
    else year = y;
}
