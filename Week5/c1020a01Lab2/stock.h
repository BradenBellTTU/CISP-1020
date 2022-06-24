#ifndef STOCK_H
#define STOCK_H

#include <dirent.h>
#include <string.h>

typedef struct date_t {
   int month, day, year;
} date_t;


#define MAX_TICKER_LENGTH 6

typedef struct stock_t {
   char ticker[MAX_TICKER_LENGTH];
   date_t date; // date bought
   int numShares;
   double pricePerShare;
} stock_t;

void printStock(stock_t);


#endif