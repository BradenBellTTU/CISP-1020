#ifndef MYALGORITHMS_H
#define MYALGORITHMS_H



template<class T>
void mySwap(T& item1, T& item2) {
	T temp;
	temp = item1;
	item1 = item2;
	item2 = temp;
}


template<class T>
T myMin(T& item1, T& item2) {
	if (item1 < item2)
		return item1;
	return item2;
}

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


template<class T>
int mySearch(T array[], int n, T key) {
	for (int i = 0; i < n; i++) {
		if (array[i] == key) {
			return 1;
		}
	}
	return -1;
}
































#endif