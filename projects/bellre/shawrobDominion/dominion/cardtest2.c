/* SHUFFLE CARD
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

int arrComp(struct gameState *testGZ, struct gameState *G, int player)
{
	int i, counter; //counter to check # of matches

	for( i = 0; i < testGZ->deckCount[player]; i++)
	{
		if(testGZ->deck[player][i] == G->deck[player][i])
			counter++;
	}

	if(counter == testGZ->deckCount[player])
		return 1;
	else
		return 0;
}



int main() {
	int seed  = 1000;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	
	struct gameState testG, G, testGZ;
	initializeGame(numPlayer, k, seed, &G);
#if(NOISY_TEST == 1)		
	printf("-----------Testing function: shuffle() --------------\n");
#endif	
	memcpy(&testG, &G, sizeof(struct gameState));
	
	/************************************************************/
	int currentPlayer = 0;

	//origDeckCount = G.deckCount[currentPlayer];
	int r;
	 r = shuffle(currentPlayer, &testG);

#if(NOISY_TEST == 1)
	printf("return value with cards in deck = %d, expected = 0\n", r);
	testG.deckCount[currentPlayer] = 0; // set to test the count

#endif
	assert(r == 0);
#if(NOISY_TEST == 1)	
	
	r = shuffle(currentPlayer, &testG);
	printf("return value with NO cards in deck = %d, expected = -1\n", r);
#endif
	assert(r == -1);

#if(NOISY_TEST == 1)

	testG.deckCount[currentPlayer] = 5; //reset for next test to work
	testG.discardCount[currentPlayer] = 0;
	r = shuffle(currentPlayer, &testG);
	printf("check the return value with no discard cards = %d, expected = 0\n", r);
	
	int t;
	testG.discardCount[currentPlayer] = 4;
	t = shuffle(currentPlayer, &testG); //should get error?
	printf("check return value with discard cards = %d, expected = -1\n", t);

	memcpy(&testGZ, &G, sizeof(struct gameState));
	int player = 1;

	int t1, r1;
	t1 = shuffle(player, &testGZ);

	printf("check the return value with no discard cards = %d, expected = 0\n", t1);
	//check to see if the values match each other
	r1 = arrComp(&testGZ, &G, player);
	printf("check shuffle of cards = %d, expected = 0", r1);

#endif
	//assert(r == 0);
	//assert(t1 == 0);
	//assert(t == -1);
	//assert(r1 == 0);
	return 0;
}