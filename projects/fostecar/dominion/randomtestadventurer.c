/*Carissa Foster  CS362  Assignment-4
* Adventurer Random Test
* int cardEffectAdventurer(struct gameState *state, int drawntreasure, int currentPlayer, int *temphand, int cardDrawn, int z);
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

int gameStateRandomSetup(struct gameState *state, int *deckTreasure1, int *deckTreasure2, int *deckTreasureNum, int *discardTreasureNum, int *temphand);

int testResults(struct gameState *testGS, int origHandCnt, int origDeckCnt, int origDiscardCnt, int *temphand, int deckTreasure1, int deckTreasure2, int deckTreasureNum, int discardTreasureNum);

int main() {

	srand(time(NULL));

	int i = -5;
	int numTestRuns = 5;
	int result = 0;
	int numTestRunsFailed = 0;

	struct gameState testGS;
	int deckTreasure1 = -5;
	int deckTreasure2 = -5;
	int deckTreasureNum = -5;
	int discardTreasureNum = -5;

	int drawntreasure = -5;
	int temphand[MAX_DECK];
	int cardDrawn = -5;
	int z = -5;

	int origHandCnt = -5;
	int origDeckCnt = -5;
	int origDiscardCnt = -5;


	for (i = 0; i < numTestRuns; ++i) {
		printf("Test Number %d Begin\n", i);
		z = 0;
		drawntreasure = 0;
		gameStateRandomSetup(&testGS, &deckTreasure1, &deckTreasure2, &deckTreasureNum, &discardTreasureNum, temphand); //setup
		origHandCnt = testGS.handCount[testGS.whoseTurn];
		origDeckCnt = testGS.deckCount[testGS.whoseTurn];
		origDiscardCnt = testGS.discardCount[testGS.whoseTurn];
		cardEffectAdventurer(&testGS, drawntreasure, testGS.whoseTurn, temphand, cardDrawn, z); //run the function under test
		result = testResults(&testGS, origHandCnt, origDeckCnt, origDiscardCnt, temphand, deckTreasure1, deckTreasure2, deckTreasureNum, discardTreasureNum); //check result

		if (result == 1) {
			++numTestRunsFailed;
		}

		printf("Test Number %d End\n\n", i);
	}

	printf("Total Runs PASSED : %d\n", (numTestRuns - numTestRunsFailed));
	printf("Total Runs FAILED : %d\n\n", numTestRunsFailed);

	return 0;
	
}

int gameStateRandomSetup(struct gameState *testGS, int *deckTreasure1, int *deckTreasure2, int *deckTreasureNum, int *discardTreasureNum, int *temphand) {
	int i = -5;
	int max = -5;
	int cnt = -5;
	//srand(time(NULL));


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

	//adventurer card insert
	i = rand() % (*testGS).handCount[(*testGS).whoseTurn];
	(*testGS).hand[(*testGS).whoseTurn][i] = adventurer;

	//deck setup
	max = rand() % 4; //0 to 3
	cnt = 0;
	*deckTreasure1 = -1;
	*deckTreasure2 = -1;
	*deckTreasureNum = 0;
	(*testGS).deckCount[(*testGS).whoseTurn] = rand() % (MAX_DECK + 1 - 1) + 1; //1 to Max_Deck

	for (i = 0; i < MAX_DECK; ++i) {
		if (i < (*testGS).deckCount[(*testGS).whoseTurn]) {
			(*testGS).deck[(*testGS).whoseTurn][i] = rand() % 27;
			if (((*testGS).deck[(*testGS).whoseTurn][i] == copper) || ((*testGS).deck[(*testGS).whoseTurn][i] == silver) || ((*testGS).deck[(*testGS).whoseTurn][i] == gold)) {
				//printf("Assigning Deck Cards: treasure assigned and ");
				if (cnt < max) {
					*deckTreasure2 = *deckTreasure1;
					*deckTreasure1 = i;
					*deckTreasureNum = *deckTreasureNum + 1;
					cnt = cnt + 1;
					//printf("kept.");
				}
				else {
					(*testGS).deck[(*testGS).whoseTurn][i] = rand() % (26 + 1 - 7) + 7; // 7 to 26
					//printf("discarded.");
				}
			}
		}
		else {
			(*testGS).deck[(*testGS).whoseTurn][i] = -1;
		}
		//printf("  i = %d, value is %d (treasure is 4, 5, 6)\n", i, (*testGS).deck[(*testGS).whoseTurn][i]);
	}

	//discard setup
	max = rand() % 4; //0 to 3
	cnt = 0;
	*discardTreasureNum = 0;
	(*testGS).discardCount[(*testGS).whoseTurn] = rand() % ((MAX_DECK - (*testGS).deckCount[(*testGS).whoseTurn]) + 1 - 1) + 1; //1 to Max_Deck

	for (i = 0; i < MAX_DECK; ++i) {
		if (i < (*testGS).discardCount[(*testGS).whoseTurn]) {
			(*testGS).discard[(*testGS).whoseTurn][i] = rand() % 27;
			if (((*testGS).discard[(*testGS).whoseTurn][i] == copper) || ((*testGS).discard[(*testGS).whoseTurn][i] == silver) || ((*testGS).discard[(*testGS).whoseTurn][i] == gold)) {
				//printf("Assigning Discard Cards: treasure assigned and ");
				if (cnt < max) {
					*discardTreasureNum = *discardTreasureNum + 1;
					cnt = cnt + 1;
					//printf("kept.");
				}
				else {
					(*testGS).discard[(*testGS).whoseTurn][i] = rand() % (26 + 1 - 7) + 7; // 7 to 26
					//printf("discarded.");
				}
			}
		}
		else {
			(*testGS).discard[(*testGS).whoseTurn][i] = -1;
		}
		//printf("  i = %d, value is %d (treasure is 4, 5, 6)\n", i, (*testGS).discard[(*testGS).whoseTurn][i]);
	}

	//temphand initialize
	for (i = 0; i < MAX_HAND; ++i) {
		temphand[i] = -1;
	}

	/*
	printf("in setup:\n");
	printf("deck T 1: %d\n", *deckTreasure1);
	printf("deck T 2: %d\n", *deckTreasure2);
	printf("deck T Num: %d\n", *deckTreasureNum);
	printf("discard T Num: %d\n", *discardTreasureNum);
	*/

	return 0;

}


int testResults(struct gameState *testGS, int origHandCnt, int origDeckCnt, int origDiscardCnt, int *temphand, int deckTreasure1, int deckTreasure2, int deckTreasureNum, int discardTreasureNum) {
	int failCnt = 0;

	printf("Hand Cnt: original = %d, current = %d\n", origHandCnt, (*testGS).handCount[(*testGS).whoseTurn]);
	printf("Deck Cnt: original = %d, current = %d\n", origDeckCnt, (*testGS).deckCount[(*testGS).whoseTurn]);
	printf("Discard Cnt: original = %d, current = %d\n", origDiscardCnt, (*testGS).discardCount[(*testGS).whoseTurn]);
	printf("Deck Treasure Locations: %d, %d\n", deckTreasure2, deckTreasure1);
	printf("Deck Treasure count: %d\n", deckTreasureNum);
	printf("Discard Treasure count: %d\n", discardTreasureNum);
	 
	//hand count check and hand added treasure check
	if (((deckTreasureNum == 0) && (discardTreasureNum == 0)) && ((*testGS).handCount[(*testGS).whoseTurn] != origHandCnt)) {
		printf("FAIL(1.0) : Resulting Hand Count Incorrect\n");
		++failCnt;
		if ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != -1) {
			printf("FAIL(1.0.1) : Hand Cards Incorrect at %d\n", origHandCnt);
			++failCnt;
		}
		if ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt + 1)] != -1) {
			printf("FAIL(1.0.2) : Hand Cards Incorrect at %d\n", (origHandCnt + 1));
			++failCnt;
		}
	}
	else if (((deckTreasureNum == 1) && (discardTreasureNum == 0)) && ((*testGS).handCount[(*testGS).whoseTurn] != (origHandCnt + 1))) {
		printf("FAIL(1.1) : Resulting Hand Count Incorrect\n");
		++failCnt;
		if (((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != copper) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != silver) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != gold)) {
			printf("FAIL(1.1.1) : Hand Cards Incorrect at %d\n", origHandCnt);
			++failCnt;
		}
		if ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt + 1)] != -1) {
			printf("FAIL(1.1.2) : Hand Cards Incorrect at %d\n", (origHandCnt + 1));
			++failCnt;
		}
	}
	else if (((deckTreasureNum == 0) && (discardTreasureNum == 1)) && ((*testGS).handCount[(*testGS).whoseTurn] != (origHandCnt + 1))) {
		printf("FAIL(1.2) : Resulting Hand Count Incorrect\n");
		++failCnt;
		if (((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != copper) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != silver) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != gold)) {
			printf("FAIL(1.2.1) : Hand Cards Incorrect at %d\n", origHandCnt);
			++failCnt;
		}
		if ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt + 1)] != -1) {
			printf("FAIL(1.2.2) : Hand Cards Incorrect at %d\n", (origHandCnt + 1));
			++failCnt;
		}
	}
	else if (((deckTreasureNum == 1) && (discardTreasureNum >= 1)) && ((*testGS).handCount[(*testGS).whoseTurn] != (origHandCnt + 2))) {
		printf("FAIL(1.3) : Resulting Hand Count Incorrect\n");
		++failCnt;
		if (((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != copper) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != silver) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != gold)) {
			printf("FAIL(1.3.1) : Hand Cards Incorrect at %d\n", origHandCnt);
			++failCnt;
		}
		if (((*testGS).hand[(*testGS).whoseTurn][(origHandCnt + 1)] != copper) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt + 1)] != silver) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt + 1)] != gold)) {
			printf("FAIL(1.3.2) : Hand Cards Incorrect at %d\n", (origHandCnt + 1));
			++failCnt;
		}
	}
	else if (((deckTreasureNum == 0) && (discardTreasureNum >= 2)) && ((*testGS).handCount[(*testGS).whoseTurn] != (origHandCnt + 2))) {
		printf("FAIL(1.4) : Resulting Hand Count Incorrect\n");
		++failCnt;
		if (((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != copper) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != silver) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != gold)) {
			printf("FAIL(1.4.1) : Hand Cards Incorrect at %d\n", origHandCnt);
			++failCnt;
		}
		if (((*testGS).hand[(*testGS).whoseTurn][(origHandCnt + 1)] != copper) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt + 1)] != silver) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt + 1)] != gold)) {
			printf("FAIL(1.4.2) : Hand Cards Incorrect at %d\n", (origHandCnt + 1));
			++failCnt;
		}
	}
	else if ((deckTreasureNum >= 2)  && ((*testGS).handCount[(*testGS).whoseTurn] != (origHandCnt + 2))) {
		printf("FAIL(1.5) : Resulting Hand Count Incorrect\n");
		++failCnt;
		if (((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != copper) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != silver) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt)] != gold)) {
			printf("FAIL(1.5.1) : Hand Cards Incorrect at %d\n", origHandCnt);
			++failCnt;
		}
		if (((*testGS).hand[(*testGS).whoseTurn][(origHandCnt + 1)] != copper) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt + 1)] != silver) && ((*testGS).hand[(*testGS).whoseTurn][(origHandCnt + 1)] != gold)) {
			printf("FAIL(1.5.2) : Hand Cards Incorrect at %d\n", (origHandCnt + 1));
			++failCnt;
		}
	}

	//deck count check
	if (((deckTreasureNum == 0) && (discardTreasureNum == 0)) && ((*testGS).deckCount[(*testGS).whoseTurn] != 0)) {
		printf("FAIL(2.0) : Resulting Deck Count Incorrect\n");
		++failCnt;
	}
	else if (((deckTreasureNum == 1) && (discardTreasureNum == 0)) && ((*testGS).deckCount[(*testGS).whoseTurn] != 0)) {
		printf("FAIL(2.1) : Resulting Deck Count Incorrect\n");
		++failCnt;
	}
	else if (((deckTreasureNum == 0) && (discardTreasureNum == 1)) && ((*testGS).deckCount[(*testGS).whoseTurn] != 0)) {
		printf("FAIL(2.2) : Resulting Deck Count Incorrect\n");
		++failCnt;
	}
	else if (((deckTreasureNum == 1) && (discardTreasureNum >= 1)) && (((*testGS).deckCount[(*testGS).whoseTurn] < 0 ) || ((*testGS).deckCount[(*testGS).whoseTurn] > (origDiscardCnt -1)))) {
		printf("FAIL(2.3) : Resulting Deck Count Incorrect\n");
		++failCnt;
	}
	else if (((deckTreasureNum == 0) && (discardTreasureNum >= 2)) && (((*testGS).deckCount[(*testGS).whoseTurn] < 0) || ((*testGS).deckCount[(*testGS).whoseTurn] > (origDiscardCnt - 2)))) {
		printf("FAIL(2.4) : Resulting Deck Count Incorrect\n");
		++failCnt;
	}
	else if ((deckTreasureNum >= 2) && (((*testGS).deckCount[(*testGS).whoseTurn] < 0)|| ((*testGS).deckCount[(*testGS).whoseTurn] > (origDeckCnt - 2)))) {
		printf("FAIL(2.5) : Resulting Deck Count Incorrect\n");
		++failCnt;
	}	

	//discard count check
	if (((deckTreasureNum == 0) && (discardTreasureNum == 0)) && ((*testGS).discardCount[(*testGS).whoseTurn] != (origDeckCnt + origDiscardCnt))) {
		printf("FAIL(3.0) : Resulting Discard Count Incorrect\n");
		++failCnt;
	}
	else if (((deckTreasureNum == 1) && (discardTreasureNum == 0)) && ((*testGS).discardCount[(*testGS).whoseTurn] != ((origDeckCnt -1) + origDiscardCnt))) {
		printf("FAIL(3.1) : Resulting Discard Count Incorrect\n");
		++failCnt;
	}
	else if (((deckTreasureNum == 0) && (discardTreasureNum == 1)) && ((*testGS).discardCount[(*testGS).whoseTurn] != (origDeckCnt + (origDiscardCnt - 1)))) {
		printf("FAIL(3.2) : Resulting Discard Count Incorrect\n");
		++failCnt;
	}
	else if (((deckTreasureNum == 1) && (discardTreasureNum >= 1)) && (((*testGS).discardCount[(*testGS).whoseTurn] < (origDeckCnt - 1))|| ((*testGS).discardCount[(*testGS).whoseTurn] > ((origDeckCnt - 1) + (origDiscardCnt - 1))))) {
		printf("FAIL(3.3) : Resulting Discard Count Incorrect\n");
		++failCnt;
	}
	else if (((deckTreasureNum == 0) && (discardTreasureNum >= 2)) && (((*testGS).discardCount[(*testGS).whoseTurn] < origDeckCnt) || ((*testGS).discardCount[(*testGS).whoseTurn] > (origDeckCnt + (origDiscardCnt - 2))))) {
		printf("FAIL(3.4) : Resulting Discard Count Incorrect\n");
		++failCnt;
	}
	else if ((deckTreasureNum >= 2) && (((*testGS).discardCount[(*testGS).whoseTurn] < origDiscardCnt) || ((*testGS).discardCount[(*testGS).whoseTurn] > ((origDeckCnt - 2) + origDiscardCnt)))) {
		printf("FAIL(3.5) : Resulting Discard Count Incorrect\n");
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