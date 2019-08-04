/*	GET WINNER																	
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


void testFunction(int player, struct gameState *state)
{
	state->hand[player][0] = province;
	state->discard[player][0] = province;
}




int main() {
	int seed  = 1000;
	int size = 2;
	int numPlayer[size];
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	struct gameState testG, G;
	initializeGame(size, k, seed, &G);
#if(NOISY_TEST == 1)		
	printf("-----------Testing card: getWinner() --------------\n");
#endif	
	memcpy(&testG, &G, sizeof(struct gameState));
	
	/************************************************************/

	int r;
#if(NOISY_TEST == 1)
	r = getWinners(numPlayer, &testG);
	printf("Test functions value = %d, expected = 0\n", r);
	printf("Unplayed players = %d, expected = -9999\n", numPlayer[0]);

	int t, z; // used as varibles for the functions end value
	testFunction(0, &testG);
	z = getWinners(numPlayer, &testG);
	printf("Test of winner being player 0, return value %d\n", z);
	testFunction(1, &G);
	t = getWinners(numPlayer, &G);
	printf("Test of winner being player 1, return value %d\n", t);
	int p;

	p = scoreFor(1, &G);
	printf("Test of score expected score > 0 got %d\n", p);
#endif
	//assert(r == 0);
	//assert(-9999 == numPlayer[4]);
	//assert(z == 0); 
	//assert(t == 0);
	//assert(p > 0);

	return 0;

}