/* 	ENDTURN
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
	
	printf("-----------Testing function: endturn() --------------\n");
#endif	
	memcpy(&testG, &G, sizeof(struct gameState));
	
	/************************************************************/
	//int currentPlayer = 0;

#if(NOISY_TEST == 1)

	int player, firstPlayer; 
	player = firstPlayer = whoseTurn(&testG); // before
	int r;

	r = endTurn(&testG);
	printf("The return value of the function is %d, expected = 0\n", r);

	int nextPlayer;
	nextPlayer = whoseTurn(&testG); // after the function
	printf("Player changed to %d, expected to != %d\n", nextPlayer, player);

	printf("Players hand count changed to %d, expected = 0\n", testG.handCount[player]);

#endif
	assert(nextPlayer != player);
	assert(testG.handCount[player] == 0);
	assert(r == 0);
#if(NOISY_TEST == 1)
	r = endTurn(&testG);
	printf("The return value of the function is %d, expected = 0\n", r);
	nextPlayer = whoseTurn(&testG);
	printf("Player changed to %d, expected to = %d\n", nextPlayer, firstPlayer);
	int handCT;
	handCT = testG.handCount[nextPlayer];
	printf("Players number of cards = %d, expected 0\n", handCT);
	
#endif
	//assert(nextPlayer == firstPlayer); // 2 players in game
	//assert(handCT == 0);
	//assert(r == 0);
	return 0;
}