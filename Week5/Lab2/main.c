#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "node.h"
#include "stock.h"
#include "date.h"

const int MAX_STR_LEN = 256;

void report();
void buy();
int sell();
void printBin();

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
            //printf("Stocks Owned\n--------\n");
            printf("%s\n", tempString); //Print file names to console
            //read that bin and count total and print total
            printBin(tempString);


        }
    }

    closedir(dirPtr);
    //read what they pick and print the stocks from that file
}


void buy() {
    stock_t s;
    FILE* outFileStream;

    printf("Enter stock ticker symbol: ");
    scanf("%s", s.ticker);
    printf("Enter number of shares: ");
    scanf("%d", &s.numShares);
    printf("%f", s.pricePerShare);
    setToday(s.date);


    outFileStream = fopen(s.ticker, "a");
    
    
    //fwrite to write s
    

    printf("%d shares of %s purchased at $%f per share.\n", s.numShares, s.ticker, s.pricePerShare);
    fclose(outFileStream);
    
}

int sell() {
    dbl_linked_list_t l;
    char tickerSymbol[256];
    FILE* inFileStream;
    int desiredStocks = 0, total = 0;


    scanf("%s", tickerSymbol);//get ticker symbol: eg APPL
    toUpperCase(tickerSymbol); //uppercase symbol and 
    strcat(tickerSymbol, ".bin"); //strcat ".bin" to the end of it
    
    
    inFileStream = fopen(tickerSymbol, "rb");//open that file
    if (inFileStream == NULL) {//if file open failed
        printf("Error: File does not exist.\n");//error message
        return 0;
    }
    //total = read from file, count total, and fill up list l (FILE* in, &dbl_linked_list l)
    //print total and 
    printf("Enter number of shares: "); //get how many user wants
    scanf("%d", desiredStocks);


    if (desiredStocks > total) {//if they want too many then return an error message and return to main menu
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
}


//Need help!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void printBin(char* fileNameIn) {
    char fileName[256];
    strcpy(fileName, fileNameIn);
    strcat(fileName, ".bin");
    FILE* inFileStream;

    stock_t testVar;
    inFileStream = fopen(fileName, "rb");
    if (inFileStream != NULL) {
        fread(&testVar, sizeof(stock_t), 1, inFileStream);
        fclose(inFileStream);
    }

    
    printf("\t%d\n", testVar.numShares);
    
    
    

}



void toUpperCase(char s[]) {
	for (int i = 0; s[i] != '\0'; i++ ) {
		s[i] = toupper(s[i]);
	}
}