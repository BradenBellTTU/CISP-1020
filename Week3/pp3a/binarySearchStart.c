/* File: binarySearch.c
 * Author: Cindy
 * Description: example of linear, binary search algorithm iterative and 
 *    recursive versions
 */
#include <stdio.h>
#include <math.h>
#include "binarySearch.h"

/* linearSearch linearly searches for key and returns index where found or -1
 * Parameters
 *    a array to search
 *    n number elements in array
 *    k key to find
 *    iPtr number of iterations made
 *    cPtr number of comparisons made
 * Precondition: *iPtr and cPtr have been initialized to 0
 * Postcondition: *iPtr contain number of iterations for the search
 *    and cPtr number of comparisons
 * Returns: index where key found or -1
 */
int linearSearch( double a[], int n, double k, int *iPtr, int *cPtr ) {
// ADD CODE HERE
}

/* iterativeBSearch uses an iterative binary search to find key and 
 *    returns index where found or -1
 * Parameters
 *    a array to search
 *    n number elements in array
 *    k key to find
 *    iPtr pointer to number of iterations made
 *    cPtr pointer to number of comparisons made
 * Precondition: * iPtr and *cPtr has been initialized to 0
 * Postcondition: *cPtr contain number of comparisons for the search
 *    and iPtr the number of iterations
 * Returns: index where key found or -1
 */
int iterativeBSearch( double a[], int n, double k, int *iPtr, int *cPtr ) {
// ADD CODE HERE

}

/* recursiveBSearch uses a recursive binary search to find key and 
 *    returns index where found or -1
 * Parameters
 *    a array to search
 *    b bottom index of subarray to search
 *    t top index of subarray 
 *    k key to find
 *    iPtr pointer to number of recursive calls made
 *    cPtr pointer to number of comparisons made
 * Precondition: * iPtr and *cPtr has been initialized to 0
 * Postcondition: *cPtr contain number of comparisons for the search
 *    and iPtr the number of recursive calls
 * Returns: index where key found or -1
 */
int recursiveBSearch( double a[], int b, int t,  double k, int *iPtr, int *cPtr )  {
// ADD CODE HERE

}

