#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "date.h"
#include "stock.h"



date_t setToday(date_t dateStruct) {
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    //printf("\nDate: %2d/%2d/%4d\n", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900);
    dateStruct.day = tm.tm_mday;
    dateStruct.month = tm.tm_mon + 1;
    dateStruct.year = tm.tm_year + 1900;
    
    return dateStruct;
    /*time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    dateStruct.day = tm -> tm_mday;
    dateStruct.month = tm -> tm_mon + 1;
    dateStruct.year = tm -> tm_mon + 1900;
    */
}
