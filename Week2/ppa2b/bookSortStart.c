/* File: bookSort.c
 * Author: Cindy
 * Description: uses array of pointers to an 
 *    array of structures to sort
 */
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 81
#define MAX_BOOKS 10 

typedef struct  {
   char title[MAX_CHARS];
   char author[MAX_CHARS];
   char publisher[MAX_CHARS];
   int edition;
} book_t;

int readBooks( book_t* );
void initSortingArray( book_t*, book_t**, int );
void printBooks( book_t**, int );
void sortBooks( book_t**, int );
void swap( book_t**, book_t** );

int main() {
   book_t books[MAX_BOOKS];  
   book_t* titlePtrs[MAX_BOOKS];
   int numBooks;
   
   numBooks = readBooks( books ); 
   initSortingArray( books, titlePtrs, numBooks );
   sortBooks( titlePtrs, numBooks );
   printBooks( titlePtrs, numBooks );
   
   return 0;
}

/* readBooks: fills book_t array with at most MAX_BOOKS
 *    book info from file books.in
 * Parameters: a array of book structure
 * Returns: number of books
 */
int readBooks( book_t* a ) {
   FILE* in;
   int i = 0;
   char junk;
   in = fopen( "books.in", "r" );
   if ( in != NULL ) {
      while ( i < MAX_BOOKS &&
      fgets( a[i].title, MAX_CHARS, in ) != NULL ) {
         fgets( a[i].author, MAX_CHARS, in );
         fgets( a[i].publisher, MAX_CHARS, in );
         fscanf(in, "%d", &a[i].edition );
         fscanf(in, "%c", &junk );
         i++;
      }
   }
   return i;
}

/* initSortingArray: sets all pointers in array to point to 
 *    books array
 * Parameters: 
 *    a books array
 *    t pointers to elements in books array
 *    n number of books in array a
 * Postcondition: t contains n valid pointers to n elements in a
 * Returns: nothing
 */
// ADD CODE HERE for the initSortingArray that initializes the array of pointers









/* printBooks: prints book info to stdout
 * Parameters:
 *    aPtr: array of pointers to book_t structures
 *    n: number of valid element in n
 * Returns: nothing
 */
void printBooks( book_t** aPtr, int n ) {
   int i;
   for( i = 0; i < n; i++ ) {
      printf("%s %s %s %d\n", aPtr[i]->title, aPtr[i]->author,
         aPtr[i]->publisher, aPtr[i]->edition );
   } 
}

/* sortBooks: uses a selection sort to sort book info 
 * Parameters:
 *    aPtr: array of pointers to book_t structures
 *    n: number of valid elements in aPtr
 * Returns: nothing
 */
// ADD CODE HERE for the sort function that sorts/swaps the array of pointers
//  NOT the array of books by book title
// MAKE SURE TO CALL THE swap FUNCTION!



















/* swap: swaps pointers to book_t array elements
 * Parameters:
 *    b1, b2: references to pointers to book_t elements
 * Postcondition: actual parameter pointer values swapped
 * Returns: nothing
 */
// ADD CODE HERE TO swap the pointers to books in the array of pointers
