/* -----------------------------------------------------------------------
* Carissa Foster - CS362 - Assignment-3
* This is a unit test implemented for the Council_Room card refactored function.
* Updated makefile to include:
*
* testCouncilRoom: cardtest4.c dominion.o rngs.o
* gcc -o testCouncilRoom -g cardtest4.c dominion.o rngs.o $(CFLAGS)
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
	int player = -5;
	int playerX = -5;
	int playerY = -5;
	int handPos = -5;
	int i = -5;
	int j = -5;
	int fxnRtn = -5;
	int choice1 = -5;
	int choice2 = -5;
	int choice3 = -5;
	int bonus = -5;

	printf("\nBegin Card Test - Council Room\n");

	//Both players have enough cards to draw
	printf("TEST 1 - Current player has > 4 cards in deck/discard, other players had > 1 card\n");
	player = 0;
	playerX = 1;
	playerY = 2;
	handPos = 0;
	testGame.whoseTurn = player;
	testGame.numPlayers = 3;
	testGame.numBuys = 1;
	testGame.deckCount[player] = 3;
	testGame.deck[player][0] = copper;
	testGame.deck[player][1] = feast;
	testGame.deck[player][2] = gardens;
	testGame.handCount[player] = 1;
	testGame.hand[player][0] = council_room;
	testGame.discardCount[player] = 1;
	testGame.discard[player][0] = treasure_map;
	testGame.playedCardCount = 0;
	testGame.playedCards[0] = -1;
	testGame.handCount[playerX] = 0;
	testGame.hand[playerX][0] = -1;
	testGame.deckCount[playerX] = 1;
	testGame.deck[playerX][0] = embargo;
	testGame.handCount[playerY] = 0;
	testGame.hand[playerY][0] = -1;
	testGame.deckCount[playerY] = 0;
	testGame.discardCount[playerY] = 1;
	testGame.discard[playerY][0] = salvager;
	//cardEffect() call
	fxnRtn = cardEffect(council_room, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: Curr player gained 4 hand cards
	if (testGame.handCount[player] == 4) {
		printf("PASS : Hand Count correct after card played\n");
	}
	else {
		printf("FAIL : Hand Count incorrect after card played (should be 4, value is %d)\n", testGame.handCount[player]);
	}
	//Check: hand does not contain Council_Room
	j = 0;
	for (i = 0; i < 4; ++i) {
		if (testGame.hand[player][i] == council_room) {
			printf("FAIL : Council_Room found in hand at position %d\n", i);
			j = 1;
		}
		else if ((i == 3) && (j != 1)) {
			printf("PASS : Council_Room NOT found in hand\n");
		}
	}
	//Check: Curr player deck = 0
	if (testGame.deckCount[player] == 0) {
		printf("PASS : Deck Count correct after card played\n");
	}
	else {
		printf("FAIL : Deck Count incorrect after card played (should be 0, value is %d)\n", testGame.deckCount[player]);
	}
	//Check: Curr player discard = 0
	if (testGame.discardCount[player] == 0) {
		printf("PASS : Discard Count correct after card played\n");
	}
	else {
		printf("FAIL : Discard Count incorrect after card played (should be 0, value is %d)\n", testGame.discardCount[player]);
	}
	//Check: numBuys = 2
	if (testGame.numBuys == 2) {
		printf("PASS : Current player number of buys is correct after card played\n");
	}
	else {
		printf("FAIL : Current player number of buys is incorrect after card played (should be 2, value is %d)\n", testGame.numBuys);
	}
	//Check: Curr player had discard card to played cards
	if (testGame.playedCardCount != 1) {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 1\n", testGame.playedCardCount);
	}
	else if (testGame.playedCards[0] != council_room){
		printf("FAIL : Played Card is incorrect, value is %d, correct value is %d\n", testGame.playedCardCount, council_room);
	}
	else {
		printf("PASS : Played Card and Count is correct\n");
	}
	//Check: PlayerX has 1 card in hand
	if (testGame.handCount[playerX] == 1) {
		printf("PASS : Player%d Hand Count correct after card played\n", playerX);
	}
	else {
		printf("FAIL : Player%d Hand Count incorrect after card played (should be 1, value is %d)\n", playerX, testGame.handCount[playerX]);
	}
	//Check: PlayerY has 1 card in hand
	if (testGame.handCount[playerY] == 1) {
		printf("PASS : Player%d Hand Count correct after card played\n", playerY);
	}
	else {
		printf("FAIL : Player%d Hand Count incorrect after card played (should be 1, value is %d)\n", playerY, testGame.handCount[playerY]);
	}
	//Check: return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}

	//Neither player has enough cards to draw
	printf("TEST 2 - Current player has 2 cards in deck/discard, other player has 0 cards\n");
	testGame.whoseTurn = player;
	testGame.numPlayers = 2;
	testGame.numBuys = 3;
	testGame.deckCount[player] = 1;
	testGame.deck[player][0] = copper;
	testGame.handCount[player] = 1;
	testGame.hand[player][0] = council_room;
	testGame.discardCount[player] = 1;
	testGame.discard[player][0] = treasure_map;
	testGame.playedCardCount = 0;
	testGame.playedCards[0] = -1;
	testGame.handCount[playerX] = 0;
	testGame.hand[playerX][0] = -1;
	testGame.deckCount[playerX] = 0;
	testGame.deck[playerX][0] = -1;
	testGame.discardCount[playerX] = 0;
	testGame.discard[playerX][0] = -1;
	//cardEffect() call
	fxnRtn = cardEffect(council_room, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: Curr player gained 2 hand cards
	if (testGame.handCount[player] == 2) {
		printf("PASS : Hand Count correct after card played\n");
	}
	else {
		printf("FAIL : Hand Count incorrect after card played (should be 2, value is %d)\n", testGame.handCount[player]);
	}
	//Check: hand does not contain Council_Room
	j = 0;
	for (i = 0; i < 2; ++i) {
		if (testGame.hand[player][i] == council_room) {
			printf("FAIL : Council_Room found in hand at position %d\n", i);
			j = 1;
		}
		else if ((i == 1) && (j != 1)) {
			printf("PASS : Council_Room NOT found in hand\n");
		}
	}
	//Check: Curr player deck = 0
	if (testGame.deckCount[player] == 0) {
		printf("PASS : Deck Count correct after card played\n");
	}
	else {
		printf("FAIL : Deck Count incorrect after card played (should be 0, value is %d)\n", testGame.deckCount[player]);
	}
	//Check: Curr player discard = 0
	if (testGame.discardCount[player] == 0) {
		printf("PASS : Discard Count correct after card played\n");
	}
	else {
		printf("FAIL : Discard Count incorrect after card played (should be 0, value is %d)\n", testGame.discardCount[player]);
	}
	//Check: numBuys = 4
	if (testGame.numBuys == 4) {
		printf("PASS : Current player number of buys is correct after card played\n");
	}
	else {
		printf("FAIL : Current player number of buys is incorrect after card played (should be 4, value is %d)\n", testGame.numBuys);
	}
	//Check: Curr player had discard card to played cards
	if (testGame.playedCardCount != 1) {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 1\n", testGame.playedCardCount);
	}
	else if (testGame.playedCards[0] != council_room) {
		printf("FAIL : Played Card is incorrect, value is %d, correct value is %d\n", testGame.playedCardCount, council_room);
	}
	else {
		printf("PASS : Played Card and Count is correct\n");
	}
	//Check: PlayerX has 0 cards in hand
	if (testGame.handCount[playerX] == 0) {
		printf("PASS : Player%d Hand Count correct after card played\n", playerX);
	}
	else {
		printf("FAIL : Player%d Hand Count incorrect after card played (should be 0, value is %d)\n", playerX, testGame.handCount[playerX]);
	}
	//Check: return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}

	printf("End Card Test - Council Room\n\n");

	return 0;
}