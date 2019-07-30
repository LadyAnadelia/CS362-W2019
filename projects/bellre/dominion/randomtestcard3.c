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
	struct gameState G, testG;
	
	//values to be randomized
	int player, nextPlayer, currentPlayer;
	int deckCT, discardCT;


	//to test and sewe what values proved true
	int passed;
	int passedCount = 0;
	int deckFail = 0;		
	int discardFail = 0;
	



	//for the random values
	srand(time(NULL));

	int i;
	for (i = 0; i < MAX_RUNS; i++)
	{
		passed = 1;
		//initalize the game with set values
		initializeGame(numPlayer, k, seed, &G);

		//to randomize which player will be which
		player = rand() % 2;

		if (player == 1)
		{
			currentPlayer = 1;
			nextPlayer = 0;
		}
		else 
		{
			currentPlayer = 0;
			nextPlayer = 1;
		}
		
		//randomize the values
		deckCT = rand() % 5 - 1 ;
		discardCT = rand() % 5  - 1;

		G.discardCount[nextPlayer] = discardCT;
		G.deckCount[nextPlayer] = deckCT;

		memcpy(&testG, &G, sizeof(struct gameState));
		caseTribute(&G, currentPlayer, nextPlayer);

		//loop though and check values of first if-statment
		if((G.discardCount[nextPlayer] + G.deckCount[nextPlayer]) <= 1)
		{
			if(G.deckCount[nextPlayer] > 0)
			{
				if((testG.deckCount[nextPlayer] - 1) != G.deckCount[nextPlayer]);
				{
					printf("Incorrect deck Count for next Player\n");		
					deckFail++;
					passed = 0;
				}
			}
			else if(G.discardCount[nextPlayer] > 0)
			{				
				if((testG.discardCount[nextPlayer] -1) != G.deckCount[nextPlayer]);
				{
					printf("Incorrect discardCount for next Player\n");	
					discardFail++;
					passed = 0;
				}
			}
		}
		else
		{



		}






		if(passed == 1)
			passedCount++;

	}

	printf("\n%d Tests Passed!\t", passedCount);



	if(passedCount == MAX_RUNS)
		printf("All Test Pass for Tribute Card!!!\n\n");
	else
		printf("There are errors in the code!!!\n\n");

	return 0;
}























