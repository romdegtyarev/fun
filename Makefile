default : fun.o
	gcc -std=c99 -o fun fun.o

fun.o : fun.c
	gcc -std=c99 -c fun.c

clean :
	rm -f fun fun.o
