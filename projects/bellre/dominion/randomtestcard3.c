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

#define MAX_RUNS 1000

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
	int deckFail2 = 0;    
	int tribFail = 0;


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

			//printf("Path 1: ");
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

			//printf("Path 2: ");
			if(G.deckCount[nextPlayer] == 0)
			{
				testG.deckCount[nextPlayer]++;
				testG.discardCount[nextPlayer]--;
			}
			
		}

		drawCard(currentPlayer, &testG);
		drawCard(currentPlayer, &testG);
		

		//printf("DeckCount = %d, expected = %d\n", G.deckCount[nextPlayer], testG.deckCount[nextPlayer]);
		if((testG.coins + 2) == G.coins)
			passed = 1;
		else if((testG.numActions + 2) == G.numActions)
			passed = 1;
		else if((G.deckCount[nextPlayer]) != (testG.deckCount[nextPlayer]))
		{
			printf("Incorect deckCount for nextPlayer (2)\n");
			deckFail2++;
			passed = 0;
		}
		else
		{
			printf("The tribute reveal card failed\n");
			tribFail++;
			passed = 0;
		}

		

		if(passed == 1)
			passedCount++;

	}

	printf("\n%d Tests Passed!\t", passedCount);
	printf("%d deckCount1 for Next Player Failed, ", deckFail);
	printf("%d discardCount1 for NextPlayer Failed\n", discardFail);
	printf("%d deckCount2 for Next Player Failed, ", deckFail2);
	printf("%d tribute reveal card failed\n", tribFail);


	if(passedCount == MAX_RUNS)
		printf("All Test Pass for Tribute Card!!!\n\n");
	else
		printf("There are errors in the code!!!\n\n");

	return 0;
}























