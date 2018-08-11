/* -----------------------------------------------------------------------
* Carissa Foster - CS362 - Assignment-3
* This is a unit test implemented for the getCost() function.
* Updated makefile to include:
*
* testGetCost: unittest1.c dominion.o rngs.o
* gcc -o testGetCost -g unittest1.c dominion.o rngs.o $(CFLAGS)
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

	int cost = -5;
	int i = -5;
	int outOfBounds = -5;
	int max = 1000;

	printf("\nBegin Test - dominion.c, getCost() - unittest1.c\n");


	/*Cycle through card numbers and compare to known cost.*/
	for (i = 0; i < 27; ++i) {
		cost = getCost(i);

		if ((i == curse) && (cost == 0)) {
			printf("PASS : card %d, cost %d is correct\n", curse, cost);
		}
		else if ((i == estate) && (cost == 2)) {
			printf("PASS : card %d, cost %d is correct\n", estate, cost);
		}
		else if ((i == duchy) && (cost == 5)) {
			printf("PASS : card %d, cost %d is correct\n", duchy, cost);
		}
		else if ((i == province) && (cost == 8)) {
			printf("PASS : card %d, cost %d is correct\n", province, cost);
		}
		else if ((i == copper) && (cost == 0)) {
			printf("PASS : card %d, cost %d is correct\n", copper, cost);
		}
		else if ((i == silver) && (cost == 3)) {
			printf("PASS : card %d, cost %d is correct\n", silver, cost);
		}
		else if ((i == gold) && (cost == 6)) {
			printf("PASS : card %d, cost %d is correct\n", gold, cost);
		}
		else if ((i == adventurer) && (cost == 6)) {
			printf("PASS : card %d, cost %d is correct\n", adventurer, cost);
		}
		else if ((i == council_room) && (cost == 5)) {
			printf("PASS : card %d, cost %d is correct\n", council_room, cost);
		}
		else if ((i == feast) && (cost == 4)) {
			printf("PASS : card %d, cost %d is correct\n", feast, cost);
		}
		else if ((i == gardens) && (cost == 4)) {
			printf("PASS : card %d, cost %d is correct\n", gardens, cost);
		}
		else if ((i == mine) && (cost == 5)) {
			printf("PASS : card %d, cost %d is correct\n", mine, cost);
		}
		else if ((i == remodel) && (cost == 4)) {
			printf("PASS : card %d, cost %d is correct\n", remodel, cost);
		}
		else if ((i == smithy) && (cost == 4)) {
			printf("PASS : card %d, cost %d is correct\n", smithy, cost);
		}
		else if ((i == village) && (cost == 3)) {
			printf("PASS : card %d, cost %d is correct\n", village, cost);
		}
		else if ((i == baron) && (cost == 4)) {
			printf("PASS : card %d, cost %d is correct\n", baron, cost);
		}
		else if ((i == great_hall) && (cost == 3)) {
			printf("PASS : card %d, cost %d is correct\n", great_hall, cost);
		}
		else if ((i == minion) && (cost == 5)) {
			printf("PASS : card %d, cost %d is correct\n", minion, cost);
		}
		else if ((i == steward) && (cost == 3)) {
			printf("PASS : card %d, cost %d is correct\n", steward, cost);
		}
		else if ((i == tribute) && (cost == 5)) {
			printf("PASS : card %d, cost %d is correct\n", tribute, cost);
		}
		else if ((i == ambassador) && (cost == 3)) {
			printf("PASS : card %d, cost %d is correct\n", ambassador, cost);
		}
		else if ((i == cutpurse) && (cost == 4)) {
			printf("PASS : card %d, cost %d is correct\n", cutpurse, cost);
		}
		else if ((i == embargo) && (cost == 2)) {
			printf("PASS : card %d, cost %d is correct\n", embargo, cost);
		}
		else if ((i == outpost) && (cost == 5)) {
			printf("PASS : card %d, cost %d is correct\n", outpost, cost);
		}
		else if ((i == salvager) && (cost == 4)) {
			printf("PASS : card %d, cost %d is correct\n", salvager, cost);
		}
		else if ((i == sea_hag) && (cost == 4)) {
			printf("PASS : card %d, cost %d is correct\n", sea_hag, cost);
		}
		else if ((i == treasure_map) && (cost == 4)) {
			printf("PASS : card %d, cost %d is correct\n", treasure_map, cost);
		}
		else {
			printf("FAIL : card %d, cost %d is NOT correct\n", i, cost);
		}
	}

	/*Test out of bounds card values. Return value expected to be -1.*/
	srand(time(0));

	for (i = 0; i < 4; ++i) {
		if (i == 0) { //one beyond upper limit
			outOfBounds = 27;
		}
		else if (i == 1) { //one beyond lower limit
			outOfBounds = -1;
		}
		else if (i == 2) { //random beyond upper limit
			outOfBounds = rand() % ((max + 1) - 28) + 28;
		}
		else if (i == 3) { // random beyond lower limit
			outOfBounds = rand() % ((max + 1) - 2) + 2;
			outOfBounds = outOfBounds * -1;
		}
		
		cost = getCost(outOfBounds);

		if (cost == -1) {
			printf("PASS : input %d, return %d is correct\n", outOfBounds, cost);
		}
		else {
			printf("FAIL : input %d, return %d is NOT correct\n", outOfBounds, cost);
		}
	}

	printf("End Test - dominion.c, getCost() - unittest1.c\n\n");

	return 0;
}