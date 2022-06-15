/* File: binaryWrite.c
 * Author: Cindy
 * Description: example of writing binary data in a structure
 */
#include <stdio.h>

#define MAX_NAME_LENGTH 30

typedef struct employee {
   char firstName[MAX_NAME_LENGTH];
   char lastName[MAX_NAME_LENGTH];
   int age;
   double salary;
} Employee;

int main(int argc, char *argv[]) {
   Employee e[5] = { { "Jack", "Dorsey", 14, 0.0 }, 
                     { "Greta", "Thunberg", 17, 1234.56 },
                     { "Manjul", "Bhargava", 54, 13579.0 }, 
                     { "Ellen", "Ochoa", 72, 99999.99 },
                     { "Maya", "Angelou", 102, 1234567.89 } };

   FILE* out;
   int i;

   //out = fopen( "binary.out", "wb" );
   // To get output  file name from command line
   out = fopen( argv[1], "wb" );

   for( i = 0; i < 5; i++ ) {
      fwrite( &e[i], sizeof( Employee ), 1, out );
   } 

   // or, since we know already we want to write 5 emplyoees, don't
   // need a loop. Can just: 
   // fwrite( e, sizeof( Employee ), 5, out );

   fclose( out );

   return 0;
}
