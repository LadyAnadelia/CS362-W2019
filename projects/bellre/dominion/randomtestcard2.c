/*	MINION CARD
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

#define MAX_RUNS 100000

int main()
{
	//have control over the gamestate values
	int seed = 2000;
	int numPlayer = 2;
	int k[10] = {adventurer, tribute, estate, gardens, village, embargo, minion, mine, baron, smithy};
	struct gameState G, testG;
	

	//values to be randomized
	int choice1, choice2, choice;
	int currentPlayer;
	int nextPlayer;
	int handPos = 1;


	//to test and see what values proved true
	int passed;
	int passedCount = 0;
	int failureCoin = 0;
	int failureDiscard = 0;
	int failureNext = 0; // to check aginst nxtplayer handCount
	int failureCurrent = 0; //to check against currentP handCount

	//for the random values
	srand(time(NULL));

	int i;
	for (i = 0; i < MAX_RUNS; i++)
	{
		nextPlayer = 1;
		//initalize the game with set values
		initializeGame(numPlayer, k, seed, &G);

		//randomly select choice1 or choice2
		choice = rand() % 2;
		
		//randomly select player
		currentPlayer = rand() % 2;

		//Random selection of next player
		if(currentPlayer == 1)
			nextPlayer = 0;

		//change the spot in the cards where the one selected will be
		handPos = rand() % 5;

		passed = 1;
		// didnot checke both values being on or off. 
		// though it should be in code
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
		
		memcpy(&testG, &G, sizeof(struct gameState));
		caseMinion(&G, choice1, choice2, handPos, currentPlayer);
		
		//set value to test against
		testG.handCount[currentPlayer] = 4;
		testG.handCount[nextPlayer] = 4;

		//check number of coins increase by 2
		if(choice1)
		{
			if((testG.coins + 2) != G.coins)
			{
				printf("Incorrect number of coins added\n");
				failureCoin++;
				passed = 0;
			}
		}

		//changed values to occur becasue
		else if(choice2)
		{
			if(numHandCards(&G) != 4) 
			{
				printf("Incorrect number discarded cards\n");
				failureDiscard++;
				passed = 0;
			}
			if(testG.handCount[currentPlayer] != G.handCount[currentPlayer])
			{	
				printf("Incorrect hand count for current player\n");
				failureCurrent++;
				passed = 0;
			}

			if(testG.handCount[nextPlayer] != G.handCount[nextPlayer])
			{	
				printf("Incorrect hand count for current player\n");
				failureNext++;
				passed = 0;
			}

		}
		if(passed == 1)
		{
			passedCount++;
		}
		
	}

	printf("\n%d Tests Passed!\t", passedCount);
	printf("%d coins count failed, ", failureCoin);
	printf("%d discard count failed, ", failureDiscard);
	printf("%d next player's hand count failed, ", failureNext);
	printf("%d current player's hand count failed!\n", failureCurrent);

	if(passedCount == MAX_RUNS)
		printf("All Tests Pass for Minion Card!!!\n\n");
	else
		printf("There are errors in the code!!!\n\n");


	return 0;
}
												
																	




















