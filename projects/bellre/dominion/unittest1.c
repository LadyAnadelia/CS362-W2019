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
#define TESTCARD "baron"

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
	int choice = 1;
	int currentPlayer = 0;
	int buyOrg = G.numBuys;
	int handCT = G.handCount[currentPlayer];
	int coinCT = G.coins;

	int r;
	 r = caseBaron(&testG, choice, currentPlayer);

#if(NOISY_TEST == 1)
	printf("number of Buys = %d, expected = 1\n", buyOrg);
	printf("number of Buys increase = %d, expected = %d\n" , testG.numBuys, buyOrg + 1);
	printf("number of coins in hand = %d, expected = %d\n", testG.coins, coinCT);
	printf("discard card count = %d, expected %d\n", testG.discardCount[currentPlayer], G.discardCount[currentPlayer]+ 1);
	printf("cards in hand = %d expected = %d\n", testG.handCount[currentPlayer], handCT - 1);

#endif
	//assert(buyOrg == 1);
	//assert(testG.numBuys == buyOrg + 1);
	//assert(testG.coins == coinCT);
	//assert(testG.discardCount[currentPlayer] == G.discardCount[currentPlayer]);
	//assert(testG.handCount[currentPlayer], handCT - 1);

	/******************************************************************/
	return 0;
}


