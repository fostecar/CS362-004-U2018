/* -----------------------------------------------------------------------
* Carissa Foster - CS362 - Assignment-3
* This is a unit test implemented for the Adventurer card refactored function.
* Updated makefile to include:
*
* testAdventurer: cardtest2.c dominion.o rngs.o
* gcc -o testAdventurer -g cardtest2.c dominion.o rngs.o $(CFLAGS)
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
	int i = -5;
	int j = -5;
	int k = -5;
	int fxnRtn = -5;
	int choice1 = -5;
	int choice2 = -5;
	int choice3 = -5;
	int bonus = -5;

	printf("\nBegin Card Test - Adventurer\n");

	//2 Treasure in Deck
	printf("*** Test %d ***\n", ++testNum);
	printf("Starting Conditions: top two cards in deck are treasure cards\n");
	//Test Prep
	player = 0;
	handPos = 0;
	testGame.whoseTurn = player;
	testGame.deckCount[player] = 2;
	testGame.deck[player][0] = copper;
	testGame.deck[player][1] = gold;
	testGame.handCount[player] = 1;
	testGame.hand[player][0] = adventurer;
	testGame.discardCount[player] = 0;
	testGame.playedCardCount = 0;
	testGame.playedCards[0] = -1;
	//cardEffect() call
	fxnRtn = cardEffect(adventurer, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: deck count = 0
	if (testGame.deckCount[player] == 0) {
		printf("PASS : Deck Count correct after card played\n");
	}
	else {
		printf("FAIL : Deck Count incorrect after card played (should be 0, value is %d)\n", testGame.deckCount[player]);
	}
	//Check: hand count = 2
	if (testGame.handCount[player] == 2) {
		printf("PASS : Hand Count correct after card played\n");
	}
	else {
		printf("FAIL : Hand Count incorrect after card played (should be 2, value is %d)\n", testGame.handCount[player]);
	}
	//Check: discard count = 0
	if (testGame.discardCount[player] == 0) {
		printf("PASS : Discard Count correct after card played\n");
	}
	else {
		printf("FAIL : Discard Count incorrect after card played (should be 0, value is %d)\n", testGame.discardCount[player]);
	}
	//Check: played card count = 1
	if (testGame.playedCardCount == 1) {
		printf("PASS : Played Card Count incremented to 1 is correct\n");
	}
	else {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 1\n", testGame.playedCardCount);
	}
	//Check: last played card is Adventurer
	if (testGame.playedCards[0] == adventurer) {
		printf("PASS : Adventurer is last card in playedCards\n");
	}
	else {
		printf("FAIL : Adventurer is NOT the last card in played Cards, value is %d\n", testGame.playedCards[0]);
	}
	//Check: hand has two treasuer cards
	j = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if ((testGame.hand[player][i] == copper) || (testGame.hand[player][i] == silver) || (testGame.hand[player][i] == gold)) {
			++j;
		}
	}
	if (j != 2) {
		printf("FAIL : Incorrect number of treasures found in hand %d, correct count is 2\n", j);
	}
	else {
		printf("PASS : 2 treasures found in hand\n");
	}
	//Check: hand does not contain Adventurer
	j = 0;
	k = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if (testGame.hand[player][i] == adventurer) {
			printf("FAIL : Adventurer found in hand at position %d\n", i);
			j = 1;
			k = 1;
		}
		else if ((i == (testGame.handCount[player]-1)) && (j != 1)) {
			printf("PASS : Adventurer NOT found in hand\n");
			k = 1;
		}
	}
	if (k != 1) {
		printf("FAIL : hand search for Adventure failed.\n");
	}
	//Check: function return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}

	//2 Treasure in Deck
	printf("*** Test %d ***\n", ++testNum);
	printf("Starting Conditions: mixed two cards in deck are treasure cards\n");
	//Test Prep
	player = 0;
	handPos = 0;
	testGame.whoseTurn = player;
	testGame.deckCount[player] = 4;
	testGame.deck[player][0] = copper;
	testGame.deck[player][1] = gardens;
	testGame.deck[player][2] = gold;
	testGame.deck[player][3] = feast;
	testGame.handCount[player] = 1;
	testGame.hand[player][0] = adventurer;
	testGame.discardCount[player] = 0;
	testGame.playedCardCount = 0;
	testGame.playedCards[0] = -1;
	//cardEffect() call
	fxnRtn = cardEffect(adventurer, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: deck count = 0
	if (testGame.deckCount[player] == 0) {
		printf("PASS : Deck Count correct after card played\n");
	}
	else {
		printf("FAIL : Deck Count incorrect after card played (should be 0, value is %d)\n", testGame.deckCount[player]);
	}
	//Check: hand count = 2
	if (testGame.handCount[player] == 2) {
		printf("PASS : Hand Count correct after card played\n");
	}
	else {
		printf("FAIL : Hand Count incorrect after card played (should be 2, value is %d)\n", testGame.handCount[player]);
	}
	//Check: discard count = 2
	if (testGame.discardCount[player] == 2) {
		printf("PASS : Discard Count correct after card played\n");
	}
	else {
		printf("FAIL : Discard Count incorrect after card played (should be 2, value is %d)\n", testGame.discardCount[player]);
	}
	//Check: played card count = 1
	if (testGame.playedCardCount == 1) {
		printf("PASS : Played Card Count incremented to 1 is correct\n");
	}
	else {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 1\n", testGame.playedCardCount);
	}
	//Check: last played card is Adventurer
	if (testGame.playedCards[0] == adventurer) {
		printf("PASS : Adventurer is last card in playedCards\n");
	}
	else {
		printf("FAIL : Adventurer is NOT the last card in played Cards, value is %d\n", testGame.playedCards[0]);
	}
	//Check: hand has two treasuer cards
	j = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if ((testGame.hand[player][i] == copper) || (testGame.hand[player][i] == silver) || (testGame.hand[player][i] == gold)) {
			++j;
		}
	}
	if (j != 2) {
		printf("FAIL : Incorrect number of treasures found in hand %d, correct count is 2\n", j);
	}
	else {
		printf("PASS : 2 treasures found in hand\n");
	}
	//Check: hand does not contain Adventurer
	j = 0;
	k = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if (testGame.hand[player][i] == adventurer) {
			printf("FAIL : Adventurer found in hand at position %d\n", i);
			j = 1;
			k = 1;
		}
		else if ((i == (testGame.handCount[player]-1)) && (j != 1)) {
			printf("PASS : Adventurer NOT found in hand\n");
			k = 1;
		}
	}
	if (k != 1) {
		printf("FAIL : hand search for Adventure failed.\n");
	}
	//Check: function return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}

	//1 Treasure in Deck, 1 Treasure in Discard
	printf("*** Test %d ***\n", ++testNum);
	printf("Starting Conditions: one treasure in deck, one treasure in discard\n");
	//Test Prep
	player = 1;
	handPos = 1;
	testGame.whoseTurn = player;
	testGame.deckCount[player] = 1;
	testGame.deck[player][0] = silver;
	testGame.handCount[player] = 2;
	testGame.hand[player][0] = council_room;
	testGame.hand[player][1] = adventurer;
	testGame.discardCount[player] = 1;
	testGame.discard[player][0] = gold;
	testGame.playedCardCount = 0;
	testGame.playedCards[0] = -1;
	//cardEffect() call
	fxnRtn = cardEffect(adventurer, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: deck count = 0
	if (testGame.deckCount[player] == 0) {
		printf("PASS : Deck Count correct after card played\n");
	}
	else {
		printf("FAIL : Deck Count incorrect after card played (should be 0, value is %d)\n", testGame.deckCount[player]);
	}
	//Check: hand count = 3
	if (testGame.handCount[player] == 3) {
		printf("PASS : Hand Count correct after card played\n");
	}
	else {
		printf("FAIL : Hand Count incorrect after card played (should be 3, value is %d)\n", testGame.handCount[player]);
	}
	//Check: played card count = 1
	if (testGame.playedCardCount == 1) {
		printf("PASS : Played Card Count incremented to 1 is correct\n");
	}
	else {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 1\n", testGame.playedCardCount);
	}
	//Check: last played card is Adventurer
	if (testGame.playedCards[0] == adventurer) {
		printf("PASS : Adventurer is last card in playedCards\n");
	}
	else {
		printf("FAIL : Adventurer is NOT the last card in played Cards, value is %d\n", testGame.playedCards[0]);
	}
	//Check: hand has two treasuer cards
	j = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if ((testGame.hand[player][i] == copper) || (testGame.hand[player][i] == silver) || (testGame.hand[player][i] == gold)) {
			++j;
		}
	}
	if (j != 2) {
		printf("FAIL : Incorrect number of treasures found in hand %d, correct count is 2\n", i);
	}
	else {
		printf("PASS : 2 treasures found in hand\n");
	}
	//Check: hand does not contain Adventurer
	j = 0;
	k = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if (testGame.hand[player][i] == adventurer) {
			printf("FAIL : Adventurer found in hand at position %d\n", i);
			j = 1;
			k = 1;
		}
		else if ((i == (testGame.handCount[player]-1)) && (j != 1)) {
			printf("PASS : Adventurer NOT found in hand\n");
			k = 1;
		}
	}
	if (k != 1) {
		printf("FAIL : hand search for Adventure failed.\n");
	}
	//Check: function return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}

	//0 Treasure in Deck, 2 Treasure in Discard
	printf("*** Test %d ***\n", ++testNum);
	printf("Starting Conditions: zero treasures in deck, two treasures in discard\n");
	//Test Prep
	player = 2;
	handPos = 2;
	testGame.whoseTurn = player;
	testGame.deckCount[player] = 2;
	testGame.deck[player][0] = village;
	testGame.deck[player][1] = feast;
	testGame.handCount[player] = 3;
	testGame.hand[player][0] = council_room;
	testGame.hand[player][1] = tribute;
	testGame.hand[player][2] = adventurer;
	testGame.discardCount[player] = 2;
	testGame.discard[player][0] = gold;
	testGame.discard[player][1] = gold;
	testGame.playedCardCount = 0;
	testGame.playedCards[0] = -1;
	//cardEffect() call
	fxnRtn = cardEffect(adventurer, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: deck count = 0
	if (testGame.deckCount[player] == 0) {
		printf("PASS : Deck Count correct after card played\n");
	}
	else {
		printf("FAIL : Deck Count incorrect after card played (should be 0, value is %d)\n", testGame.deckCount[player]);
	}
	//Check: hand count = 4
	if (testGame.handCount[player] == 4) {
		printf("PASS : Hand Count correct after card played\n");
	}
	else {
		printf("FAIL : Hand Count incorrect after card played (should be 4, value is %d)\n", testGame.handCount[player]);
	}
	//Check: played card count = 1
	if (testGame.playedCardCount == 1) {
		printf("PASS : Played Card Count incremented to 1 is correct\n");
	}
	else {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 1\n", testGame.playedCardCount);
	}
	//Check: last played card is Adventurer
	if (testGame.playedCards[0] == adventurer) {
		printf("PASS : Adventurer is last card in playedCards\n");
	}
	else {
		printf("FAIL : Adventurer is NOT the last card in played Cards, value is %d\n", testGame.playedCards[0]);
	}
	//Check: hand has two treasuer cards
	j = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if ((testGame.hand[player][i] == copper) || (testGame.hand[player][i] == silver) || (testGame.hand[player][i] == gold)) {
			++j;
		}
	}
	if (j != 2) {
		printf("FAIL : Incorrect number of treasures found in hand %d, correct count is 2\n", i);
	}
	else {
		printf("PASS : 2 treasures found in hand\n");
	}
	//Check: hand does not contain Adventurer
	j = 0;
	k = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if (testGame.hand[player][i] == adventurer) {
			printf("FAIL : Adventurer found in hand at position %d\n", i);
			j = 1;
			k = 1;
		}
		else if ((i == (testGame.handCount[player]-1)) && (j != 1)) {
			printf("PASS : Adventurer NOT found in hand\n");
			k = 1;
		}
	}
	if (k != 1) {
		printf("FAIL : hand search for Adventure failed.\n");
	}
	//Check: discard count = 2
	if (testGame.discardCount[player] == 2) {
		printf("PASS : Discard Count of 2 is correct\n");
	}
	else {
		printf("FAIL : Discard Count is incorrect, value is %d, correct value is 2\n", testGame.discardCount[player]);
	}
	//Check: function return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}

	//1 Treasure in Deck, 0 Treasure in Discard
	printf("*** Test %d ***\n", ++testNum);
	printf("Starting Conditions: one treasure in deck, zero treasures in discard\n");
	//Test Prep
	player = 3;
	handPos = 0;
	testGame.whoseTurn = player;
	testGame.deckCount[player] = 5;
	testGame.deck[player][0] = village;
	testGame.deck[player][1] = silver;
	testGame.deck[player][2] = remodel;
	testGame.deck[player][3] = mine;
	testGame.deck[player][4] = gardens;
	testGame.handCount[player] = 1;
	testGame.hand[player][0] = adventurer;
	testGame.discardCount[player] = 5;
	testGame.discard[player][0] = treasure_map;
	testGame.discard[player][1] = embargo;
	testGame.discard[player][2] = smithy;
	testGame.discard[player][3] = outpost;
	testGame.discard[player][4] = steward;
	testGame.playedCardCount = 0;
	testGame.playedCards[0] = -1;
	//cardEffect() call
	fxnRtn = cardEffect(adventurer, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: deck count = 0
	if (testGame.deckCount[player] == 0) {
		printf("PASS : Deck Count correct after card played\n");
	}
	else {
		printf("FAIL : Deck Count incorrect after card played (should be 0, value is %d)\n", testGame.deckCount[player]);
	}
	//Check: hand count = 1
	if (testGame.handCount[player] == 1) {
		printf("PASS : Hand Count correct after card played\n");
	}
	else {
		printf("FAIL : Hand Count incorrect after card played (should be 1, value is %d)\n", testGame.handCount[player]);
	}
	//Check: played card count = 1
	if (testGame.playedCardCount == 1) {
		printf("PASS : Played Card Count incremented to 1 is correct\n");
	}
	else {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 1\n", testGame.playedCardCount);
	}
	//Check: last played card is Adventurer
	if (testGame.playedCards[0] == adventurer) {
		printf("PASS : Adventurer is last card in playedCards\n");
	}
	else {
		printf("FAIL : Adventurer is NOT the last card in played Cards, value is %d\n", testGame.playedCards[0]);
	}
	//Check: hand has one treasuer card
	j = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if ((testGame.hand[player][i] == copper) || (testGame.hand[player][i] == silver) || (testGame.hand[player][i] == gold)) {
			++j;
		}
	}
	if (j != 1) {
		printf("FAIL : Incorrect number of treasure cards found in hand %d, correct count is 1\n", j);
	}
	else {
		printf("PASS : 1 treasure card found in hand\n");
	}
	//Check: hand does not contain Adventurer
	j = 0;
	k = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if (testGame.hand[player][i] == adventurer) {
			printf("FAIL : Adventurer found in hand at position %d\n", i);
			j = 1;
			k = 1;
		}
		else if ((i == (testGame.handCount[player]-1)) && (j != 1)) {
			printf("PASS : Adventurer NOT found in hand\n");
			k = 1;
		}
	}
	if (k != 1) {
		printf("FAIL : hand search for Adventure failed.\n");
	}
	//Check: discard count = 9
	if (testGame.discardCount[player] == 9) {
		printf("PASS : Discard Count of 9 is correct\n");
	}
	else {
		printf("FAIL : Discard Count is incorrect, value is %d, correct value is 9\n", testGame.discardCount[player]);
	}
	//Check: function return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}

	//0 Treasure in Deck, 1 Treasure in Discard
	printf("*** Test %d ***\n", ++testNum);
	printf("Starting Conditions: zero treasures in deck, one treasures in discard\n");
	//Test Prep
	player = 3;
	handPos = 2;
	testGame.whoseTurn = player;
	testGame.deckCount[player] = 5;
	testGame.deck[player][0] = village;
	testGame.deck[player][1] = feast;
	testGame.deck[player][2] = remodel;
	testGame.deck[player][3] = mine;
	testGame.deck[player][4] = gardens;
	testGame.handCount[player] = 3;
	testGame.hand[player][0] = council_room;
	testGame.hand[player][1] = tribute;
	testGame.hand[player][2] = adventurer;
	testGame.discardCount[player] = 5;
	testGame.discard[player][0] = copper;
	testGame.discard[player][1] = embargo;
	testGame.discard[player][2] = smithy;
	testGame.discard[player][3] = outpost;
	testGame.discard[player][4] = steward;
	testGame.playedCardCount = 0;
	testGame.playedCards[0] = -1;
	//cardEffect() call
	fxnRtn = cardEffect(adventurer, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: deck count = 0
	if (testGame.deckCount[player] == 0) {
		printf("PASS : Deck Count correct after card played\n");
	}
	else {
		printf("FAIL : Deck Count incorrect after card played (should be 0, value is %d)\n", testGame.deckCount[player]);
	}
	//Check: hand count = 3
	if (testGame.handCount[player] == 3) {
		printf("PASS : Hand Count correct after card played\n");
	}
	else {
		printf("FAIL : Hand Count incorrect after card played (should be 3, value is %d)\n", testGame.handCount[player]);
	}
	//Check: played card count = 1
	if (testGame.playedCardCount == 1) {
		printf("PASS : Played Card Count incremented to 1 is correct\n");
	}
	else {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 1\n", testGame.playedCardCount);
	}
	//Check: last played card is Adventurer
	if (testGame.playedCards[0] == adventurer) {
		printf("PASS : Adventurer is last card in playedCards\n");
	}
	else {
		printf("FAIL : Adventurer is NOT the last card in played Cards, value is %d\n", testGame.playedCards[0]);
	}
	//Check: hand has one treasuer card
	j = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if ((testGame.hand[player][i] == copper) || (testGame.hand[player][i] == silver) || (testGame.hand[player][i] == gold)) {
			++j;
		}
	}
	if (j != 1) {
		printf("FAIL : Incorrect number of treasure cards found in hand %d, correct count is 1\n", i);
	}
	else {
		printf("PASS : 1 treasure card found in hand\n");
	}
	//Check: hand does not contain Adventurer
	j = 0;
	k = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if (testGame.hand[player][i] == adventurer) {
			printf("FAIL : Adventurer found in hand at position %d\n", i);
			j = 1;
			k = 1;
		}
		else if ((i == (testGame.handCount[player]-1)) && (j != 1)) {
			printf("PASS : Adventurer NOT found in hand\n");
			k = 1;
		}
	}
	if (k != 1) {
		printf("FAIL : hand search for Adventure failed.\n");
	}
	//Check: discard count = 9
	if (testGame.discardCount[player] == 9) {
		printf("PASS : Discard Count of 9 is correct\n");
	}
	else {
		printf("FAIL : Discard Count is incorrect, value is %d, correct value is 9\n", testGame.discardCount[player]);
	}
	//Check: function return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}

	//0 Treasure in Deck, 0 Treasure in Discard
	printf("*** Test %d ***\n", ++testNum);
	printf("Starting Conditions: zero treasures in deck, zero treasures in discard\n");
	//Test Prep
	player = 3;
	handPos = 0;
	testGame.whoseTurn = player;
	testGame.deckCount[player] = 1;
	testGame.deck[player][0] = village;
	testGame.handCount[player] = 1;
	testGame.hand[player][0] = adventurer;
	testGame.discardCount[player] = 1;
	testGame.discard[player][0] = sea_hag;
	testGame.playedCardCount = 0;
	testGame.playedCards[0] = -1;
	//cardEffect() call
	fxnRtn = cardEffect(adventurer, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: deck count = 0
	if (testGame.deckCount[player] == 0) {
		printf("PASS : Deck Count correct after card played\n");
	}
	else {
		printf("FAIL : Deck Count incorrect after card played (should be 0, value is %d)\n", testGame.deckCount[player]);
	}
	//Check: hand count = 3
	if (testGame.handCount[player] == 0) {
		printf("PASS : Hand Count correct after card played\n");
	}
	else {
		printf("FAIL : Hand Count incorrect after card played (should be 0, value is %d)\n", testGame.handCount[player]);
	}
	//Check: played card count = 1
	if (testGame.playedCardCount == 1) {
		printf("PASS : Played Card Count incremented to 1 is correct\n");
	}
	else {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 1\n", testGame.playedCardCount);
	}
	//Check: last played card is Adventurer
	if (testGame.playedCards[0] == adventurer) {
		printf("PASS : Adventurer is last card in playedCards\n");
	}
	else {
		printf("FAIL : Adventurer is NOT the last card in played Cards, value is %d\n", testGame.playedCards[0]);
	}
	//Check: hand has zero treasuer cards
	j = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if ((testGame.hand[player][i] == copper) || (testGame.hand[player][i] == silver) || (testGame.hand[player][i] == gold)) {
			++j;
		}
	}
	if (j != 0) {
		printf("FAIL : Incorrect number of treasure cards found in hand %d, correct count is 0\n", i);
	}
	else {
		printf("PASS : 0 treasure cards found in hand\n");
	}
	//Check: hand does not contain Adventurer
	j = 0;
	k = 0;
	for (i = 0; i < testGame.handCount[player]; ++i) {
		if (testGame.hand[player][i] == adventurer) {
			printf("FAIL : Adventurer found in hand at position %d\n", i);
			j = 1;
			k = 1;
		}
		else if ((i == (testGame.handCount[player] - 1)) && (j != 1)) {
			printf("PASS : Adventurer NOT found in hand\n");
			k = 1;
		}
	}
	if (k != 1) {
		printf("FAIL : hand search for Adventure failed.\n");
	}
	//Check: discard count = 2
	if (testGame.discardCount[player] == 2) {
		printf("PASS : Discard Count of 2 is correct\n");
	}
	else {
		printf("FAIL : Discard Count is incorrect, value is %d, correct value is 2\n", testGame.discardCount[player]);
	}
	//Check: function return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}

	printf("End Card Test - Adventurer\n\n");

	return 0;
}



//int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
//int cardEffectAdventurer(struct gameState *state, int drawntreasure, int currentPlayer, int *temphand, int cardDrawn, int z)
