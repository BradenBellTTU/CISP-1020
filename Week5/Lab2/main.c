#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "node.h"
#include "stock.h"

const int MAX_STR_LEN = 256;

int main() {
    int usrMenuSelect = 0;
    int menuLoop = 1;

    printf("\nWelcome to YourTrade.com\n");

    do {
        printf("Reporting, buying, or selling?\n");
        printf("(0 = quit, 1 = report, 2 = buy, 3 = sell): ");
        scanf("%d", &usrMenuSelect);

        switch(usrMenuSelect) {
            case 0:
                printf("Thank you for trading with YourTrade.com\n");
                menuLoop = 0;
                break;

            case 1:
                report();
                break;

            case 2:
                printf("Buy placeholder\n");
                break;

            case 3:
                printf("Sell placeholder\n");
                break;

            default:
                printf("Error. Closing program.\n");
                menuLoop = 0;
        }
    } while(menuLoop);
    return 0;
}




void report() {
    DIR* dirPtr;
    struct dirent* dirEntry;
    dirPtr = opendir(".");
    //struct dirent* readdir(dirPtr);

    char tempString[MAX_STR_LEN];

    while( (dirEntry = readdir( dirPtr )) != NULL) {
        if ( strstr(dirEntry->d_name, ".bin") != NULL) { //Check for .bin files
            strncpy(tempString, dirEntry->d_name, strlen(dirEntry->d_name) - 4); //remove .bin and store it in tempString
            printf("%s\n", tempString); //Print file names to console
        }
    }

    closedir(dirPtr);

}


void buy() {
    char tickerSymbol[MAX_STR_LEN];
    int numShares = 0;
    float stockPrice = 0;
    FILE* outFileStream;

    printf("Enter stock ticker symbol: ");
    scanf("%s", tickerSymbol);
    printf("Enter number of shares: ");
    scanf("%d", numShares);
    printf("%f", stockPrice);

    outFileStream = fopen(tickerSymbol, "a");
    
    //?????


    printf("%d shares of %s purchased at $%f per share.\n", numShares, tickerSymbol, stockPrice);
    fclose(outFileStream);
    
}