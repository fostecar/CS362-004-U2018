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

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe *.exe
	rm -f testGetCost testGetCost.exe testFullDeckCount testFullDeckCount.exe testKingdomCards testKingdomCards.ece testHandCard testHandCard.exe
	rm -f testSmithy testSmithy.exe testAdventurer testAdventurer.exe testCutpurse testCutpurse.exe testCouncilRoom testCouncilRoom.exe
	rm -f randTestAdventurer randTestAdventurer.exe randTestSmithy randTestSmithy.exe randTestCutpurse randTestCutpurse.exe

############################################################################
#Unit Tests from Assignment - 3
#getCost()
testGetCost: unittest1.c dominion.o rngs.o
	gcc -o testGetCost unittest1.c -g dominion.o rngs.o $(CFLAGS)

#fullDeckCount()
testFullDeckCount: unittest2.c dominion.o rngs.o
	gcc -o testFullDeckCount unittest2.c -g dominion.o rngs.o $(CFLAGS)

#kingdomCards
testKingdomCards: unittest3.c dominion.o rngs.o
	gcc -o testKingdomCards unittest3.c -g dominion.o rngs.o $(CFLAGS)

#handCard
testHandCard: unittest4.c dominion.o rngs.o
	gcc -o testHandCard unittest4.c -g dominion.o rngs.o $(CFLAGS)

#Smithy
testSmithy: cardtest1.c dominion.o rngs.o
	gcc -o testSmithy -g cardtest1.c dominion.o rngs.o $(CFLAGS)

#Adventurer
testAdventurer: cardtest2.c dominion.o rngs.o
	gcc -o testAdventurer -g cardtest2.c dominion.o rngs.o $(CFLAGS)

#Cutpurse
testCutpurse: cardtest3.c dominion.o rngs.o
	gcc -o testCutpurse -g cardtest3.c dominion.o rngs.o $(CFLAGS)

#CouncilRoom
testCouncilRoom: cardtest4.c dominion.o rngs.o
	gcc -o testCouncilRoom -g cardtest4.c dominion.o rngs.o $(CFLAGS)

resultsTestAdventurer: testadventurer.out

testadventurer.out: cardtest2.c dominion.c rngs.c
	echo "Result for running Adventurer unit test:" > testadventurer.out
	
	echo "cardtest2.c:" >> testadventurer.out
	gcc -o testAdventurer dominion.c rngs.c cardtest2.c $(CFLAGS)
	testAdventurer >> testadventurer.out
	gcov dominion.c -b >> testadventurer.out

resultsTestSmithy: testsmithy.out

testsmithy.out: cardtest1.c dominion.c rngs.c
	echo "Result for running Smithy unit test:" > testsmithy.out
	
	echo "cardtest1.c:" >> testsmithy.out
	gcc -o testSmithy dominion.c rngs.c cardtest1.c $(CFLAGS)
	testSmithy >> testsmithy.out
	gcov dominion.c -b >> testsmithy.out


############################################################################
#Random Tests from Assignment - 4
randTestAdventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randTestAdventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

randTestSmithy: randomtestcard1.c dominion.o rngs.o
	gcc -o randTestSmithy randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)

randTestCutpurse: randomtestcard2.c dominion.o rngs.o
	gcc -o randTestCutpurse randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)

resultsRandTestAdventurer: randomtestadventurer.out

randomtestadventurer.out: randomtestadventurer.c dominion.c rngs.c
	echo "Result for running Adventurer random test:" > randomtestadventurer.out
	
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -o randTestAdventurer dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	randTestAdventurer >> randomtestadventurer.out
	gcov dominion.c -b >> randomtestadventurer.out
	#gcov randomtestadventurer.c -b >> randomtestadventurer.out

resultsRandTestSmithy: randomtestsmithy.out

randomtestsmithy.out: randomtestcard1.c dominion.c rngs.c
	echo "Result for running Smithy random test:" > randomtestsmithy.out
	
	echo "randomtestcard1.c:" >> randomtestsmithy.out
	gcc -o randTestSmithy dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	randTestSmithy >> randomtestsmithy.out
	gcov dominion.c -b >> randomtestsmithy.out
	#gcov randomtestcard1.c -b >> randomtestsmithy.out





############################################################################
#Make All Tests from Assign3 & Assign4
allTests: testGetCost testFullDeckCount testKingdomCards testHandCard testSmithy testAdventurer testCutpurse testCouncilRoom randTestAdventurer randTestSmithy randTestCutpurse 
