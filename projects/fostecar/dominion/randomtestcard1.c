/*Carissa Foster  CS362  Assignment-4
* Smithy Random Test
* int cardEffectSmithy(struct gameState *state, int currentPlayer, int handPos, int i);
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

int gameStateRandomSetup(struct gameState *state, int *handPos);

int testResults(struct gameState *testGS, int origHandCnt, int origDeckCnt, int origDiscardCnt, int origPlayedCardCnt);

int main() {

	srand(time(NULL));

	int i = -5;
	int z = -5;
	int numTestRuns = 50;
	int result = 0;
	int numTestRunsFailed = 0;

	struct gameState testGS;

	int handPos = -5;

	int origHandCnt = -5;
	int origDeckCnt = -5;
	int origDiscardCnt = -5;
	int origPlayedCardCnt = -5;

	printf("SMITHY TEST\n\n");

	for (i = 0; i < numTestRuns; ++i) {
		printf("Test Number %d Begin\n", (i + 1));
		z = 0;
		gameStateRandomSetup(&testGS, &handPos); //setup
		origHandCnt = testGS.handCount[testGS.whoseTurn];
		origDeckCnt = testGS.deckCount[testGS.whoseTurn];
		origDiscardCnt = testGS.discardCount[testGS.whoseTurn];
		origPlayedCardCnt = testGS.playedCardCount;
		cardEffectSmithy(&testGS, testGS.whoseTurn, handPos, z); //run the function under test
		result = testResults(&testGS, origHandCnt, origDeckCnt, origDiscardCnt, origPlayedCardCnt); //check result

		if (result == 1) {
			++numTestRunsFailed;
		}

		printf("Test Number %d End\n\n", (i + 1));
	}

	printf("Total Runs PASSED : %d\n", (numTestRuns - numTestRunsFailed));
	printf("Total Runs FAILED : %d\n\n", numTestRunsFailed);

	return 0;

}

int gameStateRandomSetup(struct gameState *testGS, int *handPos) {
	int i = -5;


	//game player setup
	(*testGS).numPlayers = rand() % (MAX_PLAYERS + 1 - 1) + 1; //1-4
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

	//smithy card insert
	i = rand() % (*testGS).handCount[(*testGS).whoseTurn];
	(*testGS).hand[(*testGS).whoseTurn][i] = smithy;
	*handPos = i;

	//deck setup
	(*testGS).deckCount[(*testGS).whoseTurn] = rand() % 6; //0 to 5

	for (i = 0; i < MAX_DECK; ++i) {
		if (i < (*testGS).deckCount[(*testGS).whoseTurn]) {
			(*testGS).deck[(*testGS).whoseTurn][i] = rand() % 27;
		}
		else {
			(*testGS).deck[(*testGS).whoseTurn][i] = -1;
		}
	}

	//discard setup
	(*testGS).discardCount[(*testGS).whoseTurn] = rand() % 6; //0 to 5

	for (i = 0; i < MAX_DECK; ++i) {
		if (i < (*testGS).discardCount[(*testGS).whoseTurn]) {
			(*testGS).discard[(*testGS).whoseTurn][i] = rand() % 27;
		}
		else {
			(*testGS).discard[(*testGS).whoseTurn][i] = -1;
		}
	}

	//played cards count
	(*testGS).playedCardCount = rand() % (MAX_DECK - 1);

	return 0;

}


int testResults(struct gameState *testGS, int origHandCnt, int origDeckCnt, int origDiscardCnt, int origPlayedCardCnt) {
	int failCnt = 0;

	printf("Hand Cnt: original = %d, current = %d\n", origHandCnt, (*testGS).handCount[(*testGS).whoseTurn]);
	printf("Deck Cnt: original = %d, current = %d\n", origDeckCnt, (*testGS).deckCount[(*testGS).whoseTurn]);
	printf("Discard Cnt: original = %d, current = %d\n", origDiscardCnt, (*testGS).discardCount[(*testGS).whoseTurn]);
	printf("Played Card Cnt: original = %d, current = %d\n", origPlayedCardCnt, (*testGS).playedCardCount);

	//hand count check
	if (((origDeckCnt == 0) && (origDiscardCnt == 0)) && ((*testGS).handCount[(*testGS).whoseTurn] != (origHandCnt - 1))) {
		printf("FAIL(1.0) : Resulting Hand Count Incorrect\n");
		++failCnt;
	}
	else if (((origDeckCnt + origDiscardCnt) == 1) && ((*testGS).handCount[(*testGS).whoseTurn] != origHandCnt)) {
		printf("FAIL(1.1) : Resulting Hand Count Incorrect\n");
		++failCnt;
	}
	else if (((origDeckCnt + origDiscardCnt) == 2) && ((*testGS).handCount[(*testGS).whoseTurn] != (origHandCnt + 1))) {
		printf("FAIL(1.2) : Resulting Hand Count Incorrect\n");
		++failCnt;
	}
	else if (((origDeckCnt + origDiscardCnt) == 3) && ((*testGS).handCount[(*testGS).whoseTurn] != (origHandCnt + 2))) {
		printf("FAIL(1.3) : Resulting Hand Count Incorrect\n");
		++failCnt;
	}
	else if (((origDeckCnt + origDiscardCnt) > 3) && ((*testGS).handCount[(*testGS).whoseTurn] != (origHandCnt + 2))) {
		printf("FAIL(1.4) : Resulting Hand Count Incorrect\n");
		++failCnt;
	}

	//deck count check
	if (((origDeckCnt == 0) && (origDiscardCnt == 0)) && ((*testGS).deckCount[(*testGS).whoseTurn] != 0)) {
		printf("FAIL(2.0) : Resulting Deck Count Incorrect\n");
		++failCnt;
	}
	else if ((((origDeckCnt == 1) || (origDeckCnt == 2)) && (origDiscardCnt == 1)) && ((*testGS).deckCount[(*testGS).whoseTurn] != 0)) {
		printf("FAIL(2.1) : Resulting Deck Count Incorrect\n");
		++failCnt;
	}
	else if ((((origDeckCnt == 1) || (origDeckCnt == 2)) && (origDiscardCnt >= 2)) && ((*testGS).deckCount[(*testGS).whoseTurn] != (origDeckCnt + origDiscardCnt - 3))) {
		printf("FAIL(2.2) : Resulting Deck Count Incorrect\n");
		++failCnt;
	}
	else if ((origDeckCnt >= 3) && ((*testGS).deckCount[(*testGS).whoseTurn] != (origDeckCnt - 3))) {
		printf("FAIL(2.3) : Resulting Deck Count Incorrect\n");
		++failCnt;
	}
	else if ((origDeckCnt == 0) && (origDiscardCnt < 3) && ((*testGS).deckCount[(*testGS).whoseTurn] != 0)) {
		printf("FAIL(2.4) : Resulting Deck Count Incorrect\n");
		++failCnt;
	}
	else if ((origDeckCnt == 0) && (origDiscardCnt >= 3) && ((*testGS).deckCount[(*testGS).whoseTurn] != (origDiscardCnt - 3))) {
		printf("FAIL(2.5) : Resulting Deck Count Incorrect\n");
		++failCnt;
	}

	//discard count check
	if ((origDeckCnt < 3) && ((*testGS).discardCount[(*testGS).whoseTurn] != 0)) {
		printf("FAIL(3.0) : Resulting Discard Count Incorrect\n");
		++failCnt;
	}
	else if ((origDeckCnt >= 3) && ((*testGS).discardCount[(*testGS).whoseTurn] != origDiscardCnt)) {
		printf("FAIL(3.1) : Resulting Discard Count Incorrect\n");
		++failCnt;
	}

	//played card count check
	if ((*testGS).playedCardCount != (origPlayedCardCnt + 1)) {
		printf("FAIL(4.0) : Resulting Played Card Count Incorrect\n");
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



//rand() % (max_number + 1 - minimum_number) + minimum_number