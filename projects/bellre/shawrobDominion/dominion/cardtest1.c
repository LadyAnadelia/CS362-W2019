/*	INITATTE GAME
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
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int k2[10] = {adventurer, council_room, feast, feast, mine, mine, smithy, village, baron, great_hall};
	
	struct gameState G;
#if(NOISY_TEST == 1)		
	printf("-----------Testing function: initializeGame() --------------\n");
#endif	
	//memcpy(&testG, &G, sizeof(struct gameState));
	
	/************************************************************/


#if(NOISY_TEST == 1)
	int t, a, b, c, d, e, copperCT, numPlayers;
	t = initializeGame(5, k, seed, &G); // test if not enough plys
        printf("return value 5 game players = %d, expected = -1\n", t);

	a = initializeGame(1, k, seed, &G); // test if not enough plys
	printf("return value 1 game player = %d, expected = -1\n", a);
	b = initializeGame(2, k2, seed, &G); // if 2 plys and same type of a card
	printf("return value 2 game player 1 repeated card = %d, expected = -1\n", b);
													
	// game initialize to work with 2 players
	numPlayers = 2;
	c = initializeGame(numPlayers, k, seed, &G); //2 plyrs
	copperCT = 60 - (7 * numPlayers);
	printf("Return value = %d, expected = 0\n", c);
	printf("2 Players: supply curse = %d, expected = 10\n", G.supplyCount[curse]); 
	printf("2 Players: supply estate = %d, expected = 8\n", G.supplyCount[estate]);
	printf("2 Players: supply duchy = %d, expected = 8\n", G.supplyCount[duchy]);
	printf("2 Players: supply province = %d, expected = 8\n", G.supplyCount[province]);
	printf("2 Players: supply copper = %d, expected = %d\n", G.supplyCount[copper], copperCT);
	printf("2 Players: supply silver = %d, expected = 40\n", G.supplyCount[silver]);
	printf("2 Players: supply gold = %d, expected = 30\n", G.supplyCount[gold]);

	memset(&G, 23, sizeof(struct gameState)); // clean the game

													
	// game initialize to work with 3 players
	numPlayers = 3;
	d = initializeGame(numPlayers, k, seed, &G); //3 plyrs
	copperCT = 60 - (7 * numPlayers);
	printf("Return value = %d, expected = 0\n", d);
	printf("3 Players: supply curse = %d, expected = 20\n", G.supplyCount[curse]); 
	printf("3 Players: supply estate = %d, expected = 12\n", G.supplyCount[estate]);
	printf("3 Players: supply duchy = %d, expected = 12\n", G.supplyCount[duchy]);
	printf("3 Players: supply province = %d, expected = 12\n", G.supplyCount[province]);
	printf("3 Players: supply copper = %d, expected = %d\n", G.supplyCount[copper], copperCT);
	printf("3 Players: supply silver = %d, expected = 40\n", G.supplyCount[silver]);
	printf("3 Players: supply gold = %d, expected = 30\n", G.supplyCount[gold]);

	memset(&G, 23, sizeof(struct gameState)); // clean the game
														
 													    
 	// game initialize to work with 4 players
 	numPlayers = 4;
 	e = initializeGame(numPlayers, k, seed, &G); //4 plyrs
 	copperCT = 60 - (7 * numPlayers);
 	printf("Return value = %d, expected = 0\n", e);
 	printf("4 Players: supply curse = %d, expected = 30\n", G.supplyCount[curse]); 
 	printf("4 Players: supply estate = %d, expected = 12\n", G.supplyCount[estate]);
 	printf("4 Players: supply duchy = %d, expected = 12\n", G.supplyCount[duchy]);
 	printf("4 Players: supply province = %d, expected = 12\n", G.supplyCount[province]);
 	printf("4 Players: supply copper = %d, expected = %d\n", G.supplyCount[copper], copperCT);
 	printf("4 Players: supply silver = %d, expected = 40\n", G.supplyCount[silver]);
 	printf("4 Players: supply gold = %d, expected = 30\n", G.supplyCount[gold]);
 
 	memset(&G, 23, sizeof(struct gameState)); // clean the game

#endif

	return 0;
}
