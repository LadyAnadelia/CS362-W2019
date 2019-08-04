CFLAGS= -Wall -fpic -coverage -lm -std=c99

ZFLAGS= -fprofile-arcs -ftest-coverage

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

tUpdateCoins: testUpdateCoins.c dominion.o rngs.o
	gcc -o testUpdateCoins -g testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 cardtest1.c dominion.o rngs.o $(CFLAGS) $(ZFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 cardtest2.c dominion.o rngs.o $(CFLAGS) $(ZFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 cardtest3.c dominion.o rngs.o $(CFLAGS) $(ZFLAGS)
cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 cardtest4.c dominion.o rngs.o $(CFLAGS) $(ZFLAGS)

cardtest5: cardtest5.c dominion.o rngs.o
	gcc -o cardtest5 cardtest5.c dominion.o rngs.o $(CFLAGS) $(ZFLAGS)

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 unittest1.c dominion.o rngs.o $(CFLAGS) $(ZFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 unittest2.c dominion.o rngs.o $(CFLAGS) $(ZFLAGS)
unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 unittest3.c dominion.o rngs.o $(CFLAGS) $(ZFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 unittest4.c dominion.o rngs.o $(CFLAGS) $(ZFLAGS)

unittest5: unittest5.c dominion.o rngs.o
	gcc -o unittest5 unittest5.c dominion.o rngs.o $(CFLAGS) $(ZFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 randomtestcard1.c dominion.o rngs.o $(CFLAGS) $(ZFLAGS)
randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 randomtestcard2.c dominion.o rngs.o $(CFLAGS) $(ZFLAGS)
randomtestcard3: randomtestcard3.c dominion.o rngs.o
	gcc -o randomtestcard3 randomtestcard3.c dominion.o rngs.o $(CFLAGS) $(ZFLAGS)

testresults: cardtest1 cardtest2 cardtest3 cardtest4 cardtest5 unittest1 unittest2 unittest3 unittest4 unittest5 randomtestcard1 randomtestcard2 randomtestcard3
	cardtest1 &> cardtest1.out
	gcov -bc dominion.c >> cardtest1.out
	cat dominion.c.gcov >> cardtest1.out
	cardtest2 &> cardtest2.out
	gcov -bc dominion.c >> cardtest2.out
	cat dominion.c.gcov >> cardtest2.out

	cardtest3 &> cardtest3.out
	gcov -bc dominion.c >> cardtest3.out
	cat dominion.c.gcov >> cardtest3.out

	cardtest4 &> cardtest4.out
	gcov -bc dominion.c >> cardtest4.out
	cat dominion.c.gcov >> cardtest4.out
	cardtest5 &> cardtest5.out
	gcov -bc dominion.c >> cardtest5.out
	cat dominion.c.gcov >> cardtest5.out
	unittest1&> unittest1.out
	gcov -bc dominion.c >> unittest1.out
	cat dominion.c.gcov >> unittest1.out
	unittest2&> unittest2.out
	gcov -bc dominion.c >> unittest2.out
	cat dominion.c.gcov >> unittest2.out
	unittest3 &> unittest3.out
	gcov -bc dominion.c >> unittest3.out
	cat dominion.c.gcov >> unittest3.out
	unittest4 &> unittest4.out
	gcov -bc dominion.c >> unittest4.out
	cat dominion.c.gcov >> unittest4.out
	unittest5 &> unittest5.out
	gcov -bc dominion.c >> unittest5.out
	cat dominion.c.gcov >> unittest5.out

	randomtestcard1 &> randomtestcard1.out
	gcov -bc dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out
	randomtestcard2 &> randomtestcard2.out
	gcov -bc dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

	randomtestcard3 &> randomtestcard3.out
	gcov -bc dominion.c >> randomtestcard3.out
	cat dominion.c.gcov >> randomtestcard3.out
	gcov -f -b -c dominion.c testresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player cardtest1 cardtest2 cardtest3 cardtest4 cardtest5 unittest1 unittest2 unittest3 unittest4 unittest5 randomtestcard1  randomtestcard2  randomtestcard3  testresults

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe


