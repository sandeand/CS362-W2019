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
// int handCard(int handPos, struct gameState *state);
// We must initialize 'state' for the state->hand[currentPlayer][handPos], and provide a handPos value

int main(){
  // Setup the game
  int outcome = 0, r;
  struct gameState game;
  int cards[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  r = initializeGame(2, cards, 1, &game);

  // Execute tests
  //outcome += asserttrue(int returning function, correct value);
  game.handCount[0] = 1;
  game.handCount[1] = 1;
  game.hand[1][0] = 10; //This value is nonsense, and should produce an error if accessed.
  for(int i = 0; i < 10; i++){
    game.hand[0][0] = i;
    outcome += asserttrue(handCard(0, &game), i, __LINE__);
  }

  if(outcome == 0){
    printf("Testing suite successful!\n");
    return 0;
  }
  if(outcome != 0){
    printf("Testing suite unsuccessful! %d errors found!\n", outcome); 
    return 0;
  }
}




