/*
    * File: main.cpp
    * Author: Braden Bell
    * Date: 6/24/2022
    * This program is for Graded Lab 2, and it simulates a website called YouTrade.com where the user
    * can report, buy, and sell their stocks.
    * 
    * 
    * 
    * Relavance Questions:
    * 1. The first thing that comes to mind for a first-in first-out scenario is maybe there is a website 
    *    that has a queue to buy tickets and you have to store the user data in a first-in first-out database
    *    (ie, the first person in line gets their ticket first.) 
    *    It wouldn't make any sense to have last-in first-out like a stack because the tickets are first come
    *    first serve.
    * 
    * 2. A doubly linked list isn't useful for data that needs to be access randomly becasue you would end up
    *    traversing the entire queue/stack every time something random needed to be accessed. It's not very
    *    efficient.
*/


//Includes:
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "node.h"
#include "stock.h"
#include "date.h"
#include <ctype.h>

//Global const vars:
const int MAX_STR_LEN = 256;

//Prototype functions:
void report();
void buy();
int sell();
void readBin(FILE*, char[], int);
void toUpperCase(char[]);

int main() {
    //Vars:
    int usrMenuSelect = 0;
    int menuLoop = 1;

    printf("\nWelcome to YourTrade.com\n"); //Welcome message

    do { //Main menu
        printf("Reporting, buying, or selling?\n");
        printf("(0 = quit, 1 = report, 2 = buy, 3 = sell): ");
        scanf("%d", &usrMenuSelect); //get menu selection from user

        switch(usrMenuSelect) {//Depending on what the user selected, call the correct function
            case 0:
                printf("Thank you for trading with YourTrade.com\n");//Goodbye message
                menuLoop = 0;//Break do-while
                break;

            case 1:
                report();
                break;

            case 2:
                buy();
                break;

            case 3:
                sell();
                break;

            default:
                printf("Error. Closing program.\n");
                menuLoop = 0;//Break do-while
        }
    } while(menuLoop);
    return 0;
}

/* report: shows user the stocks they have and how many and gives detailed info on a specific stock
 * Parameters:
 *    None
 * Returns: nothing 
 */
void report() {
    //Vars
    DIR* dirPtr;
    struct dirent* dirEntry;
    dirPtr = opendir(".");
    char tempString[MAX_STR_LEN], stockChoice[5];
    int totalStock = 0;
    FILE* inFileStream;
    stock_t stockVar;

    
    printf("\tStocks Owned\n\t-----------\n"); //menu stuff

    while( (dirEntry = readdir( dirPtr )) != NULL) {//While there is still content in the directory

        if ( strstr(dirEntry->d_name, ".bin") != NULL) { //Check for .bin files
            strncpy(tempString, dirEntry->d_name, strlen(dirEntry->d_name) - 4); //remove .bin and store it in tempString

           inFileStream = fopen(dirEntry -> d_name, "rb");//Open filestream in read-only mode
           if (inFileStream != NULL) {//Make sure file stream is valid
            readBin(inFileStream, tempString, 1);//Read the bin file
           }
        }
        //Reinitalize variables to be empty
        totalStock = 0;
        strcpy(tempString, "");
    }
    fclose(inFileStream);//Close filestream

    //read what they pick and print the stocks from that file
    printf("\tEnter stock ticker symbol: ");            
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

    else {
        printf("You do not own any '%s' stock\n", stockChoice);
    }
    totalStock = 0;
    strcpy(tempString, "");
}


/* buy: allows the user to buy a stock and saves it to a file
 * Parameters:
 *     None
 * Returns: nothing 
 */
void buy() {
    //Vars
    stock_t stockVar;
    FILE* outFileStream;
    char tempString[MAX_STR_LEN];

    //Get info from user
    printf("Enter stock ticker symbol: ");
    scanf("%s", stockVar.ticker);
    toUpperCase(stockVar.ticker);
    printf("Enter number of shares: ");
    scanf("%d", &stockVar.numShares);
    printf("Enter stock price: ");
    scanf("%lf", &stockVar.pricePerShare);
    stockVar.date = setToday(stockVar.date);


    strcpy(tempString, stockVar.ticker); //Copy the tickername into a temporary string
    strcat(tempString, ".bin");//Add .bin to the temporary string for file work

    outFileStream = fopen(tempString, "a"); //Open file in append mode
    
    
    if (outFileStream != NULL) {//Makes sure the filestream is valid
        fwrite(&stockVar, sizeof(stock_t), 1, outFileStream); //write to filestream
    }

    //Confirm to user their purchase was successful
    printf("%d shares of %s purchased at $%3.2f per share.\n", stockVar.numShares, stockVar.ticker, stockVar.pricePerShare);
    fclose(outFileStream); //Close file stream
    
}

/* sell: allows a user to sell their stocks
 * Parameters:
 *     None
 * Returns: true or false depending on if it was successful
 */
int sell() {
    //Vars
    dbl_linked_list_t list;
    char tickerSymbol[MAX_STR_LEN], tempString[MAX_STR_LEN];
    FILE* inFileStream, outFileStream;
    stock_t stockVar;
    int desiredStocks = 0, totalStock = 0, soldStock = 0, costToSell = 0, totalBuying = 0;
    node_t* nodePtr;

    createList(&list);
    //printf("\nList made\n");
    printf("\tEnter stock ticker symbol: ");
    scanf("%s", tickerSymbol);//get ticker symbol: eg APPL
    toUpperCase(tickerSymbol); //uppercase symbol and 
    strcpy(tempString, tickerSymbol);
    strcat(tickerSymbol, ".bin"); //strcat ".bin" to the end of it
    
 
    inFileStream = fopen(tickerSymbol, "rb");//open that file
    //printf("\nFile opened\n");
    if (inFileStream == NULL) {//if file open failed
        printf("Error: File for stock does not exist.\n");//error message
        return 0; //return to main menu
    }
    //total = read from file, count total, and fill up list l (FILE* in, &dbl_linked_list list)
    fread(&stockVar, sizeof(stock_t), 1, inFileStream);
    //printf("\nFile read\n");
    while(!feof(inFileStream)) {
        totalStock += stockVar.numShares;
       //printf("\nTotal stock incrimented\n");
        nodePtr = initNode(stockVar);
        //printf("\nNode initlaized\n");
        insertNode(&list, nodePtr);
        //printf("\nNode inserted\n");
        fread(&stockVar, sizeof(stock_t), 1, inFileStream);
        //printf("\nFile read\n");
    }

    //traverseQueue(&list);
    //printf("\nQueue traversed\n");
    printf("You own %d %s shares.\n", totalStock, tempString);//print total and 
    printf("Enter number of shares: "); //get how many user wants
    scanf("%d", &desiredStocks);


    if (desiredStocks > totalStock) {//if they want too many then return an error message and return to main menu
        printf("Error: not enough stocks to sell\n");
        return 0;
    }

    traverseQueueAndSell(&list, nodePtr, desiredStocks, tickerSymbol);
   
    deleteList(&list);
    return 1;
}


/* readBin: Reads and prints the date in a stock.bin file
 * Parameters:
 *     inFileStream - a file stream to the .bin file
 *     fileNameIn - the name of the .bin file
 *     Case - whether or not to print just the number of shares or a more detailed look
 * Returns: nothing 
 */
void readBin(FILE* inFileStream, char* fileNameIn, int Case) {
    //Vars
    stock_t stockVar;
    int totalStock = 0;

    if (inFileStream != NULL) { //Make sure the file stream is valid
        fread(&stockVar, sizeof(stock_t), 1, inFileStream);//Read file
        while(!feof(inFileStream)) { //While we're not to the end of the file
            if(Case == 2) { //If case is 2, then print detailed information on the stock
                printStock(stockVar);
            }

            totalStock += stockVar.numShares; //Incriment totalStock
            fread(&stockVar, sizeof(stock_t), 1, inFileStream);//Read from the file again
        }
        if (Case == 1) { //If case is 1, then only print the amount of stock owned
            printf("\t%s\t%3d\n", fileNameIn, totalStock);
        }
    }

}


/* toUpperCase: Makes a string all uppercase
 * Parameters:
 *     s - the string to be converted to uppercase
 * Returns: nothing 
 */
void toUpperCase(char s[]) {
    int i = 0;	
    for (i = 0; s[i] != '\0'; i++ ) {
		s[i] = toupper(s[i]);
	}
}
