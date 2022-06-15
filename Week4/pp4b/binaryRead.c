/* File: binaryRead.c
 * Author: Cindy
 * Description: example of reading binary data in a structure
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
   Employee e[5]; 

   // ADD CODE HERE TO declare file pointer
   FILE* inFileStream;
   int i = 0;


   // ADD CODE HERE TO 
   if(argc == 2) {// if there is a filename argument
      inFileStream = fopen(argv[1], "rb");
      if (inFileStream != NULL) {//if file  open is successful, open binary file whose name retreived from command line for reading
         //       ADD CODE HERE TO read 5 employees from the binary file
         fread( &e[i], sizeof(Employee), 1, inFileStream);
         while(!feof(inFileStream)) {
            i++;
            fread(&e[i], sizeof(Employee), 1, inFileStream);
         }
      }
   
   
      //      ADD CODE HERE TO close the input file
      fclose(inFileStream);

      // print employees read
      for( i= 0; i  < 5; i++ ) {
         printf("%s %s %d %lf\n", e[i].firstName, e[i].lastName, e[i].age, e[i].salary );
      }
   }
   return 0;
}
