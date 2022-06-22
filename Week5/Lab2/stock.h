#ifndef STOCK_H
#define STOCK_H

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




#endif