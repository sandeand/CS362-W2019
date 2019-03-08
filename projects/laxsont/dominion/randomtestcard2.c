#include "dominion.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

void randomize_everything(struct gameState *game, int cards[10], int default_cards[7]){
  game->handCount[0] = rand()%9 + 1;
  game->deckCount[0] = rand()%70;
  game->discardCount[0] = rand()%70;

  //printf("hand_count: %d, deck_count: %d, discard_count: %d\n", game->handCount[0], game->deckCount[0], game->discardCount[0]);
  int card_num;
  int out;

  //Get random hand
  for(int i = 0; i < game->handCount[0]; i++){
    card_num = rand()%17;
    if(card_num <= 9){
      out = cards[card_num];
    }
    else{
      card_num = card_num - 10;
      out = default_cards[card_num];
    }  
    game->hand[0][i] = out;
    //printf("%d, ", game->hand[0][i]); 
  }
  //printf("\n");

  //Get random deck
  for(int i = 0; i < game->deckCount[0]; i++){
    card_num = rand()%17;
    if(card_num <= 9){
      out = cards[card_num];
    }
    else{
      card_num = card_num - 10;
      out = default_cards[card_num];
    }  
    game->deck[0][i] = out;
    //printf("%d, ", game->deck[0][i]); 
  }
  //printf("\n");

  //Get random discard
  for(int i = 0; i < game->discardCount[0]; i++){
    card_num = rand()%17;
    if(card_num <= 9){
      out = cards[card_num];
    }
    else{
      card_num = card_num - 10;
      out = default_cards[card_num];
    }  
    game->discard[0][i] = out;
    //printf("%d, ", game->discard[0][i]); 
  }
  //printf("\n");

  game->numActions = rand()%9 + 1;
  game->whoseTurn = 0;
  game->phase = 0;

} 

int test_village(struct gameState *game){
  int actions = game->numActions;
  int handcnt = game->handCount[0];
  int handPos = rand()%handcnt;

  /*
  printf("Copper: %d, Silver: %d, Gold: %d, adventurer: %d\n", copper, silver, gold, adventurer);

  printf("Old Hand: ");
  for(int i = 0; i < game->handCount[0]; i++){
    printf("%d, ", game->hand[0][i]); 
  }
  printf("\n");
  */
  
  game->hand[0][handPos] = village;
  
  actions = actions + 1;

  int success = playCard(handPos, -1, -1, -1, game);

  int error_count = 0;
  error_count += asserttrue(success, 0, __LINE__);
  error_count += asserttrue(game->numActions, actions, __LINE__);
  error_count += asserttrue(game->handCount[0], handcnt, __LINE__);

  /*
  printf("successful? %d\n", success);

  printf("New Hand: ");
  for(int i = 0; i < game->handCount[0]; i++){
    printf("%d, ", game->hand[0][i]); 
  }
  printf("\n");
  */
  //printf("card1: %d, card2: %d, calc_act: %d, aft_act: %d, calc_cnt: %d, aft_cnt: %d\n", card1, card2, actions, game->numActions, handcnt, game->handCount[0]);
  //printf("error_count - %d\n", error_count);
  return error_count;
}                        

// TESTING SUITE FOR CARD - __

int main(){
  int error_count = 0;
  srand(time(0));
  int num_runs = 10000;

  for(int i = 0; i < num_runs; i++){ //Configure num_runs for the amount of tests you want to do.
    // Setup the game
    struct gameState game;
    int cards[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall};
    int default_cards[7] = {copper, silver, gold, curse, 
                        estate, duchy, province};

    randomize_everything(&game, cards, default_cards);

    error_count += test_village(&game);
  }

  printf("Testing suite complete - %d errors found in %d runs!\n", error_count, num_runs);
}



