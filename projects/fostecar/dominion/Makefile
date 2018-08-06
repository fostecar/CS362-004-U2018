CFLAGS = -Wall -fpic -coverage -lm -std=c99

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


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

randTestAdventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randTestAdventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

randTestSmithy: randomtestcard1.c dominion.o rngs.o
	gcc -o randTestSmithy randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)

randTestCutpurse: randomtestcard2.c dominion.o rngs.o
	gcc -o randTestCutpurse randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)

resultsAdventurer: randomtestadventurer.out

randomtestadventurer.out: randomtestadventurer.c dominion.c rngs.c
	echo "Result for running Adventurer random test:" > randomtestadventurer.out
	
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o randTestAdventurer dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	randTestAdventurer >> randomtestadventurer.out
	gcov randomtestadventurer.c -b >> randomtestadventurer.out

resultsCard1: randomtestcard1.out

randomtestcard1.out: randomtestcard1.c dominion.c rngs.c
	echo "Result for running Smithy random test:" > randomtestcard1.out
	
	echo "randomtestcard2.c:" >> randomtestcard1.out
	gcc -o randTestSmithy dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	randTestSmithy >> randomtestcard1.out
	gcov randomtestcard1.c -b >> randomtestcard1.out


resultsCard2: randomtestcard2.out

randomtestcard2.out: randomtestcard2.c dominion.c rngs.c
	echo "Result for running Cutpurse random test:" > randomtestcard2.out
	
	echo "randomtestcard2.c:" >> randomtestcard2.out
	gcc -o randTestCutpurse dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	randTestCutpurse >> randomtestcard2.out
	gcov randomtestcard2.c -b >> randomtestcard2.out

runAllRandTests: resultsAdventurer resultsCard1 resultsCard2


all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe randTestAdventurer randTestAdventurer.exe randTestSmithy randTestSmithy.exe randTestCutpurse randTestCutpurse.exe
