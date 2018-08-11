/* -----------------------------------------------------------------------
* Carissa Foster - CS362 - Assignment-3
* This is a unit test implemented for the handCard() function.
* Updated makefile to include:
*
* testHandCard: unittest4.c dominion.o rngs.o
* gcc -o testHandCard -g unittest4.c dominion.o rngs.o $(CFLAGS)
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
	int card = -5;
	int handPosSet = -5;
	int cardReturned = -5;

	srand(time(0));

	printf("\nBegin Test - dominion.c, handCard() - unittest4.c\n");

	/*Inrange hand position values for players 0, 1, 2, 3*/
	player = 0;
	testGame.whoseTurn = player;
	card = rand() % 27;
	handPosSet = rand() % MAX_HAND;
	testGame.hand[player][handPosSet] = card;
	cardReturned = handCard(handPosSet, &testGame);

	if (cardReturned == card) {
		printf("PASS : Player %d Random Card and Card Position, correct card returned\n", player);
	}
	else {
		printf("FAIL : Player %d Random Card and Card Position, incorrect card returned %d, correct value is %d\n", player, cardReturned, card);
	}

	player = 1;
	testGame.whoseTurn = player;
	card = rand() % 27;
	handPosSet = rand() % MAX_HAND;
	testGame.hand[player][handPosSet] = card;
	cardReturned = handCard(handPosSet, &testGame);

	if (cardReturned == card) {
		printf("PASS : Player %d Random Card and Card Position, correct card returned\n", player);
	}
	else {
		printf("FAIL : Player %d Random Card and Card Position, incorrect card returned %d, correct value is %d\n", player, cardReturned, card);
	}

	player = 2;
	testGame.whoseTurn = player;
	card = rand() % 27;
	handPosSet = rand() % MAX_HAND;
	testGame.hand[player][handPosSet] = card;
	cardReturned = handCard(handPosSet, &testGame);

	if (cardReturned == card) {
		printf("PASS : Player %d Random Card and Card Position, correct card returned\n", player);
	}
	else {
		printf("FAIL : Player %d Random Card and Card Position, incorrect card returned %d, correct value is %d\n", player, cardReturned, card);
	}

	player = 3;
	testGame.whoseTurn = player;
	card = rand() % 27;
	handPosSet = rand() % MAX_HAND;
	testGame.hand[player][handPosSet] = card;
	cardReturned = handCard(handPosSet, &testGame);

	if (cardReturned == card) {
		printf("PASS : Player %d Random Card and Card Position, correct card returned\n", player);
	}
	else {
		printf("FAIL : Player %d Random Card and Card Position, incorrect card returned %d, correct value is %d\n", player, cardReturned, card);
	}

	/*Behavior Checks - Invalid hand positions entered*/
	player = rand() % 4;
	cardReturned = handCard(-1, &testGame); 
	printf("Behavior Check : Invalid hand position (-1), return value %d, player %d\n", cardReturned, player);

	player = rand() % 4;
	cardReturned = handCard(MAX_HAND, &testGame);
	printf("Behavior Check : Invalid hand position (%d), return value %d, player %d\n", MAX_HAND, cardReturned, player);

	player = rand() % 4;
	handPosSet = rand() % 2500 + MAX_HAND;
	cardReturned = handCard(MAX_HAND, &testGame);
	printf("Behavior Check : Invalid hand position (%d), return value %d, player %d\n", handPosSet, cardReturned, player);

	player = rand() % 4;
	handPosSet = rand() % 2500;
	handPosSet = (handPosSet * -1);
	cardReturned = handCard(MAX_HAND, &testGame);
	printf("Behavior Check : Invalid hand position (%d), return value %d, player %d\n", handPosSet, cardReturned, player);


	printf("End Test - dominion.c, handCard() - unittest4.c\n\n");

	return 0;
}

/*

int handCard(int handPos, struct gameState *state) {
	int currentPlayer = whoseTurn(state);
	return state->hand[currentPlayer][handPos];
}

*/