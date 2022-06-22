#include "stock.h"
#include <stdlib.h>
#include <stdio.h>

const int MAX_STR_LEN = 256;

void report() {
    DIR* dirPtr;
    struct dirent* dirEntry;
    dirPtr = opendir(".");
    //struct dirent* readdir(dirPtr);

    char tempString[MAX_STR_LEN];

    while( (dirEntry = readdir( dirPtr )) != NULL) {
        if ( strstr(dirEntry->d_name, ".bin") != NULL) { //Check for .bin files
            strncpy(tempString, dirEntry->d_name, strlen(dirEntry->d_name) - 4); //remove .bin and store it in tempString
            printf("%s\n", tempString);
        }
    }

    cosedir(dirPtr);

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
    
    stock_t tempStock_t
}