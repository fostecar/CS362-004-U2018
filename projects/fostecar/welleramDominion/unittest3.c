/* -----------------------------------------------------------------------
* Carissa Foster - CS362 - Assignment-3
* This is a unit test implemented for the kingdomCards() function.
* Updated makefile to include:
*
* testKingdomCards: unittest3.c dominion.o rngs.o
* gcc -o testKingdomCards -g unittest3.c dominion.o rngs.o $(CFLAGS)
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

	int testArray1[10];
	int *testArray2;
	int i = -5;
	int card = -5;

	srand(time(0));

	printf("\nBegin Test - dominion.c, kingdomCards() - unittest3.c\n");


	/*Real Card Values*/
	for (i = 0; i < 10; ++i) {
		card = rand() % 27;
		testArray1[i] = card;
	}

	testArray2 = kingdomCards(testArray1[0], testArray1[1], testArray1[2], testArray1[3], testArray1[4], testArray1[5], testArray1[6], testArray1[7], testArray1[8], testArray1[9]);

	for (i = 0; i < 10; ++i) {
		if (testArray1[i] != *(testArray2 + i)) {
			printf("FAIL : Returned Array Incorrect Pointer - Real Card Values, array position %d\n", i);
		}
		else if (i == 9) {
			printf("PASS : Returned Array Correct Pointer - Real Card Values\n");
		}
	}
	
	/*Other Random Card Values*/
	for (i = 0; i < 10; ++i) {
		card = rand() % 5000 - 2500;
		testArray1[i] = card;
	}

	testArray2 = kingdomCards(testArray1[0], testArray1[1], testArray1[2], testArray1[3], testArray1[4], testArray1[5], testArray1[6], testArray1[7], testArray1[8], testArray1[9]);

	for (i = 0; i < 10; ++i) {
		if (testArray1[i] != *(testArray2 + i)) {
			printf("FAIL : Returned Array Pointer Incorrect - Other Random Values, array position %d\n", i);
		}
		else if (i == 9) {
			printf("PASS : Returned Array Correct Pointer - Other Random Values\n");
		}
	}

	printf("End Test - dominion.c, kingdomCards() - unittest3.c\n\n");

	return 0;
}

/*
int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,
int k8, int k9, int k10) {
int* k = malloc(10 * sizeof(int));
k[0] = k1;
k[1] = k2;
k[2] = k3;
k[3] = k4;
k[4] = k5;
k[5] = k6;
k[6] = k7;
k[7] = k8;
k[8] = k9;
k[9] = k10;
return k;
}
*/