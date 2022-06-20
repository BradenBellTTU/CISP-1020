/* File: grades.c
 * Author: Cindy Arnold
 * Description: demonstrates dynamically allocates array
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
   int count, i;
   // ADD CODE HERE TO declare pointer to grades (doubles)
   double *grades;

   double sum = 0, average = 0;
   
   // as user how many grades
   printf( "How many grades?  " );
   scanf( "%d", &count );
   
   // ADD CODE HEE TO dynamically allocate count grades
   grades = (double*) malloc(sizeof(double)*count);
   
   // ADD CODE HERE TO get the grades
   i = 0;


   while (i < count) { //User populates grades array until it is full
      printf("Enter grade: ");
      scanf( "%lf", &grades[i]);
      i++;
   }


   // ADD CODE HERE TO compute and print the sum and average
  
   for (i = 0; i < count; i++) { //Calculate sum
      sum += grades[i];
   }

   average = (sum /(double)count); //Calculate average

   //printf("Sum of all grades: %0.2lf\n", sum);
   printf("Average of all grades: %0.2lf\n", average); //Print average


   free(grades); //Deallocate dynamic memory to prevent memory leaks
   return 0;
}
