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
	int choice1, choice2, choice;
	int currentPlayer = 1;
	int handPos = 1;

	//for the random values
	srand(time(NULL));

	int i;
	for (i = 0; i < MAX_RUNS; i++)
	{

		//initalize the game with set values
		initializeGame(numPlayer, k, seed, &G);

		//randomly select choice1 or choice2
		choice = rand() % 2;
		
		//randomly select player
		currentPlayer = rand() % 2;

		//change the spot in the cards where the one selected will be
		handPos = rand() % 5;

		//if statements switch between the two different options
		if(choice == 0)
		{
			choice1 = 0;
			choice2 = 1;
		}
		else 
		{
			choice1 = 1;
			choice2 = 0;
		}
	
		caseMinion(&G, choice1, choice2, handPos, currentPlayer);

	}

	return 0;
}
												
																	




















