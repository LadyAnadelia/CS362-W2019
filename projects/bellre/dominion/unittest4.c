/*	TRIBUTE																		
 * Name: Rebecca Bell
 *Part of document came from examples given to us in class 
testUpdateCoins.c and cardtest4.c
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//set to 0 to remove printfs from output
#define NOISY_TEST 1
#define TESTCARD "tribute"

int main() {
	int seed  = 1000;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, tribute, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	struct gameState testG, G;
	initializeGame(numPlayer, k, seed, &G);
#if(NOISY_TEST == 1)		
	printf("-----------Testing card: %s --------------\n", TESTCARD);
#endif	
	memcpy(&testG, &G, sizeof(struct gameState));
	
	/************************************************************/
	int currentPlayer = 0;
	int nextPlayer = 1;
	//this section was designed to test the first if statement
	//to run through first if statement

#if(NOISY_TEST == 1)
	int test1, i;
	// to go through the second if statment
	int discardCT, deckCT;
	testG.deckCount[nextPlayer] = 0;


	//trying to set the tribute reveal cards outside the function	
	testG.deck[nextPlayer][testG.deckCount[nextPlayer]-1] = copper;
	testG.deck[nextPlayer][testG.deckCount[nextPlayer]--] = -1;
	testG.deckCount[nextPlayer]-1;
	testG.deck[nextPlayer][testG.deckCount[nextPlayer]-1] = copper;
	testG.deck[nextPlayer][testG.deckCount[nextPlayer]--] = -1;      	
	testG.deckCount[nextPlayer]-1;
	for(i = 0; i < G.discardCount[nextPlayer]; i++)
	{
		G.deckCount[nextPlayer]+1;
		G.discardCount[nextPlayer]-1;
	}
	shuffle(nextPlayer, &testG);
	
	deckCT = G.deckCount[nextPlayer];
	discardCT = G.discardCount[nextPlayer];

	testG.deck[nextPlayer][testG.deckCount[nextPlayer]-1] = copper;
	testG.deck[nextPlayer][testG.deckCount[nextPlayer]-2] = copper;
	
	// test to make sure the function runs
	test1 = caseTribute(&testG, currentPlayer, nextPlayer);
	printf("Return value of the function = %d, expected 0\n", test1);
	printf("Discard Count = %d, expected = %d\n", testG.discardCount[nextPlayer], discardCT);
	printf("Deck Count = %d, expected = %d\n", testG.deckCount[nextPlayer], deckCT);

	printf("Played card count = %d\n", testG.playedCardCount);
	printf("Values before chang by the cards listed below\n");
	printf("\tCoins = %d, ", G.coins);
	printf("\tAction = %d, ", G.numActions);
	printf("\tHand = %d\n", G.handCount[currentPlayer]);

	printf("Values after change by the cards listed below\n");
        printf("\tCoins = %d, ", testG.coins);
        printf("\tAction = %d, ", testG.numActions);
        printf("\tHand = %d\n", testG.handCount[currentPlayer]);

#endif

	assert(test1 == 0);
	//assert(testG.discardCount[nextPlayer] == discardCT);
	//assert(testG.deckCount[nextPlayer] == deckCT);
	
	//assert(G.coins != testG.coins && G.numActions != testG.numActions && G.handCount[currentPlayer] != testG.handCount[currentPlayer]);


	return 0;
}



















