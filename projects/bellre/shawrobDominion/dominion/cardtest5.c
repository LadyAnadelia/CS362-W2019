/*																		
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

int main() {
	int seed  = 1000;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	struct gameState testG, G;
	initializeGame(numPlayer, k, seed, &G);
#if(NOISY_TEST == 1)		
	printf("-----------Testing function: drawCard() --------------\n");
#endif	
	memcpy(&testG, &G, sizeof(struct gameState));
	
	/************************************************************/
	int currentPlayer = 0;
	int nextPlayer = 1;
	int handCT, deckCT;
	int r, t;
#if(NOISY_TEST == 1)
	//check that thehand count goes up and deck count goes down.	
	deckCT = G.deckCount[currentPlayer] - 1;
	handCT = G.handCount[currentPlayer] + 1;
								
	r = drawCard(currentPlayer, &testG);
	printf("Testing return value = %d, expected = 0\n", r);

	printf("Testing deck Count = %d, expected %d\n", testG.deckCount[currentPlayer], deckCT);
	printf("Testing hand Count = %d, expected %d\n", testG.handCount[currentPlayer], handCT);
	
	//check to make cure other player did not change value

	printf("Testing next Players deckCount = %d, expected %d\n", testG.deckCount[nextPlayer], G.deckCount[nextPlayer]);
	printf("Testing next Players handCount = %d, expected %d\n", testG.handCount[nextPlayer], G.handCount[nextPlayer]);
#endif
	//assert(r == 0);
	//assert(testG.deckCount[currentPlayer] == deckCT);	
	//assert(testG.handCount[currentPlayer] == handCT);
	//assert(testG.deckCount[nextPlayer] == G.deckCount[nextPlayer]);
	//assert(testG.handCount[nextPlayer] == G.handCount[nextPlayer]);

#if(NOISY_TEST == 1)
	testG.deckCount[currentPlayer] = -1; //set deckCount to -1 to get if statemement
	r = drawCard(currentPlayer, &testG);
	//run function and see what the current discardCardCount is
	printf("Testing new deckCount = %d, expected %d\n", testG.deckCount[currentPlayer], testG.discardCount[currentPlayer]);
	
	//change the discard count and get a return value of r in function
	testG.discardCount[currentPlayer] = 0;	
	t = drawCard(currentPlayer, &testG);
	printf("Testing return value with no discard card = %d, expected = -1\n", t);

	printf("Testing deck Count = %d, expected %d\n", testG.deckCount[currentPlayer], deckCT);
        printf("Testing hand Count = %d, expected %d\n", testG.handCount[currentPlayer], handCT);

	printf("Testing next Players deckCount = %d, expected %d\n", testG.deckCount[nextPlayer], G.deckCount[nextPlayer]);
	printf("Testing next Players handCount = %d, expected %d\n", testG.handCount[nextPlayer], G.handCount[nextPlayer]);

#endif
	
	//assert(r == 0);
	//assert(t == -1);
	//assert(testG.deckCount[currentPlayer] == deckCT);	
	//assert(testG.handCount[currentPlayer] == handCT);
	//assert(testG.deckCount[nextPlayer] == G.deckCount[nextPlayer]);
	//assert(testG.handCount[nextPlayer] == G.handCount[nextPlayer]);

return 0;
}