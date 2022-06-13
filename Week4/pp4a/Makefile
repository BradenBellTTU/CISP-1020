all: myprogram

myprogram: mainQueue.o queue.o
	gcc mainQueue.c queue.c -o mainQueue.exe

main: mainQueue.c queueItem.h
	gcc -c mainQueue.c

stack: queue.c queue.h
	gcc -c queue.c

clean:
	rm -rf *.o *.gch
