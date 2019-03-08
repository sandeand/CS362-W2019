#include "dominion.h"
#include <stdio.h>

int asserttrue(int a, int b, int line){
  if(a == b){
    //printf("Test Successful for a=%d, b=%d.\n", a, b); 
    return 0;
  }
  else{
    printf("Test Unsuccessful for out=%d, expected=%d.\n\tFound on line %d.\n", a, b, line);
    return 1;
  }
}

// TESTING SUITE FOR FUNCTION __
// int buyCard(int supplyPos, struct gameState *state);
// We must initialize 'supplyPos' as well as 'state' for state->numBuys, whoseTurn, coins, phase,  
// Added note - an output of 0 indicates a SUCCESSFUL transaction, -1 indicates it was NOT successful

int main(){
  // Setup the game
  int outcome = 0, r;
  struct gameState game;
  int cards[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  r = initializeGame(2, cards, 1, &game);

  // Execute tests
  //outcome += asserttrue(int returning function, correct value);
  outcome += asserttrue(buyCard(copper, &game), 0, __LINE__);
  //Test for enough buys
  game.numBuys = 0;
  game.supplyCount[copper] = 30;
  outcome += asserttrue(buyCard(copper, &game), -1, __LINE__);
  game.numBuys = 1;
  outcome += asserttrue(buyCard(copper, &game), 0, __LINE__);
  outcome += asserttrue(game.numBuys, 0, __LINE__);

  //Test for enough supply
  game.numBuys = 1;
  game.supplyCount[copper] = 0;
  outcome += asserttrue(buyCard(copper, &game), -1, __LINE__);
  game.supplyCount[copper] = 30;
  outcome += asserttrue(buyCard(copper, &game), 0, __LINE__);
  outcome += asserttrue(game.numBuys, 0, __LINE__);
  outcome += asserttrue(game.supplyCount[copper], 29, __LINE__);

  //Test for enough money
  game.numBuys = 1;
  game.supplyCount[smithy] = 10;
  game.coins = 0;
  outcome += asserttrue(buyCard(smithy, &game), -1, __LINE__);
  game.coins = 10;
  outcome += asserttrue(buyCard(smithy, &game), 0, __LINE__);
  outcome += asserttrue(game.numBuys, 0, __LINE__);
  outcome += asserttrue(game.supplyCount[smithy], 9, __LINE__);
  outcome += asserttrue(game.coins, 6, __LINE__);

  if(outcome == 0){
    printf("Testing suite successful!\n");
    return 0;
  }
  if(outcome != 0){
    printf("Testing suite unsuccessful! %d errors found!\n", outcome); 
    return 0;
  }
}




