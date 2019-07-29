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
	int player, nextPlayer, currentPlayer;
	int deckCT, discardCT;


	//for the random values
	srand(time(NULL));

	int i;
	for (i = 0; i < MAX_RUNS; i++)
	{

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


		caseTribute(&G, currentPlayer, nextPlayer);


	}
	return 0;
}























