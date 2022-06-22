all: fullprogram

fullprogram: main.o stock.o list.o node.o
	gcc main.c stock.c list.c node.c -o main.exe

main: main.c
	gcc -c main.c

stock: stock.c stock.h
	gcc -c stock.c

list: list.c list.h
	gcc -c list.c

node: node.c node.h
	gcc -c node.c

clean:
	rm -rf *.o *.gch