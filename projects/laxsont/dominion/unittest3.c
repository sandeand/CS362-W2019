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

int getCost(int);

// TESTING SUITE FOR FUNCTION __
// int getCost(int cardNumber);
// We must initialize only the list of cards, which is likely provided in the .h file!

int main(){
  // Setup the game
  int outcome = 0, r;
  struct gameState game;
  int cards[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  r = initializeGame(2, cards, 1, &game);

  // Execute tests
  //outcome += asserttrue(int returning function, correct value);
  outcome += asserttrue(getCost(adventurer), 6, __LINE__);
  outcome += asserttrue(getCost(council_room), 5, __LINE__);
  outcome += asserttrue(getCost(feast), 4, __LINE__);
  outcome += asserttrue(getCost(gardens), 4, __LINE__);
  outcome += asserttrue(getCost(mine), 5, __LINE__);
  outcome += asserttrue(getCost(remodel), 4, __LINE__);
  outcome += asserttrue(getCost(smithy), 4, __LINE__);
  outcome += asserttrue(getCost(village), 3, __LINE__);
  outcome += asserttrue(getCost(baron), 4, __LINE__);
  outcome += asserttrue(getCost(great_hall), 3, __LINE__);


  if(outcome == 0){
    printf("Testing suite successful!\n");
    return 0;
  }
  if(outcome != 0){
    printf("Testing suite unsuccessful! %d errors found!\n", outcome); 
    return 0;
  }
}




