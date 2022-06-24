#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "node.h"
#include "stock.h"
#include "date.h"
#include <ctype.h>

const int MAX_STR_LEN = 256;

void report();
void buy();
int sell();
void readBin(FILE*, char[], int);
void toUpperCase(char[]);

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
                buy();
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
    char tempString[MAX_STR_LEN], stockChoice[5];
    int totalStock = 0;
    FILE* inFileStream;
    

    stock_t stockVar;
    
    printf("\tStocks Owned\n\t-----------\n");
    while( (dirEntry = readdir( dirPtr )) != NULL) {

        if ( strstr(dirEntry->d_name, ".bin") != NULL) { //Check for .bin files
            strncpy(tempString, dirEntry->d_name, strlen(dirEntry->d_name) - 4); //remove .bin and store it in tempString

           inFileStream = fopen(dirEntry -> d_name, "rb");
           if (inFileStream != NULL) {
            readBin(inFileStream, tempString, 1);
           }
        }
        totalStock = 0;
        strcpy(tempString, "");
    }
    fclose(inFileStream);

    //read what they pick and print the stocks from that file
    printf("Enter stock ticker symbol: ");            
    scanf("%s", stockChoice);
    strcpy(tempString, stockChoice);
    strcat(tempString, ".bin");
    inFileStream = fopen(tempString, "rb");
    if (inFileStream != NULL) {
        printf("\n\tTicker\tPurchase Date\tShares\tPrice Per Share\n");
        printf("\t---------------------------------------------------\n");
        readBin(inFileStream, stockChoice, 2);
        printf("\n");
    }
    totalStock = 0;
    strcpy(tempString, "");
}


void buy() {
    stock_t stockVar;
    FILE* outFileStream;
    char tempString[MAX_STR_LEN];

    printf("Enter stock ticker symbol: ");
    scanf("%s", stockVar.ticker);
    printf("Enter number of shares: ");
    scanf("%d", &stockVar.numShares);
    printf("Enter stock price: ");
    scanf("%lf", &stockVar.pricePerShare);
   // printf("%d", stockVar.date.year);
    stockVar.date = setToday(stockVar.date);
    //printf("%d", stockVar.date.year);

    strcpy(tempString, stockVar.ticker);
    strcat(tempString, ".bin");

    outFileStream = fopen(tempString, "a");
    
    
    //fwrite to write stockVar
    if (outFileStream != NULL) {
        fwrite(&stockVar, sizeof(stock_t), 1, outFileStream);
    }

    printf("%d shares of %s purchased at $%f per share.\n", stockVar.numShares, stockVar.ticker, stockVar.pricePerShare);
    fclose(outFileStream);
    
}

int sell() {
    dbl_linked_list_t list;
    char tickerSymbol[MAX_STR_LEN];
    FILE* inFileStream;
    int desiredStocks = 0, totalStocks = 0;


    scanf("%s", tickerSymbol);//get ticker symbol: eg APPL
    toUpperCase(tickerSymbol); //uppercase symbol and 
    strcat(tickerSymbol, ".bin"); //strcat ".bin" to the end of it
    
    
    inFileStream = fopen(tickerSymbol, "rb");//open that file
    if (inFileStream == NULL) {//if file open failed
        printf("Error: File for stock does not exist.\n");//error message
        return 0;
    }
    //total = read from file, count total, and fill up list l (FILE* in, &dbl_linked_list l)

    //HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    //print total and 
    printf("Enter number of shares: "); //get how many user wants
    scanf("%d", &desiredStocks);


    if (desiredStocks > totalStocks) {//if they want too many then return an error message and return to main menu
        printf("Error: not enough stocks to sell\n");
        return 0;
    }

    //desiredStocks < #in node
        //decriment # in the node
        //done

    //if desiredStocks == #in the node
        //pop node
        //deallocate the node
        //done

    //if desiredStocks > #in the node
        //decriment and pop if needed

    //if the list isn't empty
        //write list back to file - put that function in list files
        //deleteList(&l);
    //else
        //remove(filename);

    return 1;
}



void readBin(FILE* inFileStream, char* fileNameIn, int Case) {
    stock_t stockVar;
    int totalStock = 0;
    if (inFileStream != NULL) {
        fread(&stockVar, sizeof(stock_t), 1, inFileStream);
        while(!feof(inFileStream)) {
            if(Case == 2) {
                printStock(stockVar);
            }
            totalStock += stockVar.numShares;
            fread(&stockVar, sizeof(stock_t), 1, inFileStream);

            
        }
        if (Case == 1) {
            printf("\t%s\t%3d\n", fileNameIn, totalStock);
        }
    }

}



void toUpperCase(char s[]) {
	for (int i = 0; s[i] != '\0'; i++ ) {
		s[i] = toupper(s[i]);
	}
}