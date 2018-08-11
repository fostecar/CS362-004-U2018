/* -----------------------------------------------------------------------
* Carissa Foster - CS362 - Assignment-3
* This is a unit test implemented for the fullDeckCount() function.
* Updated makefile to include:
*
* testFullDeckCount: unittest2.c dominion.o rngs.o
* gcc -o testGetCost -g unittest2.c dominion.o rngs.o $(CFLAGS)
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
	testGame.numPlayers = MAX_PLAYERS;
	int player = -5;
	int card = -5;
	int cardPos = -5;
	int cardCount = -5;
	int cardCountArray[27];
	int i = -5;

	srand(time(0));

	/*Initialize cardCountArray*/
	card = 0;
	
	for (i = 0; i < 27; ++i) {
		cardCountArray[i] = 0;
	}

	for (i = 0; i < MAX_DECK; ++i) {
		testGame.deck[0][i] = card;
		testGame.hand[0][i] = card;
		testGame.discard[0][i] = card;
		testGame.deck[1][i] = card;
		testGame.hand[1][i] = card;
		testGame.discard[1][i] = card;
		testGame.deck[2][i] = card;
		testGame.hand[2][i] = card;
		testGame.discard[2][i] = card;
		testGame.deck[3][i] = card;
		testGame.hand[3][i] = card;
		testGame.discard[3][i] = card;

		cardCountArray[card] = cardCountArray[card] + 1;

		++card;
		if (card > 26) {
			card = 0;
		}
	}


	printf("\nBegin Test - dominion.c, fullDeckCount() - unittest2.c\n");

	/*Check various cards in the deck only*/
	card = rand() % 27;  //Select a card (0,26)
	player = 0;
	testGame.deckCount[player] = MAX_DECK;
	testGame.handCount[player] = 0;
	testGame.discardCount[player] = 0;

	cardCount = fullDeckCount(player, card, &testGame);

	if (cardCount == cardCountArray[card]) {
		printf("PASS : Deck Only, card %d, quantity %d, function return %d\n", card, cardCountArray[card], cardCount);
	}
	else {
		printf("FAIL : Deck Only, card %d, quantity %d, function return %d\n", card, cardCountArray[card], cardCount);
	}

	/*Check card in the hand only*/
	card = rand() % 27;  //Select a card (0,26)
	player = 1;
	testGame.deckCount[player] = 0;
	testGame.handCount[player] = MAX_HAND;
	testGame.discardCount[player] = 0;

	cardCount = fullDeckCount(player, card, &testGame);

	if (cardCount == cardCountArray[card]) {
		printf("PASS : Hand Only, card %d, quantity %d, function return %d\n", card, cardCountArray[card], cardCount);
	}
	else {
		printf("FAIL : Hand Only, card %d, quantity %d, function return %d\n", card, cardCountArray[card], cardCount);
	}


	/*Check card in the discard only*/
	card = rand() % 27;  //Select a card (0,26)
	player = 2;
	testGame.deckCount[player] = 0;
	testGame.handCount[player] = 0;
	testGame.discardCount[player] = MAX_DECK;

	cardCount = fullDeckCount(player, card, &testGame);

	if (cardCount == cardCountArray[card]) {
		printf("PASS : Discard Only, card %d, quantity %d, function return %d\n", card, cardCountArray[card], cardCount);
	}
	else {
		printf("FAIL : Discard Only, card %d, quantity %d, function return %d\n", card, cardCountArray[card], cardCount);
	}

	/*Check card in the deck, hand, and discard*/
	card = rand() % 27;  //Select a card (0,26)
	player = 3;
	testGame.deckCount[player] = MAX_DECK;
	testGame.handCount[player] = MAX_HAND;
	testGame.discardCount[player] = MAX_DECK;

	cardCount = fullDeckCount(player, card, &testGame);

	if (cardCount == (3 * cardCountArray[card])) {
		printf("PASS : Deck/Hand/Discard, card %d, quantity %d, function return %d\n", card, (3 * cardCountArray[card]), cardCount);
	}
	else {
		printf("FAIL : Deck/Hand/Discard, card %d, quantity %d, function return %d\n", card, (3 * cardCountArray[card]), cardCount);
	}

	/*Card NOT in deck, hand, and/or discard*/
	player = 0;
	card = rand() % 27;  //Select a card (0,26)

	for (i = card; i < 26; ++i) {
		testGame.deck[player][i] = testGame.deck[player][i + 1];
		testGame.hand[player][i] = testGame.deck[player][i + 1];
		testGame.discard[player][i] = testGame.deck[player][i + 1];
	}

	testGame.deckCount[player] = 26;
	testGame.handCount[player] = 26;
	testGame.discardCount[player] = 26;


	cardCount = fullDeckCount(player, card, &testGame);

	if (cardCount == 0) {
		printf("PASS : Card NOT in deck/hand/discard, function return %d\n", cardCount);
	}
	else {
		printf("FAIL : Card NOT in deck/hand/discard, function return %d\n", cardCount);
	}

	/*All cards*/
	player = 1;
	card = rand() % 27;  //Select a card (0,26)
	testGame.deckCount[player] = MAX_DECK;
	testGame.handCount[player] = MAX_HAND;
	testGame.discardCount[player] = MAX_DECK;
		
	for (cardPos = 0; cardPos < MAX_DECK; ++cardPos) {
		testGame.deck[player][cardPos] = card;
		testGame.hand[player][cardPos] = card;
		testGame.discard[player][cardPos] = card;
	}

	cardCount = fullDeckCount(player, card, &testGame);
	if (cardCount == ((2 * MAX_DECK) + MAX_HAND)) {
		printf("PASS : All Cards, player %d, card %d, function return %d\n", player, card, cardCount);
	}
	else {
		printf("FAIL : All Cards, player %d, card %d, function return %d\n", player, card, cardCount);
	}
	

	/*Player had zero cards*/
	player = 2;
	testGame.deckCount[player] = 0;
	testGame.handCount[player] = 0;
	testGame.discardCount[player] = 0;

	cardCount = fullDeckCount(player, card, &testGame);
	if (cardCount == 0) {
		printf("PASS : Player has zero cards, player %d, card %d, function return %d\n", player, card, cardCount);
	}
	else {
		printf("FAIL : Player has zero cards, player %d, card %d, function return %d\n", player, card, cardCount);
	}
	

	/*Invalid player*/
	card = rand() % 27;  //Select a card (0,26)
	player = 4;
	cardCount = fullDeckCount(player, card, &testGame);
	printf("Behavior Check : Invalid Player (+1), return %d\n", cardCount);

	player = -1;
	cardCount = fullDeckCount(player, card, &testGame);
	printf("Behavior Check : Invalid Player (-1), return %d\n", cardCount);

	/*Invalid card*/
	player = 2;
	card = 27;
	cardCount = fullDeckCount(player, card, &testGame);
	printf("Behavior Check : Invalid Card (+1), return %d\n", cardCount);

	card = -1;
	cardCount = fullDeckCount(player, card, &testGame);
	printf("Behavior Check : Invalid Card (-1), return %d\n", cardCount);


	printf("End Test - dominion.c, fullDeckCount() - unittest2.c\n\n");

	return 0;
}
/*
struct gameState {
	int numPlayers; //number of players
	int supplyCount[treasure_map + 1];  //this is the amount of a specific type of card given a specific number.
	int embargoTokens[treasure_map + 1];
	int outpostPlayed;
	int outpostTurn;
	int whoseTurn;
	int phase;
	int numActions; // Starts at 1 each turn 
	int coins;  // Use as you see fit! 
	int numBuys; //  Starts at 1 each turn 
	int hand[MAX_PLAYERS][MAX_HAND];
	int handCount[MAX_PLAYERS];
	int deck[MAX_PLAYERS][MAX_DECK];
	int deckCount[MAX_PLAYERS];
	int discard[MAX_PLAYERS][MAX_DECK];
	int discardCount[MAX_PLAYERS];
	int playedCards[MAX_DECK];
	int playedCardCount;
};*/