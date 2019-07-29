/*
 * Name: Rebecca Bell
 * Description: random testing values for the dominion.c baron card
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

#define MAX_RUNS 500000

int main()
{
	//have control over the gamestate values
	int seed = 2000;
	int numPlayer = 2;
	int k[10] = {adventurer, tribute, estate, gardens, village, embargo, minion, mine, baron, smithy};
	struct gameState G;
	

	//values to be randomized
	int choice1 = 0;
	int currentPlayer = 0;
	int handCT = 0;
	int supplyCT = 0; //estate card supply count


	//for the random values
	srand(time(NULL));

	int i;
	for (i = 0; i < MAX_RUNS; i++)
	{

		//initalize the game with set values
		initializeGame(numPlayer, k, seed, &G);

		//random card could be estate card
		choice1 = rand() % (26 + 0);


		//random number of estate cards in supply
		supplyCT = rand() % (8);

		G.supplyCount[estate] = supplyCT;

		//current player either 0 or 1
		currentPlayer = rand() % 2;

		//change the hand count
		handCT = rand() % (MAX_DECK);
		
		G.handCount[0] = handCT;

		caseBaron(&G, choice1, currentPlayer);
	

	}

	return 0;
}
												
