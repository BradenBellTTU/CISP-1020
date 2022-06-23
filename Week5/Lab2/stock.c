#include "stock.h"
#include <stdlib.h>
#include <stdio.h>

void printStock(stock_t stock) {
    printf("%s", stock.ticker);
    printf("%d/%d/%d", stock.date.month, stock.date.day, stock.date.year);
    printf("%d", stock.numShares);
    printf("%f", stock.pricePerShare);
}






