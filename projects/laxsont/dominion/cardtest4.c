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

// TESTING SUITE FOR CARD __
// great hall

int main(){
  // Setup the game
  int outcome = 0, r;
  struct gameState game;
  int cards[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  r = initializeGame(2, cards, 1, &game);

  // Execute tests
  //outcome += asserttrue(int returning function, correct value);
  //outcome += asserttrue(numHandCards(&game), 5);
  game.whoseTurn = 0;
  game.handCount[0] = 1;
  game.handCount[1] = 0;
  game.numActions = 1;
  game.hand[0][0] = village; 

  playCard(0, -1, -1, -1, &game);

  outcome += asserttrue(game.handCount[0], 1, __LINE__);
  outcome += asserttrue(game.handCount[1], 0, __LINE__);
  outcome += asserttrue(game.numActions, 2, __LINE__);
   
  game.handCount[0] = 2;
  game.handCount[1] = 0;
  game.numActions = 2;
  game.hand[0][0] = village; 

  playCard(0, -1, -1, -1, &game);

  outcome += asserttrue(game.handCount[0], 2, __LINE__);
  outcome += asserttrue(game.handCount[1], 0, __LINE__);
  outcome += asserttrue(game.numActions, 3, __LINE__);

  if(outcome == 0){
    printf("Testing suite successful!\n");
    return 0;
  }
  if(outcome != 0){
    printf("Testing suite unsuccessful! %d errors found!\n", outcome); 
    return 0;
  }
}




