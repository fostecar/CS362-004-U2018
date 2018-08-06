/*Carissa Foster  CS362  Assignment-4
* Cutpurse Random Test
* int cardEffectCutpurse(struct gameState *state, int currentPlayer, int handPos, int i, int j, int k);
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

int gameStateRandomSetup(struct gameState *state, int *handPos, int *origNumCoppers);

int testResults(struct gameState *testGS, int *origHandCnt, int origPlayedCardCnt, int origCoins, int *origNumCoppers);

int findNumCoppers(int player, struct gameState *testGS);

int main() {

	srand(time(NULL));

	int i = -5;
	int j = -5;
	int x = -5;
	int y = -5;
	int z = -5;
	int numTestRuns = 5;
	int result = 0;
	int numTestRunsFailed = 0;

	struct gameState testGS;

	int handPos = -5;

	int origHandCnt[MAX_PLAYERS];
	int origCoins = -5;
	int origNumCoppers[MAX_PLAYERS];
	int origPlayedCardCnt = -5;

	printf("CUTPURSE TEST\n\n");

	for (i = 0; i < numTestRuns; ++i) {
		printf("Test Number %d Begin\n", (i + 1));
		x = 0;
		y = 0;
		z = 0;
		gameStateRandomSetup(&testGS, &handPos, origNumCoppers); //setup
		for (j = 0; j < MAX_PLAYERS; ++j) {
			origHandCnt[j] = testGS.handCount[j];
		}
		origCoins = testGS.coins;
		origPlayedCardCnt = testGS.playedCardCount;
		cardEffectCutpurse(&testGS, testGS.whoseTurn, handPos, x, y, z); //run the function under test
		result = testResults(&testGS, origHandCnt, origPlayedCardCnt, origCoins, origNumCoppers); //check result

		if (result == 1) {
			++numTestRunsFailed;
		}

		printf("Test Number %d End\n\n", (i + 1));
	}

	printf("Total Runs PASSED : %d\n", (numTestRuns - numTestRunsFailed));
	printf("Total Runs FAILED : %d\n\n", numTestRunsFailed);

	return 0;

}

int gameStateRandomSetup(struct gameState *testGS, int *handPos, int *origNumCoppers) {
	int i = -5;
	int j = -5;
	int maxNumCoppers = -5;
	int numCoppers = -5;


	//game player setup
	(*testGS).numPlayers = rand() % (MAX_PLAYERS + 1 - 2) + 2; //1-4
	(*testGS).whoseTurn = rand() % (*testGS).numPlayers;

	//hand setup
	(*testGS).handCount[(*testGS).whoseTurn] = rand() % (MAX_HAND + 1 - 1) + 1; //1 to Max_Hand

	for (i = 0; i < MAX_HAND; ++i) {
		if (i < (*testGS).handCount[(*testGS).whoseTurn]) {
			(*testGS).hand[(*testGS).whoseTurn][i] = rand() % 27;
		}
		else {
			(*testGS).hand[(*testGS).whoseTurn][i] = -1;
		}
	}

	//cutpurse card insert
	i = rand() % (*testGS).handCount[(*testGS).whoseTurn];
	(*testGS).hand[(*testGS).whoseTurn][i] = cutpurse;
	*handPos = i;

	//played cards count
	(*testGS).playedCardCount = rand() % (MAX_DECK - 1);

	//update coins
	updateCoins((*testGS).whoseTurn, testGS, 0);

	//other players hand setup
	for (j = 0; j < (*testGS).numPlayers; ++j) {
		if (j != (*testGS).whoseTurn) {
			(*testGS).handCount[j] = rand() % MAX_HAND; //0 to MAX_DECK
			maxNumCoppers = rand() % 3; //0 to 2
			numCoppers = 0;

			for (i = 0; i < MAX_HAND; ++i) {
				if (i < (*testGS).handCount[j]) {
					(*testGS).hand[j][i] = rand() % 27;
					if (numCoppers >= maxNumCoppers) {
						(*testGS).hand[j][i] = rand() % (26 + 1 - 5) + 5; //5 to 26
					}
					else {
						++numCoppers;
					}
				}
				else {
					(*testGS).hand[j][i] = -1;
				}
			}
		}
		origNumCoppers[j] = numCoppers;
	}





	return 0;

}


int testResults(struct gameState *testGS, int *origHandCnt, int origPlayedCardCnt, int origCoins, int *origNumCoppers){
	int failCnt = 0;
	int i = -5;
	int x = -5;

	printf("Num Coins: original = %d, current = %d\n", origCoins, (*testGS).coins);
	printf("Hand Cnt: (Current Player %d) original = %d, current = %d\n", (*testGS).whoseTurn, origHandCnt[(*testGS).whoseTurn], (*testGS).handCount[(*testGS).whoseTurn]);
	for (i = 0; i < (*testGS).numPlayers; ++i) {
		if (i != (*testGS).whoseTurn) {
			printf("Hand Cnt: (Player %d) original = %d, current = %d\n", i, origHandCnt[i], (*testGS).handCount[i]);
		}
	}
	for (i = 0; i < (*testGS).numPlayers; ++i) {
		if (i != (*testGS).whoseTurn) {
			printf("Copper Cnt: (Player %d) original = %d, current = %d\n", i, origNumCoppers[i], findNumCoppers(i, testGS));
		}
	}
	printf("Played Card Cnt: original = %d, current = %d\n", origPlayedCardCnt, (*testGS).playedCardCount);

	//player number of coins
	if ((*testGS).coins != (origCoins + 2)) {
		printf("FAIL(1.0) : Resulting Coins Count is Incorrect\n");
		++failCnt;
	}

	//hand count check curr player
	if ((*testGS).handCount[(*testGS).whoseTurn] != (origHandCnt[(*testGS).whoseTurn] - 1)) {
		printf("FAIL(2.0) : Resulting Hand Count Incorrect For Current Player (%d)\n", (*testGS).whoseTurn);
		++failCnt;
	}
	for (i = 0; i < (*testGS).numPlayers; ++i) {
		if (i != (*testGS).whoseTurn) {
			if ((origNumCoppers[i] >= 1) && ((*testGS).handCount[i] != (origHandCnt[i] - 1))) {
				printf("FAIL(2.1) : Resulting Hand Count Incorrect For Other Player %d\n", i);
				++failCnt;
			}
		}
	}

	//played card count check
	x = 1;
	for (i = 0; i < (*testGS).numPlayers; ++i) {
		if (i != (*testGS).whoseTurn) {
			if (origNumCoppers[i] >= 1) {
				++x;
			}
		}
	}

	if ((*testGS).playedCardCount != (origPlayedCardCnt + x)) {
		printf("FAIL(3.0) : Resulting Played Card Count Incorrect\n");
		++failCnt;
	}


	if (failCnt > 0) {
		printf("Test Run Fail Count : %d\n", failCnt);
		return 1;
	}
	else {
		printf("All Tests Passed!\n");
		return 0;
	}

	return -1;
}

int findNumCoppers(int player, struct gameState *testGS) {
	int numCoppers = 0;
	int i = -5;

	for (i = 0; i < (*testGS).handCount[player]; ++i) {
		if ((*testGS).hand[player][i] == copper) {
			numCoppers++;
		}
	}

	return numCoppers;
}



//rand() % (max_number + 1 - minimum_number) + minimum_number