all: myprogram

myprogram: mainStack.o stack.o
	gcc mainStack.c stack.c -o mainStack.exe

main: mainStack.c stackItem.h
	gcc -c mainStack.c

stack: stack.c stack.h
	gcc -c stack.c

clean:
	rm -rf *.o *.gch
