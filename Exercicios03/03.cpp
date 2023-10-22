#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "03_util.h"
#include <time.h>
#include <string.h>

int main(void){
    srand(time(NULL)); // Initializes the random seed, for each code initialization.
    
    player *jogadores = (player *) malloc(4 * sizeof(player)); // Dynamically allocate the player
    card *cartas = (card *) malloc(20 * sizeof(card));

    read_players(jogadores, cartas);

    show_players(jogadores);
    
    free(jogadores);
    free(cartas);

    return 0;
}
