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

#define MAX_RUNS 5000000

int main()
{
	//have control over the gamestate values
	int seed = 2000;
	int numPlayer = 2;
	int k[10] = {adventurer, tribute, estate, gardens, village, embargo, minion, mine, baron, smithy};
	struct gameState G, testG;
	

	//values to be randomized
	int choice1 = 0;
	int currentPlayer = 0;
	int handCT = 0;
	int supplyCT = 0; //estate card supply count

										
	//to test and see what values proved true
	int passed;
	int failureBuy = 0, failureCoin = 0, failureDiscard = 0, failureHand = 0;
	int passedCount = 0;
                                                                                	
	//for the random values
	srand(time(NULL));

	int i;
	for (i = 0; i < MAX_RUNS; i++)
	{

		//initalize the game with set values
		initializeGame(numPlayer, k, seed, &G);
		

		//make a copy of the game 
		memcpy(&testG, &G, sizeof(struct gameState));

		//random card could be estate card
		choice1 = rand() % (26 + 0);


		//random number of estate cards in supply
		supplyCT = rand() % (8);

		G.supplyCount[estate] = supplyCT;

		//current player either 0 or 1
		currentPlayer = rand() % 2;

		//change the hand count
		handCT = rand() % (MAX_DECK);
		
		G.handCount[currentPlayer] = handCT;

		execute_baron(&G, choice1, currentPlayer);
	
										
		//reset to see what values proved true
		passed = 1;
			

		int pos;
		int cardSpot = 0;
		for(pos = 0; pos < G.handCount[currentPlayer]; pos++)
		{
			if(G.hand[currentPlayer][pos] == estate)
				cardSpot = 1; //Card is found
		}



		if(choice1 > 0)
		{
			//coin failure
			if((testG.coins + 4) != G.coins && cardSpot == 1)
			{
				printf("Incorrect number of coins added\n");
				failureCoin++;
				passed = 0;
			}	
		
			//number of buys failure
			if((testG.numBuys + 1) != G.numBuys)
			{
				printf("Incorrect number of buys added\n");
				failureBuy++;
				passed = 0;
			}
			//discard Count failure
			if((testG.discardCount[currentPlayer] + 1) != G.discardCount[currentPlayer] && cardSpot == 1)
			{
				printf("Incorrect number of cards Discarded\n");
				failureDiscard++;
				passed = 0;	
			}
			//handCount failure
			if((G.handCount[currentPlayer] != -1) && cardSpot == 1)
			{
				printf("Incorrect number of cards added to hand\n");
				failureHand++;
				passed = 0;
			}
		}

		if(passed == 1)
		{
			passedCount++;
		}			

	}
	

	printf("\n%d Tests Passed!\t", passedCount);
	printf("%d buys failed, ", failureBuy);
	printf("%d coins count failed, ", failureCoin);
	printf("%d discard count failed, ", failureDiscard);
	printf("and %d hand count failied!\n", failureHand);

	if(passedCount == MAX_RUNS)
		printf("All Tests Pass for Baron Card!!!\n\n");

	return 0;
}
