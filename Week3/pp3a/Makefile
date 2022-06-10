all: myprogram

myprogram: mainSearch.o binarySearch.o
	gcc mainSearch.c binarySearch.c -o mainSearch.exe

main: mainStack.c 
	gcc -c mainSearch.c

binary_search: binarySearch.c binarySearch.h
	gcc -c binarySearch.c

clean:
	rm -rf *.o *.gch