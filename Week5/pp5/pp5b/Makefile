all: fullprogram

fullprogram: mainDbLinkedList.o dbl_linked_list.o node.o
	gcc mainDbLinkedList.c dbl_linked_list.c node.c -o mainQueue.exe

main: mainDbLinkedList.c
	gcc -c mainDbLinkedList.c

dbl_linked_list: dbl_linked_list.c dbl_linked_list.h
	gcc -c dbl_linked_list.c 

node: node.c node.h
	gcc node.c

clean:
	rm -rf *.o *.gch
