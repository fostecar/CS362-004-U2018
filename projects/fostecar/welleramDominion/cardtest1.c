/* -----------------------------------------------------------------------
* Carissa Foster - CS362 - Assignment-3
* This is a unit test implemented for the Smithy card refactored function.
* Updated makefile to include:
*
* testSmithy: cardtest1.c dominion.o rngs.o
* gcc -o testSmithy -g cardtest1.c dominion.o rngs.o $(CFLAGS)
* -----------------------------------------------------------------------
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>


int main() {

	struct gameState testGame;
	int testNum = 0;
	int player = -5;
	int handPos = -5;
	int i;
	int j = -5;
	int fxnRtn = -5;
	int choice1 = -5;
	int choice2 = -5;
	int choice3 = -5;
	int bonus = -5;

	printf("\nBegin Card Test - Smithy\n");

	//deckCt = 5 (1)
	printf("***Test %d (deckCount > 3)***\n", ++testNum);
	printf("Starting Conditions: deck count = 5, hand count = 5 (smithy at pos 2), played card count = 0\n");
	//Test Prep
	player = 0;
	handPos = 2;
	testGame.whoseTurn = player;
	testGame.deckCount[player] = 5;
	testGame.deck[player][0] = village;
	testGame.deck[player][1] = feast;
	testGame.deck[player][2] = gardens;
	testGame.deck[player][3] = mine;
	testGame.deck[player][4] = remodel;
	testGame.handCount[player] = 5;
	testGame.hand[player][0] = council_room;
	testGame.hand[player][1] = great_hall;
	testGame.hand[player][2] = smithy;
	testGame.hand[player][3] = minion;
	testGame.hand[player][4] = steward;
	testGame.playedCardCount = 0;
	testGame.playedCards[0] = -1;
	//cardEffect() call
	fxnRtn = cardEffect(smithy, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: deckCt = 2
	if (testGame.deckCount[player] == 2) {
		printf("PASS : Deck Count correct after card played\n");
	}
	else {
		printf("FAIL : Deck Count incorrect after card played (should be 2, value is %d)\n", testGame.deckCount[player]);
	}
	//Check handCt = 7
	if (testGame.handCount[player] == 7) {
		printf("PASS : Hand Count correct after card played\n");
	}
	else {
		printf("FAIL : Hand Count incorrect after card played (should be 7, value is %d)\n", testGame.handCount[player]);
	}
	//Check: hand does not contain Smithy
	j = 0;
	for (i = 0; i < 7; ++i) {
		if (testGame.hand[player][i] == smithy) {
			printf("FAIL : Smithy found in hand at position %d\n", i);
			j = 1;
		}
		else if ((i == 6) && (j != 1)) {
			printf("PASS : Smithy NOT found in hand\n");
		}
	}
	//Check: playedCardsCt = 1
	if (testGame.playedCardCount == 1) {
		printf("PASS : Played Card Count incremented to 1 is correct\n");
	}
	else {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 1\n", testGame.playedCardCount);
	}
	//Check: played card last card is Smithy
	if (testGame.playedCards[0] == smithy) {
		printf("PASS : Smithy is last card in playedCards\n");
	}
	else {
		printf("FAIL : Smithy is NOT the last card in played Cards, value is %d\n", testGame.playedCards[0]);
	}
	//Check: return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}

	//deck count = 2, discard count = 2 (2)
	printf("***Test %d (deckCount < 3, deckCount + discardCount > 3)***\n", ++testNum);
	printf("Starting Conditions: deck count = 2, hand count = 5 (smithy at pos 0), discard count = 2, played card count = 1\n");
	//Test Prep
	player = 1;
	handPos = 0;
	testGame.whoseTurn = player;
	testGame.deckCount[player] = 2;
	testGame.deck[player][0] = village;
	testGame.deck[player][1] = feast;
	testGame.handCount[player] = 5;
	testGame.hand[player][0] = smithy;
	testGame.hand[player][1] = great_hall;
	testGame.hand[player][2] = sea_hag;
	testGame.hand[player][3] = minion;
	testGame.hand[player][4] = steward;
	testGame.discardCount[player] = 2;
	testGame.discard[player][0] = outpost;
	testGame.discard[player][1] = treasure_map;
	testGame.playedCardCount = 1;
	testGame.playedCards[0] = cutpurse;
	testGame.playedCards[1] = -1;
	//cardEffect() call
	fxnRtn = cardEffect(smithy, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: deckCt = 1
	if (testGame.deckCount[player] == 1) {
		printf("PASS : Deck Count correct after card played\n");
	}
	else {
		printf("FAIL : Deck Count incorrect after card played (should be 1, value is %d)\n", testGame.deckCount[player]);
	}
	//Check handCt = 7
	if (testGame.handCount[player] == 7) {
		printf("PASS : Hand Count correct after card played\n");
	}
	else {
		printf("FAIL : Hand Count incorrect after card played (should be 7, value is %d)\n", testGame.handCount[player]);
	}
	//Check: hand does not contain Smithy
	j = 0;
	for (i = 0; i < 7; ++i) {
		if (testGame.hand[player][i] == smithy) {
			printf("FAIL : Smithy found in hand at position %d\n", i);
			j = 1;
		}
		else if ((i == 6) && (j != 1)) {
			printf("PASS : Smithy NOT found in hand\n");
		}
	}
	//Check: playedCardsCt = 2
	if (testGame.playedCardCount == 2) {
		printf("PASS : Played Card Count incremented to 2 is correct\n");
	}
	else {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 2\n", testGame.playedCardCount);
	}
	//Check: played card last card is Smithy
	if (testGame.playedCards[1] == smithy) {
		printf("PASS : Smithy is last card in playedCards\n");
	}
	else {
		printf("FAIL : Smithy is NOT the last card in played Cards, value is %d\n", testGame.playedCards[1]);
	}
	//Check: return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}
	//Check: discard count is 0
	if (testGame.discardCount[player] == 0) {
		printf("PASS : discard count is 0\n");
	}
	else {
		printf("FAIL: discard count is NOT 0, value is %d\n", testGame.discardCount[player]);
	}

	//deck count = 1, discard count = 1 (3)
	printf("***Test %d (deckCount < 3, deckCount + discardCount < 3)***\n", ++testNum);
	printf("Starting Conditions: deck count = 1, hand count = 5 (smithy at pos 4), discard count = 1, played card count = 0\n");
	//Test Prep
	player = 3;
	handPos = 4;
	testGame.whoseTurn = player;
	testGame.deckCount[player] = 1;
	testGame.deck[player][0] = village;
	testGame.handCount[player] = 5;
	testGame.hand[player][0] = embargo;
	testGame.hand[player][1] = great_hall;
	testGame.hand[player][2] = sea_hag;
	testGame.hand[player][3] = minion;
	testGame.hand[player][4] = smithy;
	testGame.discardCount[player] = 1;
	testGame.discard[player][0] = outpost;
	testGame.playedCardCount = 0;
	testGame.playedCards[0] = -1;
	//cardEffect() call
	fxnRtn = cardEffect(smithy, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: deckCt = 1
	if (testGame.deckCount[player] == 0) {
		printf("PASS : Deck Count correct after card played\n");
	}
	else {
		printf("FAIL : Deck Count incorrect after card played (should be 0, value is %d)\n", testGame.deckCount[player]);
	}
	//Check handCt = 6
	if (testGame.handCount[player] == 6) {
		printf("PASS : Hand Count correct after card played\n");
	}
	else {
		printf("FAIL : Hand Count incorrect after card played (should be 6, value is %d)\n", testGame.handCount[player]);
	}
	//Check: hand does not contain Smithy
	j = 0;
	for (i = 0; i < 7; ++i) {
		if (testGame.hand[player][i] == smithy) {
			printf("FAIL : Smithy found in hand at position %d\n", i);
			j = 1;
		}
		else if ((i == 6) && (j != 1)) {
			printf("PASS : Smithy NOT found in hand\n");
		}
	}
	//Check: playedCardsCt = 1
	if (testGame.playedCardCount == 1) {
		printf("PASS : Played Card Count incremented to 1 is correct\n");
	}
	else {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 1\n", testGame.playedCardCount);
	}
	//Check: played card last card is Smithy
	if (testGame.playedCards[0] == smithy) {
		printf("PASS : Smithy is last card in playedCards\n");
	}
	else {
		printf("FAIL : Smithy is NOT the last card in played Cards, value is %d\n", testGame.playedCards[0]);
	}
	//Check: return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}
	//Check: discard count is 0
	if (testGame.discardCount[player] == 0) {
		printf("PASS : discard count is 0\n");
	}
	else {
		printf("FAIL: discard count is NOT 0, value is %d\n", testGame.discardCount[player]);
	}

	printf("End Card Test - Smithy\n\n");

	return 0;
}

//int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)