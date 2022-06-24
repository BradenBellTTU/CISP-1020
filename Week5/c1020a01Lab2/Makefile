all: fullprogram

fullprogram: main.o stock.o list.o node.o date.o
	gcc main.c stock.c list.c node.c date.o -o main.exe

main: main.c
	gcc -c main.c

stock: stock.c stock.h
	gcc -c stock.c

list: list.c list.h
	gcc -c list.c

node: node.c node.h
	gcc -c node.c

date: date.c date.h
	gcc -c date.c

clean:
	rm -rf *.o *.gch