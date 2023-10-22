#include <cstring> 
#include <stdio.h>
#include <stdlib.h>

typedef struct Card {
    int valor;
    int naipe;
} card;

typedef struct Player {
    char nome[20];
    card *cartas; // (card *) malloc(5 * sizeof(card));

} player;

const char *vetor[13] = {
    "Ace of", "Two of", "Three of", "Four of", "Five of", "Six of",
    "Seven of", "Eight of", "Nine of", "Ten of", "Jack of", "Queen of", "King of"
};

int drawn_cards(int valor, int naipe, int matriz[4][13]){
    return matriz[naipe][valor];
}

const char* naipe(card* c){
    switch (c->naipe) {
    case 0:
        return "Hearts";

    case 1:
        return "Spades";

    case 2:
        return "Clubs";

    case 3:
        return "Diamonds";

    default:
        return "Invalid";
    }
}

int matriz[4][13] = {0};

void read_players(player *jogadores, card *cartas){
    for (int i = 0; i < 4; i++){
        printf("Insert the name of player %d: ", i+1);
        fgets(jogadores[i].nome, 20, stdin);
        jogadores[i].nome[strlen(jogadores[i].nome) - 1] = '\0';

        jogadores[i].cartas = cartas + i * 5;

        for (int j = 0; j < 5; j++){
            int naipe, valor;

            do {
                valor = rand() % 13;
                naipe = rand() % 4;

            } while (drawn_cards(valor, naipe, matriz));
            
            matriz[naipe][valor] = 1;

            jogadores[i].cartas[j].valor = valor;
            jogadores[i].cartas[j].naipe = naipe;

        }
    }
}

void show_players(player *jogadores){
    for (int i = 0; i < 4; i++){
        printf("\n[ %s ] - ", jogadores[i].nome);
        for(int j = 0; j < 5; j++) {
            printf("%s ", vetor[jogadores[i].cartas[j].valor]);
            printf("%s ", naipe(&jogadores[i].cartas[j]));
        }
        printf("\n");
    }
}

/*
para cada player 4
[carta -> naipe -- 4, carta -> valor -- 13]

criar uma matriz 4 x 13

            1 2 3 4 5 6 7 8 9 10 11 12 13
[  copas  ] 
[  spadas ]
[  paus   ]
[  ouro   ]
*/
