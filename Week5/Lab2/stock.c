#include "stock.h"
#include <stdlib.h>
#include <stdio.h>

void printStock(stock_t stock) {
    printf("\t%s\t", stock.ticker);
    printf("%2d/%2d/%4d\t", stock.date.month, stock.date.day, stock.date.year);
    printf("%3d\t", stock.numShares);
    printf("$  %6.2lf\n", stock.pricePerShare);
}






