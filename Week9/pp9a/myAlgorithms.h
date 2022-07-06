#ifndef MYALGORITHMS_H
#define MYALGORITHMS_H


/* mySwap: swaps the first item with the second item
Parameters:
	item1 - the first item
	item2 - the second item
Pre-condition(s):
	type T has defined operator=
Returns: void
*/
template<class T>
void mySwap(T& item1, T& item2) {
	T temp;
	temp = item1;
	item1 = item2;
	item2 = temp;
}

/* myMin: Compares 2 values and returns the minimum
Parameters:
	item1 - the first item to be compared
	item2 - the second item to be compared
Pre-condition(s):
	type T has defined operator<
Returns: T The item that is the least of the two
*/
template<class T>
T myMin(T& item1, T& item2) {
	if (item1 < item2)
		return item1;
	return item2;
}


/* mySort: Sorts an array from least to greatest
Parameters:
	array - the array
	n - the number of valid elements in the array
Pre-condition(s):
	type T has defined operator<
Returns: void
*/
template<class T>
void mySort(T array[], int n) {
	int min = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (array[j] < array[i]) {
				mySwap(array[j], array[i]);
			}
		}
	}
}

/* mySearch: searches for a key in an array
Parameters:
	array - the array
	n - the number of valid elements in the array
	key - the key to look for
Pre-condition(s):
	type T has defined operator==
Returns: int index where key is found or -1 if not found
*/
template<class T>
int mySearch(T array[], int n, T key) {
	for (int i = 0; i < n; i++) {
		if (array[i] == key) {
			return i;
		}
	}
	return -1;
}
































#endif