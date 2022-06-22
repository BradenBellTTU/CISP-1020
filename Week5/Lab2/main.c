#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "node.h"
#include "stock.h"


int main() {
    int usrMenuSelect = 0;

    printf("\nWelcome to YourTrade.com\n");
    printf("Reporting, buying, or selling?\n");
    printf("(0 = quit, 1 = report, 2 = buy, 3 = sell): ");
    scanf("%d", &usrMenuSelect);

    switch(usrMenuSelect) {
        case 0:
            printf("Thank you for trading with YourTrade.com\n");
            break;

        case 1:
            printf("Report placeholder\n");
            break;

        case 2:
            printf("Buy placeholder\n");
            break;

        case 3:
            printf("Sell placeholder\n");
            break;
    }

    return 0;
}