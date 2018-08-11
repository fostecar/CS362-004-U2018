/* -----------------------------------------------------------------------
* Carissa Foster - CS362 - Assignment-3
* This is a unit test implemented for the Cutpurse card refactored function.
* Updated makefile to include:
*
* testCutpurse: cardtest3.c dominion.o rngs.o
* gcc -o testCutpurse -g cardtest3.c dominion.o rngs.o $(CFLAGS)
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
	int handPos = -5;
	int i = -5;
	int j = -5;
	int fxnRtn = -5;
	int choice1 = -5;
	int choice2 = -5;
	int choice3 = -5;
	int bonus = -5;
	int playerX = -5;
	int playerY = -5;
	int playerZ = -5;

	testGame.numPlayers = 4;
	player = 1;
	playerX = 0;
	playerY = 2;
	playerZ = 3;
	handPos = 0;
	testGame.whoseTurn = player;
	testGame.handCount[player] = 5;
	testGame.hand[player][0] = cutpurse;
	testGame.hand[player][1] = copper;
	testGame.hand[player][2] = tribute;
	testGame.hand[player][3] = silver;
	testGame.hand[player][4] = gold;
	testGame.playedCardCount = 0;
	testGame.playedCards[0] = -1;
	testGame.handCount[playerX] = 5;
	testGame.hand[playerX][0] = minion;
	testGame.hand[playerX][1] = copper;
	testGame.hand[playerX][2] = treasure_map;
	testGame.hand[playerX][3] = copper;
	testGame.hand[playerX][4] = sea_hag;
	testGame.handCount[playerY] = 5;
	testGame.hand[playerY][0] = village;
	testGame.hand[playerY][1] = feast;
	testGame.hand[playerY][2] = gold;
	testGame.hand[playerY][3] = silver;
	testGame.hand[playerY][4] = outpost;
	testGame.handCount[playerZ] = 5;
	testGame.hand[playerZ][0] = salvager;
	testGame.hand[playerZ][1] = mine;
	testGame.hand[playerZ][2] = gardens;
	testGame.hand[playerZ][3] = smithy;
	testGame.hand[playerZ][4] = ambassador;

	printf("\nBegin Card Test - Cutpurse\n");
	//cardEffect() call
	fxnRtn = cardEffect(cutpurse, choice1, choice2, choice3, &testGame, handPos, &bonus);
	//Check: Correct coin count after the function call
	if (testGame.coins == 8) {
		printf("PASS : current player has 8 coins to spend is correct (hand coin total + 2 bonus)\n");
	}
	else {
		printf("FAIL: current player has %d coins, correct total for coins is 8\n", testGame.coins);
	}
	//Check: played card count = 1
	if (testGame.playedCardCount == 1) {
		printf("PASS : Played Card Count incremented to 1 is correct\n");
	}
	else {
		printf("FAIL : Played Card Count is incorrect, value is %d, correct value is 1\n", testGame.playedCardCount);
	}
	//Check: last played card is Cutpurse
	if (testGame.playedCards[0] == cutpurse) {
		printf("PASS : Cutpurse is last card in playedCards\n");
	}
	else {
		printf("FAIL : Cutpurse is NOT the last card in played Cards, value is %d\n", testGame.playedCards[0]);
	}

	//Other PlayerX (0) has coppers
	//Check PlayerX hand Count
	if (testGame.handCount[playerX] == 4) {
		printf("PASS : Hand count for player%d is 4\n", playerX);
	}
	else {
		printf("FAIL : Hand count for player%d is %d, correct value is 4\n", playerX, testGame.handCount[playerX]);
	}
	//Check PlayerX has two coppers in their hand
	j = 0;
	for (i = 0; i < testGame.handCount[playerX]; ++i) {
		if (testGame.hand[playerX][i] == copper) {
			++j;
		}
	}
	if (j != 1) {
		printf("FAIL : Incorrect number of coppers found in player%d's hand, found %d, correct count is 1\n", playerX, j);
	}
	else {
		printf("PASS : 1 copper found in player%d's hand\n", playerX);
	}

	//Other Player (2) does NOT have a copper, has other coins
	//Check PlayerY hand Count
	if (testGame.handCount[playerY] == 5) {
		printf("PASS : Hand count for player%d is 5\n", playerY);
	}
	else {
		printf("FAIL : Hand count for player%d is %d, correct value is 5\n", playerY, testGame.handCount[playerY]);
	}
	//Check PlayerY has no copper in their hand
	j = 0;
	for (i = 0; i < testGame.handCount[playerY]; ++i) {
		if (testGame.hand[playerY][i] == copper) {
			++j;
		}
	}
	if (j != 0) {
		printf("FAIL : Incorrect number of coppers found in player%d's hand, found %d, correct count is 0\n", playerY, j);
	}
	else {
		printf("PASS : 0 coppers found in player%d's hand\n", playerY);
	}

	//Other Player (3) does NOT have a copper, does NOT have other coins
	//Check PlayerZ hand Count
	if (testGame.handCount[playerZ] == 5) {
		printf("PASS : Hand count for player%d is 5\n", playerZ);
	}
	else {
		printf("FAIL : Hand count for player%d is %d, correct value is 5\n", playerZ, testGame.handCount[playerZ]);
	}
	//Check PlayerZ has no copper in their hand
	j = 0;
	for (i = 0; i < testGame.handCount[playerZ]; ++i) {
		if (testGame.hand[playerZ][i] == copper) {
			++j;
		}
	}
	if (j != 0) {
		printf("FAIL : Incorrect number of coppers found in player%d's hand, found %d, correct count is 0\n", playerZ, j);
	}
	else {
		printf("PASS : 0 coppers found in player%d's hand\n", playerZ);
	}
	//Check: function return = 0
	if (fxnRtn == 0) {
		printf("PASS : function return of 0 is correct\n");
	}
	else {
		printf("FAIL: function return of %d is NOT correct, correct return is 0\n", fxnRtn);
	}

	printf("End Card Test - Cutpurse\n\n");

	return 0;

}

//int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
//int cardEffectCutpurse(struct gameState *state, int currentPlayer, int handPos, int i, int j, int k)