/* MINION CARD																		
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
#define TESTCARD "minion"

int main() {
	int seed  = 1000;
	int numPlayer = 2;
	int k[10] = {minion, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	struct gameState testG, G;
	initializeGame(numPlayer, k, seed, &G);
#if(NOISY_TEST == 1)		
	printf("-----------Testing card: %s --------------\n", TESTCARD);
#endif	
	memcpy(&testG, &G, sizeof(struct gameState));
	
	/************************************************************/
	int currentPlayer = 0;
	int nextPlayer = 1;
	int coinCT;
	coinCT = G.coins = G.coins + 2;
	int r, t;
	r = execute_minion(&testG, 1, 0, 1, currentPlayer);
#if(NOISY_TEST == 1)
	printf("Return value = %d, expected = 0\n", r);

	//check to see if the coins increased
	printf("Coin count change with choice1 = %d, expected = %d\n", testG.coins, coinCT);
		//checked to see the number of cards in hand
	printf("count of discard cards = %d, expected = 4\n", numHandCards(&testG));
#endif					
	//assert(r == 0);
	//assset(testG.coins ==coinCT);
	//assert(numHandCards(&testG) == 4))
#if(NOISY_TEST == 1)       	
	//checked to see if all players had 4 cards starting
	printf("CurrentPlayers hand = %d, expected = %d\n", testG.handCount[currentPlayer], G.handCount[currentPlayer]);
 	printf("Next Players hand = %d, expected = %d\n", testG.handCount[nextPlayer], G.handCount[nextPlayer]);
#endif
	//assert(testG.handCount[currentPlayer] == G.handCount[currentPlayer]);
	//assert(testG.handCount[nextPlayer] == G.handCount[nextPlayer]);

#if(NOISY_TEST == 1)
	//checked to see if all players drew 4 cards
	t = execute_minion(&testG, 0, 1, 1, currentPlayer);
	printf("Return value = %d, expected = 0\n", t); 	
	printf("CurrentPlayers hand = %d, expected = 4\n", testG.handCount[currentPlayer]);
 	printf("Next Players hand = %d, expected = 4\n", testG.handCount[nextPlayer]);

#endif

	//assert(testG.handCount[currentPlayer] == G.handCount[currentPlayer]);
	//assert(testG.handCount[nextPlayer] == G.handCount[nextPlayer]);
								
	assert(t == 0);
	return 0;

}
