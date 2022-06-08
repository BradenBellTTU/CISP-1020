/* File: binarySearch.h
 * Author: Cindy Arnold
 * Description: function declarations for search functions
 */
#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#define NOT_FOUND -1

int linearSearch( double a[], int n, double k, int *iPtr, int *cPtr );
int iterativeBSearch( double a[], int n, double k, int *iPtr, int *cPtr );
int recursiveBSearch( double a[], int b, int t,  double k, int *iPtr, int *cPtr );

#endif
