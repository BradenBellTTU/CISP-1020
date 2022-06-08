/* File: mainSearch.c
 * Author: Cindy Arnold
 * Description: main function to test different searches
 */
#include <stdio.h>
#include "binarySearch.h"
#define NUM_VALUES 25

int main() {
   double numbers[NUM_VALUES] = { 0.0, 1.1, 2.2, 3.3, 4.4, 5.5,
		6.6, 7.7, 8.8, 9.9, 10, 11.1, 12.2, 13.3, 14.4, 15.5, 16.6,
		17.7, 18.8, 19.9, 20.0, 21.1, 22.2, 23.3, 24.4 };
	double key;
   int i;
	int comparisons, iterations;
	int foundIndex;
   
   printf( "Enter a number to find: " );
   scanf( "%lf", &key );	
   comparisons = iterations = 0;
   foundIndex = linearSearch( numbers, NUM_VALUES, key, &iterations, &comparisons );
   printf( "Linear: %d iterations, %d comparisons\n", iterations, comparisons );
	if ( foundIndex == -1 ) 
	   printf( "\tKey %lf not found.\n", key );
	else 
      printf( "\tKey %5.2lf found %5.2lf at index %d.\n", key, numbers[foundIndex], foundIndex );
	comparisons = iterations = 0;
   foundIndex = iterativeBSearch( numbers, NUM_VALUES, key, &iterations, &comparisons );
	printf( "Iterative binary: %d iterations, %d comparisons\n", iterations, comparisons );
   if ( foundIndex == -1 ) 
      printf( "\tKey %lf not found.\n", key );
	else 
      printf( "\tKey %5.2lf found %5.2lf at index %d.\n", key, numbers[foundIndex], foundIndex );
   comparisons = iterations = 0;
   foundIndex = recursiveBSearch( numbers, 0, NUM_VALUES-1, key, &iterations, &comparisons );
   printf( "Recursive binary: %d recursive calls, %d comparisons\n", iterations, comparisons );
	if ( foundIndex == -1 )
      printf( "\tKey %lf not found.\n", key );
	else
      printf( "\tKey %5.2lf found %5.2lf at index %d.\n", key, numbers[foundIndex], foundIndex );
	return 0;
}
