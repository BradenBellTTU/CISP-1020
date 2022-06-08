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
    for (int i = 0; i < n; i++) {
        ++(*iPtr);
        if (++(*cPtr) && a[i] == k) {
            return i;
        }
    }
    return -1;
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
    int low = 0;
    int high = (n - 1);
    while(low <= high) {
        ++(*iPtr);
        int mid = (low + high) / 2;

        if (++(*cPtr) && k == a[mid]) {
            return mid;
        }

        else if (++(*cPtr) && k > a[mid]) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }
    return -1;
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
    int mid = (b + t) / 2;
    ++(*iPtr);
    if (++(*cPtr) && k == a[mid]) { //Found it
        return mid;
    }

    else if (++(*cPtr) && b > t) { //Never going to find it
        return -1;
    }

    else if (++(*cPtr) && k  < a[mid]) {
        t = mid - 1;
        return recursiveBSearch(a, b, t, k, iPtr, cPtr);
    }

    else {
        b = mid + 1;
        return recursiveBSearch(a, b, t, k, iPtr, cPtr);
    }
}

