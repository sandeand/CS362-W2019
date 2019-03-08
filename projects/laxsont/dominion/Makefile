CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randomtestadventurer: dominion.o rngs.o randomtestadventurer.o
	gcc -o randomtestadventurer randomtestadventurer.c -g  dominion.o rngs.o $(CFLAGS) -w
	./randomtestadventurer > randomtestadventurer.out
	gcov -b -f dominion.c >> randomtestadventurer.out

randomtestcard1: dominion.o rngs.o randomtestcard1.o
	gcc -o randomtestcard1 randomtestcard1.c -g  dominion.o rngs.o $(CFLAGS) -w
	./randomtestcard1 > randomtestcard1.out
	gcov -b -f dominion.c >> randomtestcard1.out

randomtestcard2: dominion.o rngs.o randomtestcard2.o
	gcc -o randomtestcard2 randomtestcard2.c -g  dominion.o rngs.o $(CFLAGS) -w
	./randomtestcard2 > randomtestcard2.out
	gcov -b -f dominion.c >> randomtestcard2.out

unittestresults: dominion.o rngs.o unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c
	gcc -o unittest1 unittest1.c -g  dominion.o rngs.o $(CFLAGS) -w
	gcc -o unittest2 unittest2.c -g  dominion.o rngs.o $(CFLAGS) -w
	gcc -o unittest3 unittest3.c -g  dominion.o rngs.o $(CFLAGS) -w
	gcc -o unittest4 unittest4.c -g  dominion.o rngs.o $(CFLAGS) -w
	gcc -o cardtest1 cardtest1.c -g  dominion.o rngs.o $(CFLAGS) -w
	gcc -o cardtest2 cardtest2.c -g  dominion.o rngs.o $(CFLAGS) -w
	gcc -o cardtest3 cardtest3.c -g  dominion.o rngs.o $(CFLAGS) -w
	gcc -o cardtest4 cardtest4.c -g  dominion.o rngs.o $(CFLAGS) -w
	./unittest1 > unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

testall: randomtestadventurer randomtestcard1 randomtestcard2 unittestresults

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
