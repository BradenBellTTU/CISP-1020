/* File: writeBinaryStockFile.c
 * Author: Cindy
 * Prompts uers for stock info then writes it to a binary file
 */ 
#include <stdio.h>
#include "stock.h"

int main() {
   FILE* output;
   stock_t s;
   int userResponse; // 0 if user is done

   // open binary file
   output = fopen( "stocks.bin", "a" );

   do {
      getStock( &s );
      fwrite( (char*)(&s), sizeof(stock_t), 1, output );
      printf( "Continue? (0 = no): " );
      scanf( "%d", &userResponse );
   } while( userResponse != 0 );
   fclose( output );

   return 0;
}
