CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme.o: testme.c
	gcc testme.c -o test  $(CFLAGS)
	./test

all: testme.o

clean:
	rm -f *.o test *.gcno
