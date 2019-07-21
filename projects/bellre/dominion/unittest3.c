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
#define TESTCARD "ambassador"

int main() {
	int seed  = 1000;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, ambassador, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	struct gameState testG, G;
	initializeGame(numPlayer, k, seed, &G);
#if(NOISY_TEST == 1)		
	printf("-----------Testing card: %s --------------\n", TESTCARD);
#endif	
	memcpy(&testG, &G, sizeof(struct gameState));
	
	/************************************************************/
	int currentPlayer = 0;
	int nextPlayer = 1;
	int r, r1, r2, r3;
#if(NOISY_TEST == 1)
	printf("Next Players card count before = %d, expected = %d\n", testG.deckCount[nextPlayer], G.deckCount[nextPlayer]);
        
#endif
	//assert(testG.deckCount[nextPlayer] == G.deckCount[nextPlayer]);
	r = caseAmbassador(&testG, 1, 1, 0, currentPlayer);
#if(NOISY_TEST == 1)

	//Correct values entered to make function run
	printf("Return value if all values enter correctly = %d, expected = 0\n", r);
	printf("supply count of card = %d, expected %d\n", testG.supplyCount[testG.hand[currentPlayer][1]], G.supplyCount[G.hand[currentPlayer][1] + 1]);
	printf("Next Players card count after = %d, expected = %d\n", testG.deckCount[nextPlayer], G.deckCount[nextPlayer] + 1);
	

#endif
	//assert(r == 0);
	//assert(testG.supplyCount[testG.hand[currentPlayer][1]] == G.supplyCount[G.hand[currentPlayer][1] + 1]);
	//assert(testG.deckCount[nextPlayer] == G.deckCount[nextPlayer + 1]);

#if(NOISY_TEST == 1)
	//if choice2 is less than 0
	r1 = caseAmbassador(&testG, 1, -1, 0, currentPlayer);
	printf("Return value if choice2 < 0 = %d, expected = -1\n", r1);
	//if choice 2 is greater than 2
	r2 = caseAmbassador(&testG, 1, 3, 0, currentPlayer);
	printf("Return value if choice 2 > 2 = %d, expected = -1\n", r2);
	//if the hand position equals choice1
	r3 = caseAmbassador(&testG, 1, 1, 1, currentPlayer);
	printf("Return value if hand pos = choice1 is %d, expected = -1\n", r3);

	testG.handCount[currentPlayer] = -5000;
 	int r4;
	r4 = caseAmbassador(&testG, 1, 0, 1, currentPlayer);
	// test to see if the handCount is less than choice 2 if it will return -1
	printf("Return value if hand count < choice2 is %d, expected = -1\n", r4);

#endif
	//assert(r == 0);
	//assert(r1 == -1);
	//assert(r2 == -1);
	//assert(r3 == -1);
	//assert(r4 == -1);
	return 0;
}






















