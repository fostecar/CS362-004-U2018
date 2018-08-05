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

int gameStateRandomSetup(struct gameState *state, int *deckTreasure1, int *deckTreasure2, int *discardTreasureNum);

int main() {

	int i = -5;
	int numTestRuns = 1;

	struct gameState testGS;
	int deckTreasure1 = -5;
	int deckTreasure2 = -5;
	int discardTreasureNum = -5;

	int drawtreasure = -5;
	int temphand[MAX_DECK];
	int cardDrawn = -5;
	int z = -5;

	for (i = 0; i < numTestRuns; ++i) {
		printf("\nTest Number %d Begin\n", i);
		z = 0;
		drawtreasure = 0;
		gameStateRandomSetup(testGS, &deckTreasure1, &deckTreasure2, &discardTreasureNum);
		cardEffectAdventurer(testGS, drawntreasure, testGS.whoseTurn, &temphand, cardDrawn, z);
		printf("\nTest Number %d End\n", i);
	}

	printf("\nTest Complete\n");


	return 1;
	
}

int gameStateRandomSetup(struct gameState *state, int *deckTreasure1, int *deckTreasure2, int *discardTreasureNum) {
	int i = -5;
	srand(time(0));


	//game player setup
	testGS.numPlayers = rand() % (MAX_PLAYERS + 1 - 1) + 1; //1-4
	testGS.whoseTurn = rand() % testGS.numPlayers;

	//hand setup
	testGS.handCount[testGS.whoseTurn] = rand() % (MAX_HAND + 1 - 1) + 1; //1 to Max_Hand

	for (i = 0; i < MAX_HAND; ++i) {
		if (i < testGS.handCount[testGS.whoseTurn]) {
			testGS.hand[testGS.whoseTurn][i] = rand() % 27;
		}
		else {
			testGS.hand[testGS.whoseTurn][i] = -1;
		}
	}

	//adventurer card insert
	i = rand() % testGS.handCount[testGS.whoseTurn];
	testGS.hand[testGS.whoseTurn][i] = adventurer;

	//deck setup
	*deckTreasure1 = -1;
	*deckTreasure2 = -1;
	testGS.deckCount[testGS.whoseTurn] = rand() % (MAX_DECK + 1 - 1) + 1; //1 to Max_Deck

	for (i = 0; i < MAX_DECK; ++i) {
		if (i < testGS.deckCount[testGS.whoseTurn]) {
			testGS.deck[testGS.whoseTurn][i] = rand() % 27;
			if ((testGS.deck[testGS.whoseTurn][i] == copper) || (testGS.deck[testGS.whoseTurn][i] == silver) || (testGS.deck[testGS.whoseTurn][i] == gold)) {
				*deckTreasure2 = *deckTreasure1;
				*deckTreasure1 = i;
			}
		}
		else {
			testGS.deck[testGS.whoseTurn][i] = -1;
		}
	}

	//discard setup
	*discardTreasureNum = 0;
	testGS.discardCount[testGS.whoseTurn] = rand() % ((MAX_DECK - testGS.deckCount[testGS.whoseTurn]) + 1 - 1) + 1; //1 to Max_Deck

	for (i = 0; i < MAX_DECK; ++i) {
		if (i < testGS.discardCount[testGS.whoseTurn]) {
			testGS.discard[testGS.whoseTurn][i] = rand() % 27;
			if ((testGS.deck[testGS.whoseTurn][i] == copper) || (testGS.deck[testGS.whoseTurn][i] == silver) || (testGS.deck[testGS.whoseTurn][i] == gold)) {
				*discardTreasureNum = *discardTreasureNum + 1;
			}
		}
		else {
			testGS.discard[testGS.whoseTurn][i] = -1;
		}
	}

	return 1;

}

//rand() % (max_number + 1 - minimum_number) + minimum_number