/*	MINE																		
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
#define TESTCARD "mine"

int main() {
	int seed  = 1000;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	struct gameState testG, G;
	initializeGame(numPlayer, k, seed, &G);
#if(NOISY_TEST == 1)		
	printf("-----------Testing card: %s --------------\n", TESTCARD);
#endif	
	memcpy(&testG, &G, sizeof(struct gameState));
	
	/************************************************************/
	int choice1, choice2, handPos;
	int currentPlayer = 0;

	int r, r1, r2, r3;
 	choice1 = 1;
	choice2 = -1;
	handPos = 1;
#if(NOISY_TEST == 1)
	//check that choice1 is not a coin
	r = execute_mine(&testG, choice1, choice2, handPos, currentPlayer);
	printf("Set a non-coin return = %d, expected = -1\n", r);
	//check choice2 is not out of range of choices	
	choice1 = copper;
	r1 = execute_mine(&testG, choice1, choice2, handPos, currentPlayer);
	printf("Set bad value for choice2 return = %d, expected = -1\n", r1);

	choice2 = province;

	r2 = execute_mine(&testG, choice1, choice2, handPos, currentPlayer);
	printf("All Correct value = %d, expected = 0\n", r2);

	//to see what the cost of the cards are
	int cost1, cost2;

	cost1 = getCost(testG.hand[currentPlayer][choice1] + 3);
	cost2 = getCost(choice2);
										
	printf("Cant afford: cost 1 = %d < cost 2 = %d\n", cost1, cost2);
	r3 = execute_mine(&testG, choice1, choice2, handPos, currentPlayer);
	printf("Return value = %d, expected = -1\n", r3);
#endif
	//assert( cost1 < cost2);
	//assert(r3 == -1);


#if(NOISY_TEST == 1)
			
	choice2 = silver;	
	//should not be able to afford these cards
	cost1 = getCost(testG.hand[currentPlayer][choice1] + 3);
	cost2 = getCost(choice2);
	
	printf("Can Afford: cost 1 = %d > cost 2 = %d\n", cost1, cost2);
	r3 = execute_mine(&testG, choice1, choice2, handPos, currentPlayer);
	printf("Return value = %d, expected = -1\n", r3);                        
	
	int handCT;
	handCT = G.handCount[currentPlayer] - 2;

	printf("hand Count = %d, expected = %d\n", testG.handCount[currentPlayer], handCT);

#endif
	assert(r == -1);
	assert(r1 == -1);
	//assert(r2 == 0);
	//assert( cost1 < cost2);
	//assert(r3 == -1);
	assert(testG.handCount[currentPlayer] == handCT);

	return 0;


}
