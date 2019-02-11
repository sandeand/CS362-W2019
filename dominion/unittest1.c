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

// TESTING SUITE FOR FUNCTION 'numHandCards'
// int numHandCards(struct gameState *state);
// We must initialize 'state' for state->handCount 

int main(){
  // Setup the game
  int outcome = 0, r;
  struct gameState game;
  int cards[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  r = initializeGame(2, cards, 1, &game);

  // Execute tests
  for(int i = 0; i < 2; i++){ //cycle through players
    game.whoseTurn = i;
    for(int j = 0; j < 6; j++){ //cycle hand sizes for player 1
      game.handCount[0] = j;
      for(int k = 0; k < 6; k++){ //cycle hand sizes for player 2
        game.handCount[1] = k;
        outcome += asserttrue(numHandCards(&game), game.handCount[i], __LINE__);
      }
    }
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




