#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "date.h"
#include "stock.h"


void setToday(date_t dateStruct) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    dateStruct.day = tm -> tm_mday;
    dateStruct.month = tm -> tm_mon + 1;
    dateStruct.year = tm -> tm_mon + 1900;
}